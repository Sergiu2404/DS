#pragma once
#include <iostream>

struct XOR_Node {
    int value;
    XOR_Node* pointerDiff; // XOR of previous and next node addresses

    XOR_Node(int val) : value{ val }, pointerDiff{ nullptr } {}
};

using namespace std;

class XOR_LinkedList {
private:
    XOR_Node* head;
    XOR_Node* tail;

    XOR_Node* XOR(XOR_Node* a, XOR_Node* b) {
        return (XOR_Node*)((uintptr_t)a ^ (uintptr_t)b); // XOR two pointers
    }

public:
    XOR_LinkedList() : head{ nullptr }, tail{ nullptr } {}

    ~XOR_LinkedList();

    void insertAtEnd(int value);

    void deleteFromEnd();

    XOR_Node* getNode(int value);

    void printList();
};