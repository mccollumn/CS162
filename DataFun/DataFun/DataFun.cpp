/*
@Filename:		DataFun.cpp
@Author:		Nick McCollum
@Date:			10/18/2018
@Version:		1.0
@Dev env:		VS 2017
@Description:	Prompts a user for an integer and a character, then outputs fun info about them.
*/

/*
Pseudocode
Part 1:

Prompt user for an integer
Input an integer

if (integer >= 0) then
	integer is positive
else
	integer is negative

if (integer > 1000) then
	integer is larger than 1000
else if (integer > 100) then
	integer is larger than 100
else if (integer > 10) then
	integer is larger than 10

if (integer mod 2 = 0) then
	integer is even
else
	integer is odd

Switch based on integer
	Case = 2
		atomic number of helium
	Case = 10
		atomic number of helium
	Case = 18
		atomic number of helium
	Case = 36
		atomic number of helium
	Case = 54
		atomic number of helium
	Case = 86
		atomic number of helium
	Default case
		not atomic number of a noble gas

Part 2:

Prompt user for a character
Input a character

if (character >= 0 AND character <= 9) then
	character is a number
else if (character >= A AND character <= Z) then
	character is upper case
	set isLetter flag to true
else if (character >= a AND character <= z) then
	character is lower case
	set isLetter flag to true
	set isLowerCase flag to true

if (character is a letter) then
	Switch based on character
		Case a:
		Case A:
		Case e:
		Case E:
		Case i:
		Case I:
		Case o:
		Case O:
		Case u:
		Case U:
			it is a vowel
		Default:
			it is not a vowel

Print the ASCII value of character

if (character is a letter) then
	if (character is lowercase) then
		alphabet position = character ASCII value - 96
	else
		alphabet position = character ASCII value - 64
	if (alphabet position mod 10 is 1 and alphabet position is not 11) then
		suffix is "st"
	else if (alphabet position mod 10 is 2 and alphabet position is not 12) then
		suffix is "nd"
	else if (alphabet position mod 10 is 3 and alphabet position is not 13) then
		suffix is "rd"
	else
		suffix is "th"

*/

#include <iostream>

using namespace std;

int main() {
	int userInt;
	int alphabetPosition;
	char userChar;
	bool isLetter = false;
	bool isLowerCase = false;

	// Favorite integer section
	// Get input from user
	cout << "What is your favorite integer? ";
	cin >> userInt;

	// Compute and print output
	// Determine if the integer is positive or negative
	if (userInt >= 0) {
		cout << "\t" << userInt << " is a positive number,\n";
	}
	else {
		cout << "\t" << userInt << " is a negative number,\n";
	}

	// Determine if the integer is greater than 1000, 100, or 10
	if (userInt > 1000) {
		cout << "\tit is greater than 1000,\n";
	}
	else if (userInt > 100) {
		cout << "\tit is greater than 100,\n";
	}
	else if (userInt > 10) {
		cout << "\tit is greater than 10,\n";
	}

	// Determine if the integer is even or odd
	if (userInt % 2 == 0) {
		cout << "\tit is even,\n";
	}
	else {
		cout << "\tit is odd,\n";
	}

	// Determine if the integer is the atomic number of a noble gas
	switch (userInt) {
	case 2:
		cout << "\tand it is the atomic number of helium.\n";
		break;
	case 10:
		cout << "\tand it is the atomic number of neon.\n";
		break;
	case 18:
		cout << "\tand it is the atomic number of argon.\n";
		break;
	case 36:
		cout << "\tand it is the atomic number of krypton.\n";
		break;
	case 54:
		cout << "\tand it is the atomic number of xenon.\n";
		break;
	case 86:
		cout << "\tand it is the atomic number of radon.\n";
		break;
	default:
		cout << "\tand it is not the atomic number of a noble gas.\n";
		break;
	}

	// Favorite character section
	// Get input from user
	cout << "\nWhat is your favorite character? ";
	cin >> userChar;

	// Compute and print output
	// Determine if the character is a number, uppercase letter, or lowercase letter
	if (userChar >= '0' && userChar <= '9') {
		cout << "\t" << userChar << " is a numeric digit,\n";
	}
	else if (userChar >= 'A' && userChar <= 'Z') {
		cout << "\t" << userChar << " is an uppercase letter,\n";
		isLetter = true;
	}
	else if (userChar >= 'a' && userChar <= 'z') {
		cout << "\t" << userChar << " is a lowercase letter,\n";
		isLetter = true;
		isLowerCase = true;
	}

	// Determine if the character is a vowel
	if (isLetter) {
		switch (userChar) {
		case 'a':
		case 'A':
		case 'e':
		case 'E':
		case 'i':
		case 'I':
		case 'o':
		case 'O':
		case 'u':
		case 'U':
			cout << "\tit is a vowel,\n";
			break;
		default:
			cout << "\tit is not a vowel,\n";
		}
	}
	
	// Print the character's ASCII value
	cout << "\tits ACSII value is " << static_cast<int>(userChar) << ",\n";

	// Determine the character's position in the alphabet
	if (isLetter) {
		if (isLowerCase) {
			alphabetPosition = static_cast<int>(userChar) - 96;
		}
		else {
			alphabetPosition = static_cast<int>(userChar) - 64;
		}
		if ((alphabetPosition % 10 == 1) && (alphabetPosition != 11)) {
			cout << "\tand it is the " << alphabetPosition << "st letter of the alphabet.\n";
		}
		else if ((alphabetPosition % 10 == 2) && (alphabetPosition != 12)) {
			cout << "\tand it is the " << alphabetPosition << "nd letter of the alphabet.\n";
		}
		else if ((alphabetPosition % 10 == 3) && (alphabetPosition != 13)) {
			cout << "\tand it is the " << alphabetPosition << "rd letter of the alphabet.\n";
		}
		else {
			cout << "\tand it is the " << alphabetPosition << "th letter of the alphabet.\n";
		}
	}

	return 0;
}