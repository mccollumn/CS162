/*
@Filename:		TimeFun.cpp
@Author:		Nick McCollum
@Date:			11/8/2018
@Version:		1.0
@Dev env:		VS 2017
@Description:	Converts times expressed in 24-hour format to 12-hour format using a.m. and p.m.
*/

#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

/*
getTime24 - Gets valid time (hour and minute) expressed as per 24 hour clock
@param: int Hour, int Minutes
@return: none
*/
void getTime24(int& hour24, int& minutes);

/*
convertTime24to12: - Converts 24-hour clock hour to 12-hour clock hour
@param: int Hour in 24, int Hour in 12, bool pm
@return: none
*/
void convertTime24to12(int& hour24, int& hour12, bool& pm);

/*
printTime24  - prints the given time in 24 hour format
@param: int Hour in 24, int Minutes
@return: none
*/
void printTime24(int hour24, int minutes);

/*
printTime12  - prints the given time in 12 hour format
@param: int Hour in 12, int Minutes
@return: none
*/
void printTime12(int hour12, int minutes, bool pm);

/*
userWantsToContinue - Determines if user wants to continue
@param: none
@return: bool Yes/No
*/
bool userWantsToContinue();

/*
validInput - Determines if user input is a valid 24 hour time
@param: int Hour in 24, in Minutes
@return: bool Yes/No
*/
bool validInput(int hour, int minutes);

int main() {
	int hour24, hour12, minutes;
	bool pm;

	do {
		getTime24(hour24, minutes);
		convertTime24to12(hour24, hour12, pm);
		printTime12(hour12, minutes, pm);
		printTime24(hour24, minutes);
	} while (userWantsToContinue());

	return 1;
}

void getTime24(int& hour24, int& minutes) {
	char ch;
	cout << "Enter a time in 24 hour format (for example 13:45): ";
	cin >> hour24 >> ch >> minutes;
	while (!validInput(hour24, minutes))	{
		cout << "That is not a valid time.\n";
		cout << "Enter a time in 24 hour format (for example 13:45): ";
		cin >> hour24 >> ch >> minutes;
	}
}

void convertTime24to12(int& hour24, int& hour12, bool& pm) {
	hour12 = ((hour24 + 11) % 12 + 1);
	// Convention: 00:00 = 12:00am (midnight start of day), 12:00 = 12:00pm (noon), 24:00 = 12:00am (midnight end of day)
	pm = false;
	if (hour24 >= 12 && hour24 != 24) {
		pm = true;
	}
}

void printTime24(int hours, int minutes) {
	cout << "That time in 24 hour format is: " << setw(2) << setfill('0') << hours << ":" << setw(2) << minutes << endl;
}

void printTime12(int hours, int minutes, bool pm) {
	cout << "That time in 12 hour format is: " << hours << ":" << setw(2) << setfill('0') << minutes;
	cout << ((pm) ? " pm\n" : " am\n");
}

bool userWantsToContinue() {
	char again;
	do
	{
		cout << "\nWould you like to continue (Y/N)? ";
		cin >> again;
		if (tolower(again) == 'n') {
			return false;
		}
	} while (tolower(again) != 'y');
	return true;
}

bool validInput(int hours, int minutes) {
	// TODO: Confirm 2 digit minutes was entered. Read it as a string first?
	if (hours < 0 || hours > 24 || minutes < 0 || minutes > 59 || (hours == 24 && minutes != 0)) {
		return false;
	}
	return true;
}