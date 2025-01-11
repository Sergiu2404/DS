#pragma once

#include <iostream>

struct Node {
	Node* next;
	int value;
	Node(int value) : value{ value }, next(nullptr){}
};

class LinkedList {
	private:
		int size = 0;
		Node* head = nullptr;

	public:
		LinkedList(): head(nullptr), size(0){}

		void addElement(int value);
		void removeElement(int value);
		Node* getElement(int value);
		int getSize();
		void printList();

		~LinkedList();

};