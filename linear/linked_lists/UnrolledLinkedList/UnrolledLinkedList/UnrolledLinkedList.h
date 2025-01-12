#pragma once
#include <iostream>


struct Node {
    int value;
    Node* next;

    Node(int val) : value(val), next(nullptr) {}
};

/**
 * structure representing a block in the unrolled linked list
 * each block contains a circular linked list of nodes and a pointer to the next block
 */
struct LinkedBlock {
    Node* blockHead;        // points to the first node in this block's circular list
    LinkedBlock* next;      // points to the next block in the unrolled linked list
    int nodeCount;         // number of nodes currently in this block

    LinkedBlock() : blockHead(nullptr), next(nullptr), nodeCount(0) {}
};

/**
 * @brief UnrolledLinkedList class implementing an unrolled linked list data structure
 *
 * This implementation combines aspects of arrays and linked lists for better performance:
 * - Each block contains a circular linked list of nodes
 * - All blocks except possibly the last contain exactly blockSize elements
 * - Provides O(blockSize) search time and improved cache performance
 * - Reduces memory overhead compared to traditional linked lists
 */
class UnrolledLinkedList {
private:
    LinkedBlock* firstBlock;
    const int blockSize;


    LinkedBlock* createNewBlock();

    Node* createNewNode(int value);

    /**
     * shifts nodes between blocks to maintain the blockSize property
     * sourceBlock The block from which to start shifting nodes
     */
    void shiftNodes(LinkedBlock* sourceBlock);

    /**
     * finds block and node at a given index
     * index: the index to search for
     * targetBlock: output parameter for the found block
     * targetNode: output parameter for the found node
     */
    void findElementPosition(int index, LinkedBlock** targetBlock, Node** targetNode);

public:
    UnrolledLinkedList(int maxBlockSize);
    ~UnrolledLinkedList();

    void addElement(int index, int value);

    //the value at the specified index, or -1 if index is out of bounds
    int getElement(int index);

    //prints the entire list, showing block divisions
    void printList();
};