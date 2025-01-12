#include "XORLinkedList.h"

XOR_LinkedList::~XOR_LinkedList() {
    XOR_Node* current = head;
    XOR_Node* prev = nullptr;
    XOR_Node* next;

    while (current != nullptr) {
        // store next node before deleting current
        next = XOR(prev, current->pointerDiff);

        // store prev before deleting
        XOR_Node* temp = current;

        // move current to next before deleting
        current = next;

        delete temp;
        prev = temp; //update prev for next iter
    }
    head = nullptr;
    tail = nullptr;
}

void XOR_LinkedList::insertAtEnd(int value) {
    XOR_Node* newNode = new XOR_Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    }
    // update tail's ptrDiff and link new node
    else {
        newNode->pointerDiff = XOR(tail, nullptr);
        tail->pointerDiff = XOR(XOR(tail->pointerDiff, nullptr), newNode);
        tail = newNode;
    }
}

void XOR_LinkedList::deleteFromEnd() {
    if (tail == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }

    if (head == tail) {
        delete tail;
        head = tail = nullptr;
    }
    else {
        // update tail to prev node
        XOR_Node* prev = XOR(tail->pointerDiff, nullptr);
        prev->pointerDiff = XOR(XOR(prev->pointerDiff, tail), nullptr);
        delete tail;
        tail = prev;
    }
}

XOR_Node* XOR_LinkedList::getNode(int value) {
    XOR_Node* current = head;
    XOR_Node* prev = nullptr;
    XOR_Node* next;

    while (current != nullptr) {
        if (current->value == value) {
            return current;
        }
        next = XOR(prev, current->pointerDiff);
        prev = current;
        current = next;
    }

    std::cout << "Node with value " << value << " not found" << std::endl;
    return nullptr;
}

void XOR_LinkedList::printList() {
    XOR_Node* current = head;
    XOR_Node* prev = nullptr;
    XOR_Node* next;

    std::cout << "List elements: ";
    while (current != nullptr) {
        std::cout << current->value << " ";
        next = XOR(prev, current->pointerDiff);
        prev = current;
        current = next;
    }
    std::cout << std::endl;
}
