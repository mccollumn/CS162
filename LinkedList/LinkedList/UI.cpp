/*
@Filename:		UI.cpp
@Author:		Nick McCollum
@Date:			3/9/2019
@Version:		1.0
@Dev env:		VS 2017
@Description:	Provides the interface to manipulate list items
*/

#include <iostream>
#include <string>
#include "LinkedList.h"

/*
menu: Main menu function that processes user input
@param: LinkedList pointer List
@return: none
*/
void menu(LinkedList* list);

/*
displayMenu: Displays the menu options and accepts user input
@param: none
@return: char User's selection
*/
char displayMenu();

/*
printList: Prints the current contains of the list
@param: LinkedList pointer List
@return: none
*/
void printList(LinkedList* list);

/*
addItem: Prompts user for a list item to add
@param: LinkedList pointer List
@return: none
*/
void addItem(LinkedList* list);

/*
removeItem: Prompts user for a list item to remove
@param: LinkedList pointer List
@return: none
*/
void removeItem(LinkedList* list);

/*
removeAll: Removes all items from the list
@param: LinkedList pointer List
@return: none
*/
void removeAll(LinkedList* list);

int main() {
	LinkedList* list = new LinkedList;
	
	menu(list);

	return 0;
}

void menu(LinkedList* list) {
	switch (displayMenu()) {
	case 'a':
		addItem(list);
		printList(list);
		break;
	case 'r':
		removeItem(list);
		printList(list);
		break;
	case 'd':
		removeAll(list);
		printList(list);
		break;
	default:
		std::cout << "Invalid selection.\n\n";
	}
	menu(list);
}

char displayMenu() {
	char selection;

	std::cout << "a - Add an item" << std::endl;
	std::cout << "r - Remove an item" << std::endl;
	std::cout << "d - Remove all items" << std::endl;
	std::cout << "\nPlease select an option: ";
	selection = std::cin.get();
	std::cin.ignore();

	return selection;
}

void printList(LinkedList* list) {
	std::cout << "\nYour list contains " << list->count() << " items:\n";
	list->print();
	std::cout << "\n--------------------" << std::endl;
}

void addItem(LinkedList* list) {
	std::string value;

	std::cout << "\nEnter the value to add: ";
	std::getline(std::cin, value);

	if (list->insert(value)) {
		std::cout << "\n\"" << value << "\" was inserted successfully." << std::endl;
	}
	else {
		std::cout << "\n\"" << value << "\" is already in the list." << std::endl;
	}
}

void removeItem(LinkedList* list) {
	if (list->count() == 0) {
		std::cout << "\nThe list is currently empty.";
	}
	else {
		std::string value;
		std::cout << "\nEnter the value to remove: ";
		std::getline(std::cin, value);

		if (list->remove(value)) {
			std::cout << "\n\"" << value << "\" was removed successfully." << std::endl;
		}
		else {
			std::cout << "\n\"" << value << "\" is not in the list." << std::endl;
		}
	}
}

void removeAll(LinkedList* list) {
	char selection;

	std::cout << "\nThis will remove all items from the list.\n";
	std::cout << "Are you sure (y/n)? ";
	selection = std::cin.get();
	std::cin.ignore();

	if (selection == 'y') {
		list->removeAll();
		std::cout << "\nAll items removed successfully.\n";
	}
}