#include <iostream>

using namespace std;

struct CLLNode {
	int value;
	CLLNode* next;

	CLLNode(int value) : value{ value }, next{ nullptr } {}
};

class CircularLinkedList {
private:
	CLLNode* head;

public:
	CircularLinkedList() : head{ nullptr } {}

	int length();

	void printList();

	void insertAtEnd(int data);

	void insertAtFront(int data);

	void deleteLast();

	void deleteFront();

	CLLNode* getElement(int data);
};