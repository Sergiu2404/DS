#pragma once
#include <iostream>

using namespace std;


struct Node {
	Node* left;
	Node* right;
	int value;

	Node(int value) : value{ value }, left{ nullptr }, right{ nullptr } {}
};

class BinaryTree {
	private:
		int size = 0;
		Node* root;

		void addElementHelper(Node* node, int value);
		Node* removeHelper(Node* node, int value);
		Node* findMin(Node* node); //find node with smallest value in right subtree
		Node* getElementHelper(Node* node, int value);
		void printInOrder(Node* node);
	public:
		BinaryTree() : root(nullptr), size(0) {}

		void addElement(int value);
		void removeElement(int value);
		Node* getElement(int value);
		int getSize();
		void printTree();
		
};