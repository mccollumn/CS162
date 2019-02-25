/*
@File:			spaceObject.cpp
@Author:		Nick McCollum
@Version:		1.0
@Description:	SpaceObject class implementation.
				Provides the base functionality for all the things that move across the screen.
*/

#include <cmath>
#include "spaceObject.h"
#include "constants.h"
#include <iostream>

SpaceObject::SpaceObject() {
	type = ASTEROID;
	location = { 0, 0 };
	velocity = { 0, 0 };
	angleDeg = 0;
	radius = 20.0;
}

SpaceObject::SpaceObject(SpaceObjType type, double radius, Point location, Point velocity, double angle) {
	if (type == SHIP || type == ASTEROID || type == PHOTON_TORPEDO) {
		SpaceObject::type = type;
	}
	else {
		SpaceObject::type = ASTEROID;
	}
	if (!setRadius(radius)) {
		SpaceObject::radius = 20.0;
	}
	if (!setLocation(location.x, location.y)) {
		SpaceObject::location = { 0, 0 };
	}
	if (!setVelocity(velocity.x, velocity.y)) {
		SpaceObject::velocity = { 0, 0 };
	}
	if (!setAngle(angle)) {
		SpaceObject::angleDeg = 0;
	}
}

bool SpaceObject::setRadius(int radius) {
	if (radius >= 0 && radius <= SCREEN_HEIGHT / 2) {
		SpaceObject::radius = radius;
		return true;
	}
	return false;
}

bool SpaceObject::setLocation(double x, double y) {
	if (x > SCREEN_WIDTH) {
		SpaceObject::location.x = x - SCREEN_WIDTH;
	}
	else if (x < 0)	{
		SpaceObject::location.x = x + SCREEN_WIDTH;
	}
	else {
		SpaceObject::location.x = x;
	}
	if (y > SCREEN_HEIGHT) {
		SpaceObject::location.y = y - SCREEN_HEIGHT;
	}
	else if (y < 0) {
		SpaceObject::location.y = y + SCREEN_HEIGHT;
	}
	else {
		SpaceObject::location.y = y;
	}
	return true;
}

bool SpaceObject::setVelocity(double velocityX, double velocityY) {
		SpaceObject::velocity.x = velocityX;
		SpaceObject::velocity.y = velocityY;
		return true;
}

bool SpaceObject::setAngle(double angDeg) {
	if (angDeg >= 0 && angDeg <= 360) {
		SpaceObject::angleDeg = angDeg;
		return true;
	}
	return false;
}

void SpaceObject::changeAngle(double deltaDeg) {
	if (type == SHIP) {
		double degree = SpaceObject::angleDeg + deltaDeg;
		int numTimesDivisible = std::abs(degree / 360);
		if (degree < 0) {
			SpaceObject::angleDeg = (degree + (numTimesDivisible * 360)) + 360;
		}
		else {
			SpaceObject::angleDeg = degree - (numTimesDivisible * 360);
		}
	}
}

double SpaceObject::getRadius()	const {
	return SpaceObject::radius;
}

Point SpaceObject::getLocation() const {
	return SpaceObject::location;
}

Point SpaceObject::getVelocity() const {
	return SpaceObject::velocity;
}

double SpaceObject::getAngle() const {
	return SpaceObject::angleDeg;
}

void SpaceObject::updatePosition() {
	Point position;
	position.x = SpaceObject::location.x + SpaceObject::velocity.x;
	position.y = SpaceObject::location.y + SpaceObject::velocity.y;
	SpaceObject::setLocation(position.x, position.y);
}

void SpaceObject::draw(sf::RenderWindow& win) {
	if (type == SHIP)
		drawShip(win);
	else if (type == SHIP_EXPLODING) {
		drawExplodingShip(win);
	}
	else
		drawAsteroid(win);
}

void SpaceObject::applyThrust() {
	if (type == SHIP) {
		double engineThrust = 0.05;
		double forcex = cos((angleDeg - 90)*PI / 180) * engineThrust;
		double forcey = sin((angleDeg - 90)*PI / 180) * engineThrust;
		velocity.x = velocity.x + forcex;
		velocity.y = velocity.y + forcey;
	}
}

