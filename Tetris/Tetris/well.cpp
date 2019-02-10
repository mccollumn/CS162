/*
@Filename:		well.cpp
@Author:		Nick McCollum
@Date:			1/31/2019
@Version:		1.0
@Dev env:		VS 2017
@Description:	Class that defines a Tetris well.
*/

#include <iostream>
#include "Well.h"

using namespace std;

Well::Well() {
	for (int height = 0; height < WELL_HEIGHT; height++) {
		for (int width = 0; width < WELL_WIDTH; width++) {
			board[height][width] = ' ';
		}
	}
	height = WELL_HEIGHT;
	width = WELL_WIDTH;
}

bool Well::tetriminoFit(Tetrimino tetrimino) {
	Location location = tetrimino.getLocation();
	int grid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
	tetrimino.getGrid(grid);

	for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
		for (int col = 0; col < TETRIMINO_GRID_SIZE; col++) {
			if (grid[row][col] == 1) {
				int boardRow = row + location.row;
				int boardCol = col + location.col;
				if ((boardRow >= 0 && board[boardRow][boardCol] != ' ') || boardRow > height || boardCol < 0 || boardCol > width - 1) {
					return false;
				}
			}
		}
	}
	return true;
}

void Well::addTetriminoToWell(Tetrimino tetrimino) {
	if (tetriminoFit(tetrimino)) {
		Location location = tetrimino.getLocation();
		int grid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
		tetrimino.getGrid(grid);

		for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
			for (int col = 0; col < TETRIMINO_GRID_SIZE; col++) {
				if (grid[row][col] == 1) {
					int boardRow = row + location.row;
					int boardCol = col + location.col;
					if (boardRow >= 0) {
						board[boardRow][boardCol] = tetrimino.getColor();
					}
				}
			}
		}
	}
}

int Well::clearFullRows() {
	int numRowsCleared = 0;
	for (int row = 0; row < height; row++) {
		if (rowIsFull(row)) {
			moveRowsDown(row - 1);
			numRowsCleared++;
		}
	}
	return numRowsCleared;
}

bool Well::topReached() {
	for (int col = 0; col < width; col++) {
		if (board[0][col] != ' ') {
			return true;
		}
	}
	return false;
}

void Well::getBoard(char well[][WELL_WIDTH]) {
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			well[row][col] = board[row][col];
		}
	}
}

void Well::boardDump() {
	for (int row = 0; row < height; row++) {
		cout << "|";
		for (int col = 0; col < width; col++) {
			cout << board[row][col];
		}
		cout << "|" << endl;
	}
	for (int col = 0; col < width + 2; col++) {
		cout << "-";
	}
	cout << endl;
}

bool Well::rowIsFull(int row) {
	for (int col = 0; col < width; col++) {
		if (board[row][col] == ' ') {
			return false;
		}
	}
	return true;
}

void Well::moveRowsDown(int FirstRowToMove) {
	for (int row = FirstRowToMove; row >= 0; row--) {
		for (int col = 0; col < width; col++) {
			board[row + 1][col] = board[row][col];
		}
	}
	for (int col = 0; col < width; col++) {
		board[0][col] = ' ';
	}
}

// Test class methods
//int main() {
//	Well testWell;
//	Tetrimino testTetrimino(3);
//
//	testTetrimino.setLocation(0, 0);
//	Location location = testTetrimino.getLocation();
//	testWell.tetriminoFit(testTetrimino);
//
//	testWell.addTetriminoToWell(testTetrimino);
//	cout << "Placed a square tetrimino at location: " << location.row << ", " << location.col << endl;
//	testWell.boardDump();
//
//	Tetrimino secondTetrimino(1);
//	secondTetrimino.setLocation(0, 0);
//	testWell.addTetriminoToWell(secondTetrimino);
//	cout << "Place another tetrimino on top of the existing one.\n";
//	cout << "It should fail and leave the board unmodified.\n";
//	testWell.boardDump();
//
//	secondTetrimino.setLocation(0, 4);
//	testWell.addTetriminoToWell(secondTetrimino);
//	cout << "Place another tetrimino next to the first.\n";
//	testWell.boardDump();
//
//	secondTetrimino.setLocation(0, 5);
//	testWell.addTetriminoToWell(secondTetrimino);
//	cout << "Attempt to add a tetrimino one square out of bounds to the right.\n";
//	cout << "It should fail and leave the board unmodified.\n";
//	testWell.boardDump();
//
//	secondTetrimino.setLocation(-2, 4);
//	testWell.addTetriminoToWell(secondTetrimino);
//	cout << "Place a tetrimino at the top of the board with part if it above the board.\n";
//	cout << "It should place the piece but part will not be visible.\n";
//	testWell.boardDump();
//
//	testTetrimino.setLocation(-10, 0);
//	testWell.addTetriminoToWell(testTetrimino);
//	cout << "Place a tetrimino way above the board.\n";
//	cout << "It should leave the board unmodified.\n";
//	testWell.boardDump();
//
//	testTetrimino.setLocation(22, 0);
//	testWell.addTetriminoToWell(testTetrimino);
//	cout << "Place a tetrimino one square out of bounds below the board.\n";
//	cout << "It should fail and leave the board unmodified.\n";
//	testWell.boardDump();
//
//	cout << "Top reached? " << testWell.topReached() << endl;
//
//	testTetrimino.setLocation(21, -1);
//	testWell.addTetriminoToWell(testTetrimino);
//	testTetrimino.setLocation(21, 1);
//	testWell.addTetriminoToWell(testTetrimino);
//	testTetrimino.setLocation(21, 3);
//	testWell.addTetriminoToWell(testTetrimino);
//	testTetrimino.setLocation(21, 5);
//	testWell.addTetriminoToWell(testTetrimino);
//	cout << "Fill the bottom of the board with square tetriminos\n";
//	testWell.boardDump();
//	
//	int rowsCleared = testWell.clearFullRows();
//	cout << "Clear " << rowsCleared << " full rows.\n";
//	testWell.boardDump();
//
//	cout << "Top reached? " << testWell.topReached() << endl;
//
//	char boardArr[WELL_HEIGHT][WELL_WIDTH];
//	testWell.getBoard(boardArr);
//
//	return 1;
//}