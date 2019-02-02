/*
@Filename:		tetrimino.cpp
@Author:		Nick McCollum
@Date:			1/25/2019
@Version:		1.0
@Dev env:		VS 2017
@Description:	Class that generates a tetrimino object with methods for manipulating the tetrimino.
*/

#include <ctime>
#include <iostream>
#include "tetrimino.h"

using namespace std;

const int NUM_TETRIMINOS = 7;

Tetrimino::Tetrimino(int type) {
	location = { 0, 0 };

	if (type < 0 || type > 6) {
		type = randType();
	}

	initGrid(type);

	char colors[NUM_TETRIMINOS] = { 't', 'b', 'o', 'y', 'g', 'p', 'r' };
	color = colors[type];
}

void Tetrimino::initGrid(const int type) {
	for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
		for (int col = 0; col < TETRIMINO_GRID_SIZE; col++) {
			grid[row][col] = 0;
		}
	}

	int shapeCoords[NUM_TETRIMINOS][TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE] = {
	{{1,0},{1,1},{1,2},{1,3}}, // I
	{{1,1},{2,1},{2,2},{2,3}}, // J
	{{1,3},{2,1},{2,2},{2,3}}, // L
	{{1,1},{1,2},{2,1},{2,2}}, // O
	{{1,2},{1,3},{2,1},{2,2}}, // S
	{{1,2},{2,1},{2,2},{2,3}}, // T
	{{1,1},{1,2},{2,2},{2,3}}  // Z
	};
	for (int coord = 0; coord < TETRIMINO_GRID_SIZE; coord++) {
		grid[shapeCoords[type][coord][0]][shapeCoords[type][coord][1]] = 1;
	}
}

int Tetrimino::randType() {
	static bool firstTime = true;
	if (firstTime) {
		srand(static_cast<unsigned int>(time(NULL)));
		firstTime = false;
	}
	return rand() % 7;
}

void Tetrimino::copyArray2D(const int sourceArray[][TETRIMINO_GRID_SIZE]) {
	for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
		for (int col = 0; col < TETRIMINO_GRID_SIZE; col++) {
			grid[row][col] = sourceArray[row][col];
		}
	}
}

char Tetrimino::getColor() {
	return color;
}

Location Tetrimino::getLocation() {
	return location;
}

void Tetrimino::getGrid(int gridOut[][TETRIMINO_GRID_SIZE]) {
	for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
		for (int col = 0; col < TETRIMINO_GRID_SIZE; col++) {
			gridOut[row][col] = grid[row][col];
		}
	}
}

void Tetrimino::setLocation(Location newLocation) {
	location = newLocation;
}

void Tetrimino::setLocation(int row, int col) {
	location = { row, col };
}

void Tetrimino::rotateLeft() {
	int tmp[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
	for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
		for (int col = 0; col < TETRIMINO_GRID_SIZE; col++) {
			tmp[(TETRIMINO_GRID_SIZE - 1) - col][row] = grid[row][col];
		}
	}
	copyArray2D(tmp);
}

void Tetrimino::rotateRight() {
	int tmp[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
	for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
		for (int col = 0; col < TETRIMINO_GRID_SIZE; col++) {
			tmp[col][(TETRIMINO_GRID_SIZE - 1) - row] = grid[row][col];
		}
	}
	copyArray2D(tmp);
}

void Tetrimino::moveLeft() {
	location.col--;
}

void Tetrimino::moveRight() {
	location.col++;
}

void Tetrimino::moveDown() {
	location.row++;
}

void Tetrimino::moveUp() {
	location.row--;
}

void Tetrimino::dataDump() {
	cout << "Current location: " << location.row << "," << location.col << endl;
	cout << "Color: " << color << endl;
	printArray(grid);
	cout << endl;
}

void Tetrimino::printArray(int array[][TETRIMINO_GRID_SIZE]) {
	for (int row = 0; row < TETRIMINO_GRID_SIZE; row++) {
		for (int col = 0; col < TETRIMINO_GRID_SIZE; col++) {
			cout << array[row][col];
		}
		cout << endl;
	}
}

// Class method tests
/*
int main() {
	int tetriminoType = 3;
	Location testLocation = { 2, 3 };
	Tetrimino randomTetrimino;
	Tetrimino myTetrimino(tetriminoType);

	cout << "Type " << tetriminoType << " Tetrimino Data Dump\n";
	myTetrimino.dataDump();

	cout << "Random Tetrimino Data Dump\n";
	randomTetrimino.dataDump();

	cout << "Get Color: " << randomTetrimino.getColor() << endl << endl;

	cout << "Get Location: " << randomTetrimino.getLocation().row << "," << randomTetrimino.getLocation().col << endl << endl;

	int gridOutput[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE];
	randomTetrimino.getGrid(gridOutput);
	cout << "Get Grid: \n";
	randomTetrimino.printArray(gridOutput);
	cout << endl;

	randomTetrimino.setLocation(testLocation);
	cout << "Set Location (using location variable) Data Dump\n";
	randomTetrimino.dataDump();

	randomTetrimino.setLocation(testLocation.row, testLocation.col);
	cout << "Set Location (using separate int variables) Data Dump\n";
	randomTetrimino.dataDump();

	randomTetrimino.rotateLeft();
	cout << "Rotate Left Data Dump\n";
	randomTetrimino.dataDump();

	randomTetrimino.rotateRight();
	cout << "Rotate Right Data Dump\n";
	randomTetrimino.dataDump();

	randomTetrimino.moveLeft();
	cout << "Move Left Data Dump\n";
	randomTetrimino.dataDump();

	randomTetrimino.moveRight();
	cout << "Move Right Data Dump\n";
	randomTetrimino.dataDump();

	randomTetrimino.moveDown();
	cout << "Move Down Data Dump\n";
	randomTetrimino.dataDump();

	randomTetrimino.moveUp();
	cout << "Move Up Data Dump\n";
	randomTetrimino.dataDump();

	return 1;
}
*/