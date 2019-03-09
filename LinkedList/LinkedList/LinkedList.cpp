/*
@Filename:		LinkedList.cpp
@Author:		Nick McCollum
@Date:			3/9/2019
@Version:		1.0
@Dev env:		VS 2017
@Description:	Implementation of LinkedList class
*/

#include "LinkedList.h"

LinkedList::LinkedList() {
	head = nullptr;
	length = 0;
}

LinkedList::~LinkedList() {
	removeAll();
}

bool LinkedList::insert(std::string value) {
	Node* newNode = new Node;
	newNode->next = nullptr;
	newNode->data = value;

	// List is currently empty
	if (head == nullptr) {
		head = newNode;
		length++;
	}
	else {
		Node* current = head;
		Node* previous = nullptr;
		bool found = false;

		// Find where newNode should be inserted
		found = locate(value, current, previous);

		// Node is already in the list
		if (found && current->data == value) {
			return false;
		}

		// newNode value is smaller than any existing values
		// Insert newNode at the beginning
		if (current == head) {
			newNode->next = head;
			head = newNode;
			length++;
		}
		// Insert newNode somewhere in the middle of the list
		else {
			previous->next = newNode;
			newNode->next = current;
			length++;
		}
	}
	return true;
}

bool LinkedList::remove(std::string value) {
	// The list is empty
	if (head == nullptr) {
		return false;
	}
	else {
		Node* current = head;
		Node* previous = nullptr;

		// Search the list for the value
		locate(value, current, previous);

		// The value is not in the list
		if (current == nullptr) {
			return false;
		}
		else {
			if (current->data == value) {
				// The node being deleted is at the beginning of the list
				if (head == current) {
					head = head->next;
					delete current;
				}
				// The node neing deleted is somewhere else in the list
				else {
					previous->next = current->next;
					delete current;
				}
				length--;
			}
			// The value is not in the list
			else {
				return false;
			}
		}
	}
	return true;
}

void LinkedList::print() {
	Node* current = head;
	while (current != nullptr) {
		std::cout << current->data << std::endl;
		current = current->next;
	}
}

void LinkedList::printReverse() {
	printReverse(head);
}

void LinkedList::printReverse(Node* current) {
	if (current != nullptr) {
		printReverse(current->next);
		std::cout << current->data << std::endl;
	}
}

int LinkedList::count() {
	return count(head);
}

int LinkedList::count(Node* current) {
	if (current == nullptr) {
		return 0;
	}
	else {
		return count(current->next) + 1;
	}
}

int LinkedList::getLength() {
	return length;
}

void LinkedList::removeAll() {
	Node* current;

	while (head != nullptr) {
		current = head;
		head = head->next;
		delete current;
	}
	length = 0;
}

bool LinkedList::locate(std::string value, Node* &current, Node* &previous) {
	bool found = false;
	while (current != nullptr && !found) {
		if (current->data >= value) {
			found = true;
		}
		else {
			previous = current;
			current = current->next;
		}
	}
	return found;
}
