#include "CircularLinkedList.h";


int CircularLinkedList::length()
{
	if (head == nullptr)
	{
		return 0;
	}

	CLLNode* current = head;
	int size = 0;

	do {
		current = current->next;
		size++;
	} while (current != head);

	return size;
}

void CircularLinkedList::printList() {
	CLLNode* current = head;
	if (head == nullptr)
	{
		cout << "List is empty" << endl;
		return;
	}

	do {
		cout << current->value << " ";
		current = current->next;
	} while (current != head);
}

void CircularLinkedList::insertAtEnd(int data)
{
	CLLNode* newNode = new CLLNode(data);

	if (head == nullptr) {
		head = newNode;
		newNode->next = head;
		return;
	}

	CLLNode* current = head;
	while (current->next != head) {
		current = current->next;
	}

	current->next = newNode;
	newNode->next = head;
}

void CircularLinkedList::insertAtFront(int data)
{
	CLLNode* newNode = new CLLNode(data);

	if (head == nullptr) {
		head = newNode;
		newNode->next = head;
		return;
	}

	CLLNode* current = head;
	while (current->next != head) {
		current = current->next;
	}

	current->next = newNode;
	newNode->next = head;
	head = newNode;
}

void CircularLinkedList::deleteLast()
{
	if (head == nullptr) {
		cout << "List is already empty" << endl;
		return;
	}

	if (head->next == head) {
		delete head;
		head = nullptr;
		return;
	}

	CLLNode* current = head;
	CLLNode* prev = nullptr;

	while (current->next != head) {
		prev = current;
		current = current->next;
	}

	prev->next = head;
	delete current;
}

void CircularLinkedList::deleteFront()
{
	if (head == nullptr) {
		cout << "List is already empty" << endl;
		return;
	}

	if (head->next == head) {
		delete head;
		head = nullptr;
		return;
	}

	CLLNode* current = head;
	while (current->next != head) {
		current = current->next;
	}

	CLLNode* temp = head;
	current->next = head->next;
	head = head->next;
	delete temp;
}

CLLNode* CircularLinkedList::getElement(int data)
{
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return nullptr;
	}

	CLLNode* current = head;
	do {
		if (current->value == data) {
			return current;
		}
		current = current->next;
	} while (current != head);

	cout << "No node with given value" << endl;
	return nullptr;
}