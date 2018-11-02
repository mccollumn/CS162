/*
@Filename:		LoopFun.cpp
@Author:		Nick McCollum
@Date:			10/25/2018
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

int main() {
	int height, width;
	double sum = 0;
	int counter = 0;

	// Get input
	cout << "Enter a box height(between 3 and 10): ";
	cin >> height;
	while (height < 3 || height > 10) {
		cout << "That number is out of bounds: Try again: ";
		cin >> height;
	}

	cout << "\nEnter a box width between (" << height + 1 << " and 20): ";
	cin >> width;
	while (width <= height || width > 20) {
		cout << "That number is out of bounds: Try again: ";
		cin >> width;
	}

	// Output the integers in the range and their average
	cout << "\nThe integers from " << height << " to " << width << " are:\n\t";
	for (int i = height; i <= width; i++) {
		cout << i << " ";
		sum += i;
		counter++;
	}
	cout << "\nand the average of those numbers is " << (sum / counter) << "\n\n";

	// Print a box
	for (int i = 1; i <= height; i++) {
		if (i == 1 || i == height) {
			cout << "*" << setw(width) << setfill('*') << "*\n";
		}
		else {
			cout << "*" << setw(width) << setfill(' ') << "*\n";
		}
	}
	cout << endl;

	// Print a triangle
	for (int i = 1; i <= height; i++) {
		for (int x = 1; x <= i * 2; x++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}