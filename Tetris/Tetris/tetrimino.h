/*
@Filename:		tetrimino.h
@Author:		Nick McCollum
@Date:			1/25/2019
@Version:		1.0
@Dev env:		VS 2017
@Description:	Interface to tetrimino class.
*/

#ifndef TETRIS_TETRIMINO
#define TETRIS_TETRIMINO

const int TETRIMINO_GRID_SIZE = 4;

struct Location {
	int row;
	int col;
};

class Tetrimino {
private:
	int grid[TETRIMINO_GRID_SIZE][TETRIMINO_GRID_SIZE]; //contains only zeros and ones 
	int tetriminoType;
	char color;
	Location location;

	/*
	initGrid: Sets the initial array values (shape) for each tetrimino.
	@param: int Shape of tetrimino
	@return: none
	*/
	void initGrid(const int type);

	/*
	randType: Generates a random tetrimino type (0 - 6)
	@param: none
	@return: int tetrimino type
	*/
	int randType();

	/*
	copyArray2D: Copies the contents of a 2D int array with known size to another array of the same size
	@params: int Source Array
	@return: none
	*/
	void copyArray2D(const int sourceArray[][TETRIMINO_GRID_SIZE]);

public:
	// constructor
	// Initialize grid, color, and location
	// The ‘type’ parameter will determine which piece we initialize grid to
	Tetrimino(int type = 7); // valid type values are 0-6

	//---------------------------------------------
	//accessors
	char getColor(); // returns the color of the tetrimino object
	Location getLocation(); // return the location of the Tetrimino
	void getGrid(int gridOut[][TETRIMINO_GRID_SIZE]);  // return the grid of the Tetrimino 
	int getType();	// return the type of the Tetrimino

	//---------------------------------------------
	//mutators
	void setLocation(Location newLocation); // modify location.row and location.col
	void setLocation(int row, int col); // modify location.row and location.col
	void rotateLeft();
	void rotateRight();
	void moveLeft();
	void moveRight();
	void moveDown();
	void moveUp();

	//---------------------------------------------
	//others
	void dataDump(); // print out the value of grid, color, and location

	/*
	printArray: prints the tetrimino array to std output
	@params: int Array
	@return: none
	*/
	void printArray(int array[][TETRIMINO_GRID_SIZE]);
};
#endif