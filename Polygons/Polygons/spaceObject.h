/*
@File:			spaceObject.h
@Author:		Nick McCollum
@Version:		1.0
@Description:	SpaceObject class interface.
*/

#pragma once

#include "SFML/Graphics.hpp"

struct Point {
	double x;
	double y;
};

enum SpaceObjType { SHIP, ASTEROID, PHOTON_TORPEDO };

class SpaceObject {

public:
	SpaceObject();

	/*
	SpaceObject: Constructor
	@param: SpaceObjType Type of Object, double radius, Point location, Point velocity, double angle
	*/
	SpaceObject(SpaceObjType type, double radius, Point location, Point velocity, double angle);

	//=============================================
	//mutators
	bool setRadius(int radius);
	bool setLocation(double x, double y);
	bool setVelocity(double velocityX, double velocityY);
	bool setAngle(double angDeg);

	/*
	changeAngle: change angle by given amount
	@param: double Change in Angle
	@return: none
	*/
	void changeAngle(double deltaDeg);

	//============================================
	//accessors
	double getRadius() const;
	Point getLocation() const;
	Point getVelocity() const;
	double getAngle() const;

	//============================================
	//others
	void updatePosition();

	/*
	draw: Draws the spaceobject on the given window
	@param: win - the window on which we’ll draw the ship
	@return: none
	*/
	void draw(sf::RenderWindow& win);

	void applyThrust();

private:
	SpaceObjType type;	//type of object
	Point location;		//current location (x,y)
	Point velocity;		//current velocity (in pixels/frame)
	double angleDeg;	//angle object is facing (in degrees)
	double radius;		//gross radius of object (for collision detection)

	/*
	drawAsteroid: Draws the spaceobject on the given window as an asteroid
	@param: win - the window on which we’ll draw the ship
	@return: none
	*/
	void drawAsteroid(sf::RenderWindow& win);

	/*
	drawShip: Draws the spaceobject on the given window as a ship
	@param: win - the window on which we’ll draw the ship
	@return: none
	*/
	void drawShip(sf::RenderWindow& win);

	/*
	nearEdge: Checks if the circle shape is within radius of windows edge
	@param: sf::CircleShape Shape to check
	@return: bool Is it near the edge
	*/
	bool nearEdge(const sf::CircleShape& shape);

	/*
	oppositeShape: Generates an identical shape with location on opposite side of window
	@param: sf::CircelShape Shape to duplicate
	@return: sf::CircleShape Opposite shape
	*/
	sf::CircleShape oppositeShape(const sf::CircleShape& shape);
};

