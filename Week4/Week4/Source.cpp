#include <iostream>  

using namespace std;

int main() {
	int x;

	//get user input  
	cout << "Enter an integer: ";
	cin >> x;

	//do some comparisons  

	//an if statement that prints out "x is 42" if it's 42
	if (x == 42) {
		cout << "x is 42\n";
	}

	//an if else statement that prints out "x is negative" if it's less than 0 or "x is positive" if it's not less than 0
	if (x < 0) {
		cout << "x is negative\n";
	}
	else
	{
		cout << "x is positive\n";
	}

	//an if else statement that has 2 lines in both the if body and else body.
	if (x > 10) {
		cout << "x is greater than 10\n";
		cout << "Yay!\n";
	}
	else
	{
		cout << "x is less or equal to 10\n";
		cout << "Boo!\n";
	}

	//create another integer variable named y
	int y;

	//prompt the user to enter another integer and store it in y
	cout << "Enter an integer: ";
	cin >> y;

	//print "those are both over 100" if x and y are both greater than 100
	if ((x > 100) && (y > 100)) {
		cout << "Those are both over 100\n";
	}

	//print "those are both 0" if x and y are both 0
	if ((x == 0) && (y == 0)) {
		cout << "Those are both 0\n";
	}

	//print "at least one of those is negative" if one of them is negative.
	if ((x < 0) || (y < 0)) {
		cout << "At least one of those is negative";
	}

	return 1;
}