/*
@Filename:		well.h
@Author:		Nick McCollum
@Date:			1/31/2019
@Version:		1.0
@Dev env:		VS 2017
@Description:	Interface to well class.
*/

#pragma once

#include "tetrimino.h"

const int WELL_HEIGHT = 24;
const int WELL_WIDTH = 8;

class Well
{
private:
	char board[WELL_HEIGHT][WELL_WIDTH];
	int height;
	int width;

	/*
	rowIsFull: determines if row is full
	@param: int Row
	@return: bool Is Full
	*/
	bool rowIsFull(int row);

	/*
	moveRowsDown: moves rows down
	@param: int First Row to Move
	@return: none
	*/
	void moveRowsDown(int FirstRowToMove);
public:
	Well();

	/*
	tetriminoFit: Determines if the given Tetrimino will fit in the well at its location
	@param: tetrimino
	@return: bool Success
	*/
	bool tetriminoFit(Tetrimino tetrimino);

	/*
	addTetriminoToWell: Changes the Well’s board squares occupied by the given Tetrimino to it’s color
	@param: tetrimino
	@return: none
	*/
	void addTetriminoToWell(Tetrimino tetrimino);

	/*
	clearFullRows: Finds any rows in the Well that are completely occupied,
				   clears the rows, and drops all rows above the cleared row(s) down one row
	@param: none
	@return: int Num Rows Cleared
	*/
	int clearFullRows();

	/*
	topReached: Returns true if the well’s top row has at least one square occupied
	@param: none
	@return: bool Top Reached
	*/
	bool topReached();

	/*
	getBoard: Returns a copy of the board
	@param: char Board array
	@return: none
	*/
	void getBoard(char board[][WELL_WIDTH]);

	/*
	boardDump: Prints the Well’s board to cout
	@param: none
	return: none
	*/
	void boardDump();
};

