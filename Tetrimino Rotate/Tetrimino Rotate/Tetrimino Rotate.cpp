/*
@Filename:		Tetrimino Rotate.cpp
@Author:		Nick McCollum
@Date:			1/10/2019
@Version:		1.0
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

typedef int tetriminoArray[NUM_ROWS][NUM_COLS];

enum shapes { I, J, L, O, S, T, Z };

/*
initialize: Sets the initial array values (shape) for each tetrimino.
			Assumes array already initialized to 0s.
@param: int Tetrimino Array, int Shape of tetrimino
@return: none
*/
void initialize(tetriminoArray tetriminoArray, shapes tetrimino);

/*
printTetrimino: Prints the contents of a 2-d tetrimino array to the console window
@param: int Tetrimino Array
@return: none
*/
void printTetrimino(const tetriminoArray tetriminoArray);

/*
rotateLeft: Rotate values in grid 90 degrees left
@param: int Tetrimino Array
@return: none
*/
void rotateLeft(tetriminoArray tetriminoArray);

/*
rotateRight: Rotate values in grid 90 degrees right
@param: int Tetrimino Array
@return: none
*/
void rotateRight(tetriminoArray tetriminoArray);

/*
output: Rotates and prints the tetrimino
@param: int Tetrimino Array, shapes Current Shape, string suffix
@return: none
*/
void output(tetriminoArray tetriminoArray, shapes tetrimino, string suffix);

/*
copyArray2D: Copies the contents of a 2D int array with known size to another array of the same size
@params: int Source Array, int Destination Array
@return: none
*/
void copyArray2D(const int sourceArray[][NUM_COLS], int destArray[][NUM_COLS]);

int main() {

	shapes tetrimino;

	// Tetrimino arrays
	tetriminoArray tetriminoI = {};
	tetriminoArray tetriminoJ = {};
	tetriminoArray tetriminoL = {};
	tetriminoArray tetriminoO = {};
	tetriminoArray tetriminoS = {};
	tetriminoArray tetriminoT = {};
	tetriminoArray tetriminoZ = {};

	// Initialize tetriminos
	initialize(tetriminoI, I);
	initialize(tetriminoJ, J);
	initialize(tetriminoL, L);
	initialize(tetriminoO, O);
	initialize(tetriminoS, S);
	initialize(tetriminoT, T);
	initialize(tetriminoZ, Z);

	// Print tetriminos
	for (tetrimino = I; tetrimino <= Z; tetrimino = static_cast<shapes>(tetrimino + 1)) {
		string suffix = "th";
		switch (tetrimino) {
		case I:
			suffix = "st";
			output(tetriminoI, tetrimino, suffix);
			break;
		case J:
			suffix = "nd";
			output(tetriminoJ, tetrimino, suffix);
			break;
		case L:
			suffix = "rd";
			output(tetriminoL, tetrimino, suffix);
			break;
		case O:
			output(tetriminoO, tetrimino, suffix);
			break;
		case S:
			output(tetriminoS, tetrimino, suffix);
			break;
		case T:
			output(tetriminoT, tetrimino, suffix);
			break;
		case Z:
			output(tetriminoZ, tetrimino, suffix);
			break;
		}
	}

	return 0;
}

// ------------------------------------------------------------
void initialize(tetriminoArray tetriminoArray, shapes tetrimino) {
	int shapeCoords[NUM_SHAPES][NUM_ROWS][NUM_COORDS] = {
		{{1,0},{1,1},{1,2},{1,3}}, // I
		{{1,1},{2,1},{2,2},{2,3}}, // J
		{{1,3},{2,1},{2,2},{2,3}}, // L
		{{1,1},{1,2},{2,1},{2,2}}, // O
		{{1,2},{1,3},{2,1},{2,2}}, // S
		{{1,2},{2,1},{2,2},{2,3}}, // T
		{{1,1},{1,2},{2,2},{2,3}}  // Z
	};
	for (int coord = 0; coord < NUM_ROWS; coord++) {
		tetriminoArray[shapeCoords[tetrimino][coord][0]][shapeCoords[tetrimino][coord][1]] = 1;
	}
}

// ------------------------------------------------------------
void printTetrimino(const tetriminoArray tetriminoArray) {
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			cout << tetriminoArray[row][col];
		}
		cout << endl;
	}
	cout << endl;
}

// ------------------------------------------------------------
void rotateLeft(tetriminoArray tetriminoArray) {
	int tmp[NUM_ROWS][NUM_COLS];
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			tmp[(NUM_COLS - 1) - col][row] = tetriminoArray[row][col];
		}
	}
	copyArray2D(tmp, tetriminoArray);
}

// ------------------------------------------------------------
void rotateRight(tetriminoArray tetriminoArray) {
	int tmp[NUM_ROWS][NUM_COLS];
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			tmp[col][(NUM_ROWS - 1) - row] = tetriminoArray[row][col];
		}
	}
	copyArray2D(tmp, tetriminoArray);
}

// ------------------------------------------------------------
void output(tetriminoArray tetriminoArray, shapes tetrimino, string suffix) {
	cout << "The " << tetrimino + 1 << suffix << " Tetrimino is:\n";
	printTetrimino(tetriminoArray);
	rotateRight(tetriminoArray);
	cout << "The " << tetrimino + 1 << suffix << " Tetrimino rotated 90 degrees to the right is:\n";
	printTetrimino(tetriminoArray);
	rotateLeft(tetriminoArray);
	rotateLeft(tetriminoArray);
	cout << "The " << tetrimino + 1 << suffix << " Tetrimino rotated 90 degrees to the left is:\n";
	printTetrimino(tetriminoArray);
}

// ------------------------------------------------------------
void copyArray2D(const int sourceArray[][NUM_COLS], int destArray[][NUM_COLS]) {
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			destArray[row][col] = sourceArray[row][col];
		}
	}
}