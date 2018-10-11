/*
@Filename:		GeometryFun2.cpp
@Author:		Nick McCollum
@Date:			10/11/2018
@Version:		1.0
@Dev env:		VS 2017
@Description:	Prompts a user for a positive whole number and the number of side for a polygon, then outputs:
					The perimeter and area of a square whose side length is the entered number
					The radius, circumference, and area of a circle whose diameter is the entered number
					The perimeter and area of an equilateral triangle whose side length is equal to the entered number.
					The perimeter and area of a regular polygon whose side length and number of sides is equal to the numbers entered.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const float PI = 3.1415f;
const float TRIANGLE_MULT = sqrt(3) / 4;
const double DEGREE_TO_RADIAN_CONV = PI / 180.0;

int main() {
	
	int userInputLength = 0;
	int userInputSides = 0;
	int perimeterSquare, areaSquare;
	int perimeterTriangle;
	int perimeterPolygon;
	double radius, circumference, areaCircle;
	double areaTriangle;
	double areaPolygon, apothem;

	// Get input from the user
	cout << "Please enter a whole number: ";
	cin >> userInputLength;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Please enter the number of sides of a regular polygon: ";
	cin >> userInputSides;

	// Compute values
	perimeterSquare = userInputLength * 4;
	areaSquare = pow(userInputLength, 2);
	radius = userInputLength / 2.0;
	circumference = 2 * PI * radius;
	areaCircle = PI * pow(radius, 2.0);
	perimeterTriangle = userInputLength * 3;
	areaTriangle = TRIANGLE_MULT * pow(userInputLength, 2.0);
	perimeterPolygon = userInputLength * userInputSides;
	apothem = userInputLength / (2.0 * tan((180.0 / userInputSides) * DEGREE_TO_RADIAN_CONV));
	areaPolygon = (perimeterPolygon * apothem) / 2;

	// Output values
	cout << setprecision(3) << fixed;
	cout << "\nA square with side length of " << userInputLength << "\n";
	cout << "\thas a perimeter of " << perimeterSquare << "\n";
	cout << "\thas an area of " << areaSquare << "\n\n";
	cout << "A circle with a diameter of " << userInputLength << "\n";
	cout << "\thas a radius of " << radius << "\n";
	cout << "\thas a circumference of " << circumference << "\n";
	cout << "\thas an area of " << areaCircle << "\n\n";
	cout << "An equilateral triangle with side length of " << userInputLength << "\n";
	cout << "\thas a perimeter of " << perimeterTriangle << "\n";
	cout << "\thas an area of " << areaTriangle << "\n\n";
	cout << "A " << userInputSides << " sided regular polygon with side length of " << userInputLength << "\n";
	cout << "\thas a perimeter of " << perimeterPolygon << "\n";
	cout << "\thas an area of " << areaPolygon << "\n\n";

	return 1;
}