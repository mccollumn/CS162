/*
@Filename:		Tetrimino Rotate.cpp
@Author:		Nick McCollum
@Date:			1/10/2019
@Version:		2.0
@Dev env:		VS 2017
@Description:	Generate seven unique 2-dimensional arrays that represent Tetriminos.
				Rotates the tetriminos left and right, then prints output.
*/

#include <iostream>
#include <string>

using namespace std;

const int NUM_SHAPES = 7;
const int NUM_ROWS = 4;
const int NUM_COLS = 4;
const int NUM_COORDS = 2;

enum shapes { I, J, L, O, S, T, Z };

/*
initialize: Sets the initial array values (shape) for each tetrimino
@param: int Tetrimino Array
@return: none
*/
void initialize(int tetriminoArray[][NUM_ROWS][NUM_COLS]);

/*
output: Rotates and prints the tetrimino
@param: int Tetrimino Array
@return: none
*/
void output(int tetriminoArray[][NUM_ROWS][NUM_COLS]);

/*
printTetrimino: Prints the contents of a 2-d tetrimino array to the console window
@param: int Tetrimino Array, Shape to Print
@return: none
*/
void printTetrimino(const int tetriminoArray[][NUM_ROWS][NUM_COLS], shapes tetrimino);

/*
rotateLeft: Rotate values in grid 90 degrees left
@param: int Tetrimino Array, Shape to Rotate
@return: none
*/
void rotateLeft(int tetriminoArray[][NUM_ROWS][NUM_COLS], shapes tetriminoShape);

/*
rotateRight: Rotate values in grid 90 degrees right
@param: int Tetrimino Array, Shape to Rotate
@return: none
*/
void rotateRight(int tetriminoArray[][NUM_ROWS][NUM_COLS], shapes tetriminoShapes);

/*
copyArray2D: Copies the contents of a 2D int array with known size to another array of the same size
@params: int Source Array, int Destination Array
@return: none
*/
void copyArray2D(int sourceArray[][NUM_COLS], int destArray[][NUM_COLS]);

/*
tetriminoName: Returns a char represnting the shape at the specified index
@params: int Tetrimino index
@return: none
*/
char tetriminoName(int tetrimino);

int main() {

	int tetriminos[NUM_SHAPES][NUM_ROWS][NUM_COLS] = {};

	// Initialize tetriminos
	initialize(tetriminos);

	// Generate output
	output(tetriminos);

	return 0;
}

// ------------------------------------------------------------
void initialize(int tetriminoArray[][NUM_ROWS][NUM_COLS]) {
	shapes tetriminoShape;
	int shapeCoords[NUM_SHAPES][NUM_ROWS][NUM_COORDS] = {
		{{1,0},{1,1},{1,2},{1,3}}, // I
		{{1,1},{2,1},{2,2},{2,3}}, // J
		{{1,3},{2,1},{2,2},{2,3}}, // L
		{{1,1},{1,2},{2,1},{2,2}}, // O
		{{1,2},{1,3},{2,1},{2,2}}, // S
		{{1,2},{2,1},{2,2},{2,3}}, // T
		{{1,1},{1,2},{2,2},{2,3}}  // Z
	};
	for (tetriminoShape = I; tetriminoShape <= Z; tetriminoShape = static_cast<shapes>(tetriminoShape + 1)) {
		for (int coord = 0; coord < NUM_ROWS; coord++) {
			tetriminoArray[tetriminoShape][shapeCoords[tetriminoShape][coord][0]][shapeCoords[tetriminoShape][coord][1]] = 1;
		}
	}
	
}

// ------------------------------------------------------------
void output(int tetriminoArray[][NUM_ROWS][NUM_COLS]) {
	shapes tetriminoShape;
	string suffix[NUM_SHAPES] = { "st", "nd", "rd", "th", "th", "th", "th" };
	for (tetriminoShape = I; tetriminoShape <= Z; tetriminoShape = static_cast<shapes>(tetriminoShape + 1)) {
		char currentShape = tetriminoName(tetriminoShape);
		cout << "The " << tetriminoShape + 1 << suffix[tetriminoShape] << " Tetrimino (" << currentShape << ") is:\n";
		printTetrimino(tetriminoArray, tetriminoShape);
		rotateRight(tetriminoArray, tetriminoShape);
		cout << "The " << tetriminoShape + 1 << suffix[tetriminoShape] << " Tetrimino (" << currentShape << ") rotated 90 degrees to the right is:\n";
		printTetrimino(tetriminoArray, tetriminoShape);
		rotateLeft(tetriminoArray, tetriminoShape);
		rotateLeft(tetriminoArray, tetriminoShape);
		cout << "The " << tetriminoShape + 1 << suffix[tetriminoShape] << " Tetrimino (" << currentShape << ") rotated 90 degrees to the left is:\n";
		printTetrimino(tetriminoArray, tetriminoShape);
	}

}

// ------------------------------------------------------------
void printTetrimino(const int tetriminoArray[][NUM_ROWS][NUM_COLS], shapes tetrimino) {
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			cout << tetriminoArray[tetrimino][row][col];
		}
		cout << endl;
	}
	cout << endl;
}

// ------------------------------------------------------------
void rotateLeft(int tetriminoArray[][NUM_ROWS][NUM_COLS], shapes tetriminoShape) {
	int tmp[NUM_ROWS][NUM_COLS];
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			tmp[(NUM_COLS - 1) - col][row] = tetriminoArray[tetriminoShape][row][col];
		}
	}
	copyArray2D(tmp, tetriminoArray[tetriminoShape]);
}

// ------------------------------------------------------------
void rotateRight(int tetriminoArray[][NUM_ROWS][NUM_COLS], shapes tetriminoShape) {
	int tmp[NUM_ROWS][NUM_COLS];
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			tmp[col][(NUM_ROWS - 1) - row] = tetriminoArray[tetriminoShape][row][col];
		}
	}
	copyArray2D(tmp, tetriminoArray[tetriminoShape]);
}

// ------------------------------------------------------------
void copyArray2D(int sourceArray[][NUM_COLS], int destArray[][NUM_COLS]) {
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			destArray[row][col] = sourceArray[row][col];
		}
	}
}

char tetriminoName(int tetrimino) {
	switch (tetrimino) {
	case 0:
		return 'I';
	case 1:
		return 'J';
	case 2:
		return 'L';
	case 3:
		return 'O';
	case 4:
		return 'S';
	case 5:
		return 'T';
	case 6:
		return 'Z';
	}
}