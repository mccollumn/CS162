#include <iostream>

using namespace std;

const int NUM_MONTHS = 12;
const int NUM_STUDENTS = 10;
const int NUM_QUIZZES = 5;

void main() {
	double monthlySales[NUM_MONTHS];
	for (int index = 0; index < 2; index++) {
		monthlySales[index] = 10;
		cout << monthlySales[index] << " ";
	}
	cout << endl;

	char grades[NUM_STUDENTS];
	for (int index = 0; index < NUM_STUDENTS; index++) {
		grades[index] = 'A';
	}
	for (int index = 0; index < NUM_STUDENTS; index++) {
		cout << grades[index] << " ";
	}
	cout << endl;

	int quizGrades[NUM_QUIZZES];
	for (int index = 0; index < NUM_QUIZZES; index++) {
		quizGrades[index] = 91 + index;
	}
	for (int index = 0; index < NUM_QUIZZES; index++){
		cout << quizGrades[index] << " ";
	}
}