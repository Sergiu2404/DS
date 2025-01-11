#include "SinglyLinkedList.h"
#include <stdexcept>
using namespace std;


void LinkedList::addElement(int value)
{
	//empty list
	if (head == nullptr)
	{
		head = new Node(value);
		size++;
		return;
	}

	//insert before head
	if (value < head->value)
	{
		Node* newNode = new Node(value);
		newNode->next = head;
		head = newNode;
		size++;
		return;
	}
	Node* current = head;

	//insert in the middle
	while (current->next != nullptr && value > current->next->value)
	{
		current = current->next;
	}

	Node* newNode = new Node(value);
	newNode->next = current->next;
	current->next = newNode;
	size++;
}

void LinkedList::removeElement(int value)
{
	//empty list
	if (head == nullptr)
	{
		throw std::out_of_range("List is already empty, nothing to remove");
	}

	//delete head
	if (head->value == value)
	{
		Node* newHead = head->next;
		delete head;
		head = newHead;
		size--;
		return;
	}

	//delete from middle
	Node* current = head;
	while (current->next != nullptr)
	{
		if (current->next->value == value)
		{
			current->next = current->next->next;
			size--;
			return;
		}
		current = current->next;
	}

	throw std::out_of_range("No node exists with the given value");
}

Node* LinkedList::getElement(int value)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->value == value)
		{
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

int LinkedList::getSize()
{
	return size;
}

void LinkedList::printList()
{
	Node* current = head;
	while (current)
	{
		cout << current->value << " ";
		current = current->next;
	}
}

LinkedList::~LinkedList()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}