void SpaceObject::drawAsteroid(sf::RenderWindow& win) {
	//Configure a graphics object to be used for drawing our object
	//this code draws a simple pentagon.Feel free to modify it if you want.
	int points = 5;
	sf::CircleShape shape(radius, points); //radius from our SpaceObject

	sf::Vector2f midpoint(radius, radius);
	shape.setOrigin(midpoint);

	shape.setFillColor(sf::Color(0, 0, 0));
	shape.setOutlineThickness(1);
	shape.setOutlineColor(sf::Color(255, 255, 255));

	//apply our object position to the graphics object and draw it
	shape.setPosition(location.x, location.y);
	shape.setRotation(angleDeg);

	win.draw(shape);

	if (nearEdge(shape)) {
		win.draw(oppositeShape(shape));
	}
}

void SpaceObject::drawShip(sf::RenderWindow& win) {
	sf::ConvexShape shipShape;
	shipShape.setPointCount(3);
	shipShape.setPoint(0, sf::Vector2f(10, 0));
	shipShape.setPoint(1, sf::Vector2f(0, 25));
	shipShape.setPoint(2, sf::Vector2f(20, 25));

	sf::Vector2f midpoint(10, 15);
	shipShape.setOrigin(midpoint);

	shipShape.setFillColor(sf::Color(0, 0, 0));
	shipShape.setOutlineThickness(1);
	shipShape.setOutlineColor(sf::Color(255, 255, 255));

	shipShape.setPosition(location.x, location.y);
	shipShape.setRotation(angleDeg);
	win.draw(shipShape);
}

bool SpaceObject::nearEdge(const sf::CircleShape& shape) {
	sf::Vector2f currentPosition = shape.getPosition();
	double radius = shape.getRadius();

	if (SCREEN_WIDTH - currentPosition.x < radius) {
		return true;
	}
	else if (currentPosition.x < radius) {
		return true;
	}
	if (currentPosition.y < radius) {
		return true;
	}
	else if (SCREEN_HEIGHT - currentPosition.y < radius) {
		return true;
	}
	return false;
}

sf::CircleShape SpaceObject::oppositeShape(const sf::CircleShape& shape) {
	sf::Vector2f currentPosition = shape.getPosition();
	double radius = shape.getRadius();
	sf::Vector2f oppositePosition = currentPosition;
	sf::CircleShape oppositeShape = shape;

	if (SCREEN_WIDTH - currentPosition.x < radius) {
		oppositePosition.x = -(SCREEN_WIDTH - currentPosition.x);
	}
	else if (currentPosition.x < radius) {
		oppositePosition.x = SCREEN_WIDTH + currentPosition.x;
	}
	if (currentPosition.y < radius) {
		oppositePosition.y = SCREEN_HEIGHT + currentPosition.y;
	}
	else if (SCREEN_HEIGHT - currentPosition.y < radius) {
		oppositePosition.y = -(SCREEN_HEIGHT - currentPosition.y);
	}
	oppositeShape.setPosition(oppositePosition.x, oppositePosition.y);
	return oppositeShape;
}

void SpaceObject::explode() {
	type = SHIP_EXPLODING;
	velocity = { 0, 0 };
}

void SpaceObject::drawExplodingShip(sf::RenderWindow& win) {
	static double explosionSize = radius;
	sf::CircleShape explosion(explosionSize);
	explosion.setFillColor(sf::Color::White);
	explosion.setOrigin(explosionSize, explosionSize);
	explosion.setPosition(location.x, location.y);
	if (explosionSize <= EXPLOSION_RADIUS) {
		win.draw(explosion);
		explosionSize += 0.1;
	}
	else {
		type = SHIP_GONE;
	}
}

// Method testing
//int main() {
//	SpaceObject testObj(ASTEROID, 10, { -125, 0 }, { 500, 1 }, 180);
//	testObj.changeAngle(185);
//
//	testObj.updatePosition();
//
//	return 1;
//}