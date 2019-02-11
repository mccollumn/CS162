/*
@Filename:		game.h
@Author:		Nick McCollum
@Date:			2/11/2019
@Version:		1.0
@Dev env:		VS 2017
@Description:	Interface for game class.
*/

#pragma once

#include "well.h"
#include "tetrimino.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <string>
#include <iostream>

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
	printError: Prints error meassge to std output
	@param: string name of file that didn't load
	@return: none
	*/
	void printError(std::string filename);

	/*
	drawWell: Draws a well object in the SFML window
	@param: Well gameWell, int pixels from top, int pixels from left, int pixel width of block
	@return: none
	*/
	void drawWell(Well gameWell, int top, int left, int blockWidth, sf::RectangleShape& block, sf::RectangleShape& well);

	/*
	drawTetrimino: Draws a tetrimino objec
	@param: Tetrimino, int pixels from top, int pixels from left, int pixel width of block
	@return: none
	*/
	void drawTetrimino(Tetrimino tetrimino, int top, int left, int blockWidth, sf::RectangleShape& block);

public:
	Game();

	/*
	playGame: Polls for events and draws game well and tetrimino
	@param: none
	@return: none
	*/
	void playGame();
};

