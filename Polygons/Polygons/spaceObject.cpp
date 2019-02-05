/*
@File:			spaceObject.cpp
@Author:		Nick McCollum
@Version:		1.0
@Description:	SpaceObject class implementation.
				Provides the base functionality for all the things that move across the screen.
*/

#include <cmath>
#include "spaceObject.h"

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
	if (velocityX >= 0 && velocityY >= 0) {
		SpaceObject::velocity.x = velocityX;
		SpaceObject::velocity.y = velocityY;
		return true;
	}
	return false;
}

bool SpaceObject::setAngle(double angDeg) {
	if (angDeg >= 0 && angDeg <= 360) {
		SpaceObject::angleDeg = angDeg;
		return true;
	}
	return false;
}

void SpaceObject::changeAngle(double deltaDeg) {
	double degree = SpaceObject::angleDeg + deltaDeg;
	int numTimesDivisible = std::abs(degree / 360);
	if (degree < 0) {
		SpaceObject::angleDeg = (degree + (numTimesDivisible * 360)) + 360;
	}
	else {
		SpaceObject::angleDeg = degree - (numTimesDivisible * 360);
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

// Method testing
int main() {
	SpaceObject testObj(ASTEROID, 10, { -125, 0 }, { 500, 1 }, 180);
	testObj.changeAngle(185);

	testObj.updatePosition();

	double degree = 365;
	int numTimesDivisible = degree / 360; // This works: equals 1 when degree is 365
	int newDegree = (degree / 360) * 360; // This does not work: equals 365 when degree is 365?
	int newDegree2 = (static_cast<int> (degree) / 360) * 360; // This works
	int newDegreeCombined = numTimesDivisible * 360; // This works

	return 1;
}