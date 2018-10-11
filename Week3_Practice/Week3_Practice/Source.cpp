#include<iostream>

using namespace std;

int main() {
	char firstLInitial;
	char lastInitial;

	cout << "Please enter your first name: ";
	cin >> firstLInitial;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Please enter your last name: ";
	cin >> lastInitial;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Your initials are: " << firstLInitial << "." << lastInitial << ".";

	return 1;
}