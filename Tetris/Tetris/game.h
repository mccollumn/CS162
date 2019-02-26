/*
@Filename:		game.h
@Author:		Nick McCollum
@Date:			2/24/2019
@Version:		2.0
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
const int LAYOUT_NEXT_TOP = 10;
const int LAYOUT_NEXT_LEFT = 50;
const int LAYOUT_NEXT_WIDTH = 100;
const int LAYOUT_NEXT_HEIGHT = 100;
const int LAYOUT_NEXT_TITLE_HEIGHT = 25;
const int LAYOUT_SCORE_TOP = 200;
const int LAYOUT_SCORE_LEFT = 50;
const int LAYOUT_SCORE_WIDTH = 100;
const int LAYOUT_SCORE_HEIGHT = 50;
const int LAYOUT_PAUSE_WIDTH = 200;
const int LAYOUT_PAUSE_HEIGHT = 200;
const int BLOCK_SIZE_PIXELS = 20;
const int TETRIS_MULTIPLIER = 2;
const Location TETRIMINO_START_LOCATION = { -2, 2 };
const int TETRIMINO_DROP_RATE = 240;
const int ROWS_PER_LEVEL = 1;				// Set low for demo purposes. Should probably be more like 10.
const float DROP_RATE_PER_LEVEL = 0.5;		// Set high for demo purposes. You probably don't actually want it 50% faster each level.
const float MUSIC_RATE_PER_LEVEL = 0.1;

enum GameState { TETRIS_SPLASH, TETRIS_PLAY, TETRIS_GAME_OVER };

struct Dimensions {
	int width;
	int height;
};

class Game
{
private:
	sf::RenderWindow window;
	sf::Font font;
	sf::Texture backgroundImage;
	sf::Sprite background;
	sf::Music music;
	sf::RectangleShape tetriminoBlock;
	int score;
	int level;
	float currentDropRate;
	float currentMusicPitch;
	Well* gameWell;
	Tetrimino* tetriminoInPlay;
	Tetrimino* tetriminoNext;

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
	getTetriminoCenter: Determines the center point of the tetrimino on the grid
	@param: Tetrimino pointer, int Tetrimino Block Width
	@return: Location Center Point
	*/
	Location getTetriminoCenter(Tetrimino* tetrimino, int blockWidth);

	/*
	getTetriminoDimensions: Determines the tetrimino dimensions in pixels
	@param: Tetrimino pointer, int Tetrimino Block Width
	@return: Dimensions Width and Height
	*/
	Dimensions getTetriminoDimensions(Tetrimino* tetrimino, int blockWidth);

	/*
	updateLevel: Checks the rows cleared and increases the game level if necessary
	@param: int Rows Cleared
	@return: none
	*/
	void updateLevel(int rowsCleared);

	/*
	processSplash: Displays a splash screen
	@param: none
	@return: none
	*/
	void processSplash();

	/*
	processGame: Polls for game events and draws game well and tetrimino
	@param: none
	@return: none
	*/
	void processGame();

	/*
	processGameOver: Displays a game over screen
	@param: none
	@return: bool Play Again
	*/
	bool processGameOver();

	/*
	drawWell: Draws a well object in the SFML window
	@param: Well Pointer gameWell, int pixels from top, int pixels from left, int pixel width of block
	@return: none
	*/
	void drawWell(Well* gameWell, int top, int left, int blockWidth, sf::RectangleShape& block, sf::RectangleShape& well);

	/*
	drawTetrimino: Draws a tetrimino object
	@param: Tetrimino Pointer, int pixels from top, int pixels from left, int pixel width of block
	@return: none
	*/
	void drawTetrimino(Tetrimino* tetrimino, int top, int left, int blockWidth, sf::RectangleShape& block);

	/*
	drawScore: Displays the score
	@param: int Score, int Position Top, int Position Left
	@return: none
	*/
	void drawScore(int score, int top, int left);
	
	/*
	drawNext: Display for the next tetrimino
	@param: Tetrinimo Pointer, int pixels from top, int pixels from left
	@return: none
	*/
	void drawNext(Tetrimino* tetrimino, int top, int left);

	/*
	drawPause: Display for the pause box
	@param: none
	@return: none
	*/
	void drawPause();

public:
	Game();

	~Game();

	/*
	playGame: Polls for events and draws game well and tetrimino
	@param: none
	@return: none
	*/
	void playGame();
};

