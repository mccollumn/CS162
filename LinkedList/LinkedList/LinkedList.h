/*
@Filename:		LinkedList.h
@Author:		Nick McCollum
@Date:			3/9/2019
@Version:		1.0
@Dev env:		VS 2017
@Description:	Interface for LinkedList class
*/

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

	/*
	insert: Add an item to the list
	@param: string Value to Add
	@return: bool Successful
	*/
	bool insert(std::string value);

	/*
	remove: Remove an item to the list
	@param: string Value to Remove
	@return: bool Successful
	*/
	bool remove(std::string value);

	/*
	print: Print the contents of the list
	@prarm: none
	@return: none
	*/
	void print();

	/*
	printReverse: Wrapper for private printReverse() method
	@prarm: none
	@return: none
	*/
	void printReverse();

	/*
	count: Wrapper for private count() method
	@param: none
	@reuturn: int Number of Items
	*/
	int count();

	/*
	getLength: Returns the current length of the list
	@param: none
	@return: int Number of Items
	*/
	int getLength();

	/*
	removeAll: Removes all items from the list
	@param: none
	@return: none
	*/
	void removeAll();

private:
	Node* head;
	int length;

	/*
	printReverse: Print the contents of the list in reverse
	@prarm: Node pointer
	@return: none
	*/
	void printReverse(Node* current);

	/*
	count: Counts the number of items currently in the list
	@param: Node pointer
	@reutn: int Number of Items
	*/
	int count(Node* current);

	/*
	locate: Finds the nodes before and after the value in the list
	@param: string Value, Node pointer After. Node pointer Before
	@return: bool Successful
	*/
	bool locate(std::string value, Node* &current, Node* &previous);
};

