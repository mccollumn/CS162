#pragma once

#include <iostream>
#include <string>

struct Node {
	std::string data;
	Node* next;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	bool insert(std::string value);
	bool remove(std::string value);
	void print();
	void printReverse();
	int count();
	int getLength();
	void removeAll();
private:
	Node* head;
	int length;
	void printReverse(Node* current);
	int count(Node* current);
	bool locate(std::string value, Node* &current, Node* &previous);
};

