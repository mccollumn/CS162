#include <SFML/Graphics.hpp>
#include "constants.h"
#include "spaceObject.h"

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
	SpaceObject asteroid(ASTEROID, 20.0, { 50, 50 }, { 0.0, -0.25 }, 180);
	SpaceObject ship(SHIP, 1, { 200, 200 }, { 0, 0 }, 0);

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
			ship.changeAngle(-1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			ship.changeAngle(1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			ship.applyThrust();
		}

		// update game objects ------------------------------------------
		asteroid.updatePosition();
		ship.updatePosition();

		// draw new frame ------------------------------------------------
		window.clear();
		asteroid.draw(window);
		ship.draw(window);
		window.display();
	}

	return 0;
}