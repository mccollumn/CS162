#pragma once

#include "well.h"
#include "tetrimino.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>

const int LAYOUT_WINDOW_WIDTH = 400;
const int LAYOUT_WINDOW_HEIGHT = 500;
const int LAYOUT_BOARD_TOP = 10;
const int LAYOUT_BOARD_LEFT = 200;
const int BLOCK_SIZE_PIXELS = 20;

class Game
{
private:
	sf::RenderWindow window;
	Well gameWell;
	Tetrimino tetriminoInPlay;

	/*
	convertToSfmlColor: Converts a character representing the Tetrimino color into a SFML color value
	@param: char Tetrimino color
	@return: sf::Color
	*/
	sf::Color convertToSfmlColor(char color);

	/*
	drawWell: Draws a well object in the SFML window
	@param: Well gameWell, int pixels from top, int pixels from left, int pixel width of block
	@return: none
	*/
	void drawWell(Well gameWell, int top, int left, int blockWidth, sf::RectangleShape block, sf::RectangleShape well);

	/*
	drawTetrimino: Draws a tetrimino objec
	@param: Tetrimino, int pixels from top, int pixels from left, int pixel width of block
	@return: none
	*/
	void drawTetrimino(Tetrimino tetrimino, int top, int left, int blockWidth, sf::RectangleShape block);

public:
	Game();

	/*
	playGame: Polls for events and draws game well and tetrimino
	@param: none
	@return: none
	*/
	void playGame();
};

