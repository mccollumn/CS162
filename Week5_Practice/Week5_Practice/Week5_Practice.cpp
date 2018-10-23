#include<iostream>

using namespace std;

int main() {

	int x = 1;
	while (x <= 10) {
		cout << x << endl;
		x++;
	}

	int y = 2;
	while (y <= 100) {
		cout << y << endl;
		//y = y + 2;
		y += 2;
	}

	int odd;
	cout << "Enter an odd number :";
	cin >> odd;
	while (odd % 2 == 0) {
		cout << "That is not odd. Enter an odd number: ";
		cin >> odd;
	}
	cout << "That works!\n";

	return 0;
}