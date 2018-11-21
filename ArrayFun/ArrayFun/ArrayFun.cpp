/*
@Filename:		ArrayFun.cpp
@Author:		Nick McCollum
@Date:			11/19/2018
@Version:		1.0
@Dev env:		VS 2017
@Description:	Prompts a user for ten integers, stores them in an array, then outputs:
					-the entire array
					-the lowest value in the array
					-the highest value in the array
					-the number of odd numbers in the array
					-the sum of all the values in the array.
					-all the values that appear in the array more than once
*/

#include <iostream>

using namespace std;

const int NUMBER_OF_VALUES = 10;

/*
getData() - fills in given array with data entered by the user
@param: int userValues[]
@return: none
*/
void getData(int userValues[]);

/*
printData() - prints given array values to the screen(space delimited)
@param: int values[], arraySize
@return: none
*/
void printData(const int outputValues[], int arraySize);

/*
lowestValue() - returns the lowest value in the given array
@param: int values[]
@return: int lowest
*/
int lowestValue(const int userValues[]);

/*
highestValue() - returns the highest value in the given array
@param:  int values[]
@return: int highest
*/
int highestValue(const int userValues[]);

/*
countOdds() - returns the number of odd numbers in the given array
@param: int userValues[]
@return: int Number of Odds
*/
int countOdds(const int userValues[]);

/*
sum() - returns the sum of all the values in the given array
@param: int userValues[]
@return: int Sum
*/
int sum(const int userValues[]);

/*
getDuplicateValues() - returns all values that appear multiple times in the input array
@param: int userValues[], int outputValues[]
@return: int Number of Duplicates
*/
int getDuplicateValues(const int userValues[], int outputValues[]);

int main() {
	int userValues[NUMBER_OF_VALUES];
	int outputValues[NUMBER_OF_VALUES / 2];

	// Get input from user
	getData(userValues);

	// Compute and output values
	cout << "\tYou entered: ";
	printData(userValues, NUMBER_OF_VALUES);
	cout << endl;
	cout << "\tLowest value:\t" << lowestValue(userValues) << endl;
	cout << "\tHighest value:\t" << highestValue(userValues) << endl;
	cout << "\t# odd numbers:\t" << countOdds(userValues) << endl;
	cout << "\tSum of all:\t" << sum(userValues) << endl;
	cout << "\n\tThe following numbers appear multiple times: ";
	printData(outputValues, getDuplicateValues(userValues, outputValues));

	return 1;
}

void getData(int userValues[]) {
	cout << "Enter " << NUMBER_OF_VALUES << " integers (separated by a space): ";
	for (int i = 0; i < NUMBER_OF_VALUES; i++) {
		cin >> userValues[i];
	}
	cout << endl;
}

void printData(const int outputValues[], int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		cout << outputValues[i] << " ";
	}
	cout << endl;
}

int lowestValue(const int userValues[]) {
	int lowest = userValues[0];
	for (int i = 1; i < NUMBER_OF_VALUES; i++) {
		if (userValues[i] < lowest) {
			lowest = userValues[i];
		}
	}
	return lowest;
}

int highestValue(const int userValues[]) {
	int highest = userValues[0];
	for (int i = 1; i < NUMBER_OF_VALUES; i++) {
		if (userValues[i] > highest) {
			highest = userValues[i];
		}
	}
	return highest;
}

int countOdds(const int userValues[]) {
	int numOdds = 0;
	for (int i = 0; i < NUMBER_OF_VALUES; i++) {
		if (userValues[i] % 2 != 0) {
			numOdds++;
		}
	}
	return numOdds;
}

int sum(const int userValues[]) {
	int sum = 0;
	for (int i = 0; i < NUMBER_OF_VALUES; i++) {
		sum += userValues[i];
	}
	return sum;
}

int getDuplicateValues(const int userValues[], int outputValues[]) {
	int outputCounter = 0;
	for (int i = 1; i < NUMBER_OF_VALUES; i++) {
		bool duplicate = false;
		for (int x = 0; x < i && !duplicate; x++) {
			if (userValues[i] == userValues[x]) {
				duplicate = true;
				if (outputCounter == 0) {
					outputValues[outputCounter] = userValues[i];
					outputCounter++;
				}
				else {
					bool outputDuplicate = false;
					for (int o = 0; o < outputCounter && !outputDuplicate; o++) {
						if (userValues[i] == outputValues[o]) {
							outputDuplicate = true;
						}
					}
					if (!outputDuplicate) {
						outputValues[outputCounter] = userValues[i];
						outputCounter++;
					}
				}
			}
		}
	}
	return outputCounter;
}