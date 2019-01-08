/*
@Filename:		Bulbasaur-Squirtle Challenge.cpp
@Author:		Nick McCollum
@Date:			1/8/2019
@Version:		1.0
@Dev env:		VS 2017
@Description:	Prints the numbers from 1 to 100.
				For multiples of three print "Bulbasaur" instead of the number
				For the multiples of five print "Squirtle" instead of the number.
				For numbers which are multiples of both three and five print "BulbasaurSquirtle".
*/

#include <iostream>

using namespace std;

const int MAX_NUMBER = 100;

/*
checkThree() - Checks if number is multiple of 3
@param: int num
@return: bool
*/
bool checkThree(int num);

/*
checkThree() - Checks if number is multiple of 5
@param: int num
@return: bool
*/
bool checkFive(int num);

int main(){

	for (int num = 1; num <= MAX_NUMBER; num++) {
		if (checkThree(num)) {
			cout << "Bulbasaur";
		}
		if (checkFive(num)) {
			cout << "Squirtle";
		}
		if (!checkThree(num) && !checkFive(num)) {
			cout << num;
		}
		cout << endl;
	}

	return 0;
}

bool checkThree(int num) {
	if (num % 3 == 0) {
		return true;
	}
	return false;
}

bool checkFive(int num) {
	if (num % 5 == 0) {
		return true;
	}
	return false;
}