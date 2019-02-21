#include "Cat.h"
#include <iostream>

Cat::Cat() {
	weightLbs = 12;
	alive = true;
	testPtr = new int[10];
	std::cout << "Cat constructor called.\n";
}
Cat::~Cat() {
	delete[] testPtr;
	std::cout << "Cat destructor called.\n";
}

void Cat::feed(int foodWeightLbs) {
	if (alive) {
		weightLbs += foodWeightLbs;
	}
	if (weightLbs > 30) {
		alive = false;
	}
}
