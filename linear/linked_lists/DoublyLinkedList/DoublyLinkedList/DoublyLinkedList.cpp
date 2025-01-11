#include "DoublyLinkedList.h"
#include <stdexcept>
#include <iostream>

using namespace std;

void DoublyLinkedList::add(int value)
{
    // Empty list
    if (head == nullptr)
    {
        head = new Node(value);
        size++;
        return;
    }

    // Insert before head
    if (value < head->value)
    {
        Node* secondNode = head;
        head = new Node(value);
        secondNode->previous = head;
        head->next = secondNode;
        size++;
        return;
    }

    Node* current = head;
    while (current->next && current->next->value < value)
    {
        current = current->next;
    }

    // Insert at the end
    if (current->next == nullptr)
    {
        current->next = new Node(value);
        current->next->previous = current;
        size++;
        return;
    }

    // Insert in the middle
    Node* newNode = new Node(value);
    newNode->next = current->next;
    newNode->previous = current;
    current->next->previous = newNode;
    current->next = newNode;
    size++;
}

void DoublyLinkedList::remove(int value)
{
    if (head == nullptr)
    {
        throw std::out_of_range("No elements left to remove");
    }

    // Remove head
    if (head->value == value)
    {
        Node* temp = head;
        head = head->next;
        if (head != nullptr) // Check to avoid dereferencing nullptr when list becomes empty
            head->previous = nullptr;
        size--;
        delete temp; // Delete the old head node to prevent memory leak
        return;
    }

    // Find the node to remove
    Node* current = head->next;
    while (current && current->value != value)
    {
        current = current->next;
    }
    if (current == nullptr)
    {
        throw std::out_of_range("No element with given value found");
    }

    // Remove last node
    if (current->next == nullptr)
    {
        current->previous->next = nullptr;
    }
    else // Remove from the middle
    {
        current->next->previous = current->previous;
        current->previous->next = current->next;
    }

    size--;
    delete current;
}

Node* DoublyLinkedList::get(int value)
{
    Node* current = head;
    while (current)
    {
        if (current->value == value)
        {
            return current;
        }
        current = current->next;
    }

    throw std::out_of_range("No element with given value found");
}

int DoublyLinkedList::getSize()
{
    return size;
}

void DoublyLinkedList::printList()
{
    Node* current = head;
    while (current)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}
