#include "BinaryTree.h"
#include <stdexcept>


void BinaryTree::addElement(int value)
{
	if (root == nullptr)
	{
		root = new Node(value);
	}
	else {
		addElementHelper(root, value);
	}

	size++;
}

void BinaryTree::addElementHelper(Node* node, int value)
{
	if (value < node->value)
	{
		if (node->left == nullptr)
		{
			node->left = new Node(value);
		}
		else
		{
			addElementHelper(node->left, value);
		}
	}
	else
	{
		if (node->right == nullptr)
		{
			node->right = new Node(value);
		}
		else
		{
			addElementHelper(node->right, value);
		}
	}
}

Node* BinaryTree::removeHelper(Node* node, int value)
{
	if (node == nullptr)
	{
		return nullptr;
	}

	if (value < node->value)
	{
		node->left = removeHelper(node->left, value);
	}
	else if (value > node->value)
	{
		node->right = removeHelper(node->right, value);
	}
	else // node found
	{
		// leaf node case
		if (node->left == nullptr && node->right == nullptr)
		{
			delete node;
			return nullptr;
		}

		// has one child
		if (node->left == nullptr)
		{
			Node* temporary = node->right;
			delete node;
			return temporary;
		}
		else if (node->right == nullptr)
		{
			Node* temporary = node->left;
			delete node;
			return temporary;
		}

		// has 2 children
		Node* temporary = findMin(node->right); // find smallest value in the right subtree
		node->value = temporary->value;         // replace node's value with successor's value
		node->right = removeHelper(node->right, temporary->value); // remove successor
	}

	return node;
}

Node* BinaryTree::findMin(Node* node)
{
	while (node->left != nullptr)
	{
		node = node->left;
	}

	return node;
}


void BinaryTree::removeElement(int value)
{
	if (root == nullptr)
	{
		throw new out_of_range("Tree is already empty");
	}

	root = removeHelper(root, value);
	size--;
}

Node* BinaryTree::getElement(int value)
{
	if (root == nullptr)
	{
		throw new out_of_range("Tree is empty, no elements to get");
	}
	else if(root->value == value)
	{
		return root;
	}
	else
	{
		return getElementHelper(root, value);
	}
}

Node* BinaryTree::getElementHelper(Node* node, int value)
{
	if (node->value == value)
	{
		return node;
	}
	else if (value < node->value)
	{
		if(node->left != nullptr)
			return getElementHelper(node->left, value);
	}
	else
	{
		if (node->right != nullptr)
			return getElementHelper(node->right, value);
	}

	throw new out_of_range("No element with given value");
}

int BinaryTree::getSize()
{
	if (size < 0)
	{
		throw new out_of_range("Size can not be a negative number");
	}
	return size;
}

void BinaryTree::printTree()
{
	if (root == nullptr)
	{
		cout << "The tree is empty";
	}
	else
	{
		cout << "Tree printed in-order: ";
		printInOrder(root);
		cout << endl;
	}
}

void BinaryTree::printInOrder(Node* node)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		//print left subtree
		printInOrder(node->left);

		cout << node->value << " ";

		//print right subtree
		printInOrder(node->right);
	}
}
