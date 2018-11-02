#include<iostream>

using namespace std;

int GetPositiveInt();

void main() {

	int myNumber = GetPositiveInt();

}

int GetPositiveInt() {
	int number;
	cout << "Enter a positive integer: ";
	cin >> number;

	while (number < 0) {
		cout << "It needs to be positive: ";
		cin >> number;
	}
	return number;
}