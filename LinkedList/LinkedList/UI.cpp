#include "LinkedList.h"

int main() {
	LinkedList list;
	std::string value;

	std::cout << "a - Add an item" << std::endl;
	std::cout << "r - Remove an item" << std::endl;
	std::cout << "d - Remove all items" << std::endl;
	std::cout << "Please select an option: ";

	std::getline(std::cin, value);

	if (list.insert(value)) {
		std::cout << value << " was inserted successfully." << std::endl;
	}
	else {
		std::cout << value << " is already in the list." << std::endl;
	}

	//LinkedList myList;
	//std::string value;

	//for (int x = 0; x < 3; x++) {
	//	std::cout << "Enter a string: ";
	//	std::getline(std::cin, value);
	//	if (myList.insert(value)) {
	//		std::cout << "Inserted successfully" << std::endl;
	//	}
	//	else {
	//		std::cout << "Already in the list" << std::endl;
	//	}
	//}
	//
	//myList.print();

	//std::cout << myList.getLength() << std::endl;
	//std::cout << myList.count() << std::endl;

	//myList.printReverse();

	//std::cout << "Enter a string to remove: ";
	//std::getline(std::cin, value);
	//if (myList.remove(value)) {
	//	std::cout << "Removed successfully" << std::endl;
	//}
	//myList.print();

	//myList.removeAll();
	//std::cout << "Empty the list" << std::endl;
	//myList.print();
	//std::cout << myList.count() << std::endl;


	return 0;
}