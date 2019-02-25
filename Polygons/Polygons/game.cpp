#include <SFML/Graphics.hpp>
#include "constants.h"
#include "spaceObject.h"
#include <cmath>
#include <iostream>

/*
getRandomLocation: Generates a random location on the screen
@param: none
@return: Point Location
*/
Point getRandomLocation();

/*
getRandomVelocity: Generates a random velocity between -1 and 1
@param: none
@return: Point Velocity
*/
Point getRandomVelocity();

/*
randNum: Generates a random integer between 0 and specified max number
@param: int Max Number
@return: int Random Number
*/
int randNum(int nums);

/*
objectsIntersect: Determines if the two objects overlap
@param: SpaceObject Obect 1, SpaceObject Object 2
@return: bool Do they overlap
*/
bool objectsIntersect(SpaceObject* object1, SpaceObject* object2);

//============================================================================
int main()
{
	//create graphics window
	sf::RenderWindow window(
		sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
		"Polygons!",
		sf::Style::Titlebar | sf::Style::Close
	);
	window.setFramerateLimit(60);

	//create SpaceObjects
//	SpaceObject asteroid(ASTEROID, 20.0, { 50, 50 }, { 0.0, -0.25 }, 180);

	SpaceObject* asteroids[MAX_ASTEROIDS];
	for (int i = 0; i < MAX_ASTEROIDS; i++) {
		asteroids[i] = nullptr;
	}
	SpaceObject* ship = new SpaceObject(SHIP, 1, { 200, 200 }, { 0, 0 }, 0);

	// Create asteroids
	int numAsteroids = 5;
	for (int i = 0; i < numAsteroids; i++) {
		Point location = getRandomLocation();
		Point velocity = getRandomVelocity();
		asteroids[i] = new SpaceObject();
		asteroids[i]->setLocation(location.x, location.y);
		asteroids[i]->setVelocity(velocity.x, velocity.y);
	}


	//game loop
	while (window.isOpen())
	{
		//handle user input (events and keyboard keys being pressed) ----
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			ship->changeAngle(-1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			ship->changeAngle(1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			ship->applyThrust();
		}

		// update game objects ------------------------------------------
//		asteroid.updatePosition();
		for (int i = 0; i < numAsteroids; i++) {
			asteroids[i]->updatePosition();
		}
		ship->updatePosition();

		// Check if ship intersects asteroids
		for (int i = 0; i < numAsteroids; i++) {
			if (objectsIntersect(asteroids[i], ship)) {
				ship->explode();
			}
		}

		// draw new frame ------------------------------------------------
		window.clear();
//		asteroid.draw(window);
		for (int i = 0; i < numAsteroids; i++) {
			asteroids[i]->draw(window);
		}
		ship->draw(window);
		window.display();
	}

	return 0;
}

Point getRandomLocation() {
	Point location;
	location.x = randNum(SCREEN_WIDTH);
	location.y = randNum(SCREEN_HEIGHT);
	return location;
}

Point getRandomVelocity() {
	Point velocity;
	velocity.x = (randNum(200) - 100.0) / 100.0;
	velocity.y = (randNum(200) - 100.0) / 100.0;
	return velocity;
}

int randNum(int nums) {
	static bool firstTime = true;
	if (firstTime) {
		srand(static_cast<unsigned int>(time(NULL)));
//		srand(42);
		firstTime = false;
	}
	return rand() % nums;
}

bool objectsIntersect(SpaceObject* object1, SpaceObject* object2) {
	Point object1Location = object1->getLocation();
	Point object2Location = object2->getLocation();
	double object1Radius = object1->getRadius();
	double object2Radius = object2->getRadius();
	double distance = sqrt(pow(object2Location.x - object1Location.x, 2) + pow(object2Location.y - object1Location.y, 2));
	double totalRadius = object1Radius + object2Radius;
	if (distance < totalRadius) {
		return true;
	}
	return false;
}