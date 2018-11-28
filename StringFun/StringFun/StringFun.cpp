/*
@Filename:		StringFun.cpp
@Author:		Nick McCollum
@Date:			11/20/2018
@Version:		1.0
@Dev env:		VS 2017
@Description:	Prompts a user to guess name and outputs the string in different ways,
				using both c-strings and string objects
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int NAME_LENGTH = 50;

/*
cStringDemo() - Perform c-string functions
@param: 
@return: none
*/
void cStringDemo();

/*
stringTypeDemo() - Perform string datatype functions
@param:
@return: none
*/
void stringTypeDemo();

/*
inputName() - Prompts user for name and returns name
@param: string Name
@return: none
*/
void inputName(char name[]);
void inputName(string& name);

/*
compareName() - Determines if name input by user matches my name
@param: string Guessed Name, string My Name
@return: bool Match
*/
bool compareName(const char name[], const char myName[]);
bool compareName(const string name, const string myName);

/*
matchMessage() - Displays a different message depending on if the names match
@param: string Guessed Name, string My Name
@return: none
*/
void matchMessage(const char name[], const char myName[]);
void matchMessage(const string name, const string myName);

/*
outputName() - Prints the name that was entered
@param: string Guessed Name
@return: none
*/
void outputName(const char name[]);
void outputName(const string name);

/*
removeVowels() - Returns a copy of the name with vowels removed
@param: string Guessed Name, string Vowelless Name
@return: none
*/
void removeVowels(const char name[], char vowellessName[]);
void removeVowels(const string name, string& vowellessName);

/*
isVowel() - Determines if a character is a vowel
@param: char Character
@return: bool
*/
bool isVowel(char character);

/*
theBarbarian() - Concatenates "the Barbarian" to the end of a string
@param: string Guessed Name, string Barbarian Name
@return: none
*/
void theBarbarian(const char name[], char barbarianName[]);
void theBarbarian(const string name, string& barbarianName);

/*
lowerString() - Returns a lowercase string
@param: string Name, string Lowercase Name
@return: none
*/
void lowerString(const char origString[], char lowerString[]);
void lowerString(const string origString, string& lowerString);

int main() {
	cStringDemo();
	stringTypeDemo();

	return 1;
}

void cStringDemo() {
	char myName[NAME_LENGTH] = "Nick McCollum";
	char guessName[NAME_LENGTH] = "";
	char vowellessName[NAME_LENGTH] = "";
	char barbarianName[NAME_LENGTH] = "";

	inputName(guessName);
	matchMessage(guessName, myName);
	outputName(guessName);
	removeVowels(guessName, vowellessName);
	cout << "Without vowels, that's " << vowellessName << endl;
	theBarbarian(guessName, barbarianName);
	cout << "\nAnd in less civilized times, it would be " << barbarianName << endl;
}

void stringTypeDemo() {
	string myName = "Nick McCollum";
	string guessName = "";
	string vowellessName = "";
	string barbarianName = "";

	cout << endl;
	inputName(guessName);
	matchMessage(guessName, myName);
	outputName(guessName);
	removeVowels(guessName, vowellessName);
	cout << "Without vowels, that's " << vowellessName << endl;
	theBarbarian(guessName, barbarianName);
	cout << "\nAnd in less civilized times, it would be " << barbarianName << endl;
}

void inputName(char name[]) {
	cout << "Guess my name (first last): ";
	cin.get(name, NAME_LENGTH);
	cin.ignore();
	cout << endl;
}

void inputName(string& name) {
	cout << "Guess my name (first last): ";
	getline(cin, name);
	cout << endl;
}

bool compareName(const char name[], const char myName[]) {
	char lowerName[NAME_LENGTH] = "";
	char lowerMyName[NAME_LENGTH] = "";
	lowerString(name, lowerName);
	lowerString(myName, lowerMyName);
	if (strcmp(lowerName, lowerMyName) == 0) {
		return true;
	}
	return false;
}

bool compareName(const string name, const string myName) {
	string lowerName = "";
	string lowerMyName = "";
	lowerString(name, lowerName);
	lowerString(myName, lowerMyName);
	if (lowerName == lowerMyName) {
		return true;
	}
	return false;
}

void matchMessage(const char name[], const char myName[]) {
	if (compareName(name, myName)) {
		cout << "Wow! You guessed it." << endl;
	}
	else {
		cout << "Nice try, but incorrect." << endl;
	}
	cout << endl;
}

void matchMessage(const string name, const string myName) {
 	if (compareName(name, myName)) {
		cout << "Wow! You guessed it." << endl;
	}
	else {
		cout << "Nice try, but incorrect." << endl;
	}
	cout << endl;
}

void outputName(const char name[]) {
	cout << "You guessed " << name << endl;
}

void outputName(const string name) {
	cout << "You guessed " << name << endl;
}

void removeVowels(const char name[], char vowellessName[]) {
	for (int i = 0; i < strlen(name); i++) {
		if (!isVowel(name[i])) {
			vowellessName[strlen(vowellessName)] = name[i];
		}
	}
}

void removeVowels(const string name, string& vowellessName) {
	for (int i = 0; i < name.length(); i++) {
		if (!isVowel(name[i])) {
			vowellessName += name[i];
		}
	}
}

bool isVowel(char character) {
	switch (tolower(character)) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}

void theBarbarian(const char name[], char barbarianName[]) {
	strcpy(barbarianName, name);
	strcat(barbarianName, " the Barbarian");
}

void theBarbarian(const string name, string& barbarianName) {
	barbarianName = name + " the Barbarian";
}

void lowerString(const char origString[], char lowerString[]) {
	for (int i = 0; char ch = origString[i]; i++) {
		lowerString[i] = tolower(ch);
	}
}

void lowerString(const string origString, string& lowerString) {
	for (int i = 0; i < origString.length(); i++) {
		lowerString += tolower(origString[i]);
	}
}