#pragma once
struct Node {
	Node* next;
	Node* previous;
	int value;

	Node(int value): value(value), next(nullptr), previous(nullptr){}
};

class DoublyLinkedList {
	private:
		int size = 0;
		Node* head;

	public:
		void add(int value);
		void remove(int value);
		Node* get(int value);
		int getSize();
		void printList();
};