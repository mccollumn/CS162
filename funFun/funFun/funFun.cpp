/*
@Filename:		funFun.cpp
@Author:		Nick McCollum
@Date:			11/1/2018
@Version:		1.0
@Dev env:		VS 2017
@Description:	Prompts a user for two integers, then outputs:
					-all the numbers in between, and the average of the numbers
					-a hollow box made of * with dimensions of the entered integers
					-a triangle shape with the height entered
*/

#include <iostream>
#include <iomanip>

using namespace std;

/*
getInteger: Gets an integer value from the user between the low and high value(inclusive).
While the value entered by the user is out of bounds, it prints an error message and gets a new value.
This continues until a valid value is entered, which is then returned.
@param: int (lowest possible value), int (highest possible value)
@return: int (the integer provided by the user)
*/
int getInteger(int low, int high);

/*
printRange: Prints the range of numbers from low to high(inclusive)
@param: int (lowest value), int (highest value)
@return: none
*/
void printRange(int low, int high);

/*
printAvg: Computes and prints the average of the numbers from low to high(inclusive)
@param: int (lowest value), int (highest value)
@return: none
*/
void printAvg(int low, int high);

/*
printBox: Prints a hollow box of * on the screen of the given height and width.
@param: int (height), int (width)
@return: none
*/
void printBox(int height, int width);

/*
printBox: Prints a wedge of * on the screen of the given height, with two * per row.
@param: int (height)
@return: none
*/
void printWedge(int height);

int main() {
	int height, width;

	// Get input
	cout << "Enter a box height(between 3 and 10): ";
	height = getInteger(3, 10);
	cout << "\nEnter a box width between (" << height + 1 << " and 20): ";
	width = getInteger(height + 1, 20);

	// Output the integers in the range
	printRange(height, width);

	// Output the average of the integers in the range
	printAvg(height, width);
	
	// Print a box
	printBox(height, width);

	// Print a triangle
	printWedge(height);

	return 0;
}

int getInteger(int low, int high) {
	int num;

	cin >> num;
	while (num < low || num > high) {
		cout << "That number is out of bounds: Try again: ";
		cin >> num;
	}

	return num;
}

void printRange(int low, int high) {
	cout << "\nThe integers from " << low << " to " << high << " are:\n\t";
	for (int i = low; i <= high; i++) {
		cout << i << " ";
	}
}

void printAvg(int low, int high) {
	double sum = 0;
	int counter = 0;

	for (int i = low; i <= high; i++) {
		cout << i << " ";
		sum += i;
		counter++;
	}
	cout << "\nand the average of those numbers is " << (sum / counter) << "\n\n";
}

void printBox(int height, int width) {
	for (int i = 1; i <= height; i++) {
		if (i == 1 || i == height) {
			cout << "*" << setw(width) << setfill('*') << "*\n";
		}
		else {
			cout << "*" << setw(width) << setfill(' ') << "*\n";
		}
	}
	cout << endl;
}

void printWedge(int height) {
	for (int i = 1; i <= height; i++) {
		for (int x = 1; x <= i * 2; x++) {
			cout << "*";
		}
		cout << "\n";
	}
}