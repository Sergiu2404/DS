#include <iostream>
#include "BinaryTree.h";

using namespace std;

int main()
{
    BinaryTree binaryTree;

    binaryTree.addElement(1);
    binaryTree.addElement(2);
    binaryTree.addElement(0);
    binaryTree.addElement(-11);

    binaryTree.removeElement(1);

    binaryTree.printTree();
    cout << binaryTree.getSize();
}