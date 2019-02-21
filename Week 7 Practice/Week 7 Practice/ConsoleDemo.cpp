#include "Cat.h"

int main() {
	Cat* p1 = nullptr;
	p1 = new Cat;

	// Same thing
	(*p1).feed(10);
	p1->feed(10);

	delete p1;
	p1 = nullptr;

	return 0;
}