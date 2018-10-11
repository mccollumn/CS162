/*
@Filename:		GeometryFun.cpp
@Author:		Nick McCollum
@Date:			10/4/2018
@Version:		1.0
@Dev env:		VS 2017
@Description:	Prompts a user for a positive whole number and outputs:
					The perimeter and area of a square whose side length is the entered number
					The radius, circumference, and area of a circle whose diameter is the entered number
*/

#include <iostream>
#include <cmath>		// Includes pow function

using namespace std;

const float PI = 3.1415f;

int main() {
	
	int userInput = 0;
	int perimeter, areaSquare;
	double radius, circumference, areaCircle;

	// Get input from the user
	cout << "Please enter a whole number: ";
	cin >> userInput;

	// Compute values
	perimeter = userInput * 4;
	areaSquare = pow(userInput, 2);
	radius = userInput / 2.0;
	circumference = 2 * PI * radius;
	areaCircle = PI * pow(radius, 2.0);

	// Output values
	cout << "\nA square with side length of " << userInput << "\n";
	cout << "\thas a perimeter of " << perimeter << "\n";
	cout << "\thas an area of " << areaSquare << "\n\n";
	cout << "A circle with a diameter of " << userInput << "\n";
	cout << "\thas a radius of " << radius << "\n";
	cout << "\thas a circumference of " << circumference << "\n";
	cout << "\thas an area of " << areaCircle << "\n";

	return 1;
}