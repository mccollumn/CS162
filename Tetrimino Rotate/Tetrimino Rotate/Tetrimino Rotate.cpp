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

/*
initialize: Sets the initial array values (shape) for each tetrimino
@param: int Tetrimino Array, int Shape of tetrimino
@return: none
*/
void initialize(int tetriminoArray[][NUM_COLS], int shape);

/*
printTetrimino: Prints the contents of a 2-d tetrimino array to the console window
@param: int Tetrimino Array
@return: none
*/
void printTetrimino(const int tetriminoArray[][NUM_COLS]);

/*
rotateLeft: Rotate values in grid 90 degrees left
@param: int Tetrimino Array
@return: none
*/
void rotateLeft(int tetriminoArray[][NUM_COLS]);

/*
rotateRight: Rotate values in grid 90 degrees right
@param: int Tetrimino Array
@return: none
*/
void rotateRight(int tetriminoArray[][NUM_COLS]);

/*
output: Rotates and prints the tetrimino
@param: int Tetrimino Array, shapes Current Shape, string suffix
@return: none
*/
void output(int tetriminoArray[][NUM_COLS], int tetrimino, string suffix);

/*
copyArray2D: Copies the contents of a 2D int array with known size to another array of the same size
@params: int Source Array, int Destination Array
@return: none
*/
void copyArray2D(int sourceArray[][NUM_COLS], int destArray[][NUM_COLS]);

int main() {

	// Tetrimino arrays
	int tetriminoI[NUM_ROWS][NUM_COLS] = {};
	int tetriminoJ[NUM_ROWS][NUM_COLS] = {};
	int tetriminoL[NUM_ROWS][NUM_COLS] = {};
	int tetriminoO[NUM_ROWS][NUM_COLS] = {};
	int tetriminoS[NUM_ROWS][NUM_COLS] = {};
	int tetriminoT[NUM_ROWS][NUM_COLS] = {};
	int tetriminoZ[NUM_ROWS][NUM_COLS] = {};

	// Shapes
	enum shapes { I, J, L, O, S, T, Z };

	// Initialize tetriminos
	initialize(tetriminoI, I);
	initialize(tetriminoJ, J);
	initialize(tetriminoL, L);
	initialize(tetriminoO, O);
	initialize(tetriminoS, S);
	initialize(tetriminoT, T);
	initialize(tetriminoZ, Z);
	
	// Print tetriminos
	for (int tetrimino = I; tetrimino <= Z; tetrimino++) {
		string suffix = "th";
		switch (tetrimino) {
		case 0:
			suffix = "st";
			output(tetriminoI, tetrimino + 1, suffix);
			break;
		case 1:
			suffix = "nd";
			output(tetriminoJ, tetrimino + 1, suffix);
			break;
		case 2:
			suffix = "rd";
			output(tetriminoL, tetrimino + 1, suffix);
			break;
		case 3:
			output(tetriminoO, tetrimino + 1, suffix);
			break;
		case 4:
			output(tetriminoS, tetrimino + 1, suffix);
			break;
		case 5:
			output(tetriminoT, tetrimino + 1, suffix);
			break;
		case 6:
			output(tetriminoZ, tetrimino + 1, suffix);
			break;
		}
	}

	return 0;
}

// ------------------------------------------------------------
void initialize(int tetriminoArray[][NUM_COLS], int shape) {
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
		tetriminoArray[shapeCoords[shape][coord][0]][shapeCoords[shape][coord][1]] = 1;
	}
}

// ------------------------------------------------------------
void printTetrimino(const int tetriminoArray[][NUM_COLS]) {
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			cout << tetriminoArray[row][col];
		}
		cout << endl;
	}
	cout << endl;
}

// ------------------------------------------------------------
void rotateLeft(int tetriminoArray[][NUM_COLS]) {
	int tmp[NUM_ROWS][NUM_COLS];
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			tmp[(NUM_COLS - 1) - col][row] = tetriminoArray[row][col];
		}
	}
	copyArray2D(tmp, tetriminoArray);
}

// ------------------------------------------------------------
void rotateRight(int tetriminoArray[][NUM_COLS]) {
	int tmp[NUM_ROWS][NUM_COLS];
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			tmp[col][(NUM_ROWS - 1) - row] = tetriminoArray[row][col];
		}
	}
	copyArray2D(tmp, tetriminoArray);
}

// ------------------------------------------------------------
void output(int tetriminoArray[][NUM_COLS], int tetrimino, string suffix) {
	cout << "The " << tetrimino << suffix << " Tetrimino is:\n";
	printTetrimino(tetriminoArray);
	rotateRight(tetriminoArray);
	cout << "The " << tetrimino << suffix << " Tetrimino rotated 90 degrees to the right is:\n";
	printTetrimino(tetriminoArray);
	rotateLeft(tetriminoArray);
	rotateLeft(tetriminoArray);
	cout << "The " << tetrimino << suffix << " Tetrimino rotated 90 degrees to the left is:\n";
	printTetrimino(tetriminoArray);
}

// ------------------------------------------------------------
void copyArray2D(int sourceArray[][NUM_COLS], int destArray[][NUM_COLS]) {
	for (int row = 0; row < NUM_ROWS; row++) {
		for (int col = 0; col < NUM_COLS; col++) {
			destArray[row][col] = sourceArray[row][col];
		}
	}
}