#include "UnrolledLinkedList.h"

UnrolledLinkedList::UnrolledLinkedList(int maxBlockSize) : firstBlock(nullptr), blockSize(maxBlockSize) {}

UnrolledLinkedList::~UnrolledLinkedList() {
    LinkedBlock* currentBlock = firstBlock;
    while (currentBlock) {
        if (currentBlock->blockHead) {
            Node* startNode = currentBlock->blockHead;
            Node* currentNode = startNode;
            if (currentNode->next != startNode) {
                do {
                    Node* nextNode = currentNode->next;
                    delete currentNode;
                    currentNode = nextNode;
                } while (currentNode != startNode);
            }
            delete startNode;
        }
        LinkedBlock* nextBlock = currentBlock->next;
        delete currentBlock;
        currentBlock = nextBlock;
    }
}

LinkedBlock* UnrolledLinkedList::createNewBlock() {
    return new LinkedBlock();
}

Node* UnrolledLinkedList::createNewNode(int value) {
    return new Node(value);
}

void UnrolledLinkedList::shiftNodes(LinkedBlock* sourceBlock) {
    while (sourceBlock->nodeCount > blockSize) {
        // Create next block if it doesn't exist
        if (!sourceBlock->next) {
            sourceBlock->next = createNewBlock();
        }

        LinkedBlock* destinationBlock = sourceBlock->next;

        // Find the last node in the source block
        Node* lastNode = sourceBlock->blockHead;
        Node* secondToLast = nullptr;
        while (lastNode->next != sourceBlock->blockHead) {
            secondToLast = lastNode;
            lastNode = lastNode->next;
        }

        // Remove the last node from source block
        if (secondToLast) {
            secondToLast->next = sourceBlock->blockHead;
        }
        else {
            // Only one node in source block
            sourceBlock->blockHead = nullptr;
        }

        // Insert at the beginning of destination block
        if (destinationBlock->blockHead) {
            // Find the last node in destination block
            Node* destLast = destinationBlock->blockHead;
            while (destLast->next != destinationBlock->blockHead) {
                destLast = destLast->next;
            }

            // Insert at beginning of destination block
            lastNode->next = destinationBlock->blockHead;
            destLast->next = lastNode;
            destinationBlock->blockHead = lastNode;
        }
        else {
            // First node in destination block
            destinationBlock->blockHead = lastNode;
            lastNode->next = lastNode;
        }

        sourceBlock->nodeCount--;
        destinationBlock->nodeCount++;

        // If source block is empty after shifting
        if (sourceBlock->nodeCount == 0) {
            sourceBlock->blockHead = nullptr;
        }

        // Continue with next block if needed
        sourceBlock = destinationBlock;
    }
}

void UnrolledLinkedList::findElementPosition(int index, LinkedBlock** targetBlock, Node** targetNode) {
    if (index < 0) {
        *targetBlock = nullptr;
        *targetNode = nullptr;
        return;
    }

    LinkedBlock* currentBlock = firstBlock;
    int currentIndex = 0;

    //find the correct block
    while (currentBlock && currentIndex + currentBlock->nodeCount <= index) {
        currentIndex += currentBlock->nodeCount;
        currentBlock = currentBlock->next;
    }

    if (!currentBlock) {
        *targetBlock = nullptr;
        *targetNode = nullptr;
        return;
    }

    //find the node from the block
    Node* currentNode = currentBlock->blockHead;
    for (int i = 0; i < index - currentIndex; i++) {
        currentNode = currentNode->next;
    }

    *targetBlock = currentBlock;
    *targetNode = currentNode;
}

void UnrolledLinkedList::addElement(int index, int value) {
    //empty list case
    if (!firstBlock) {
        firstBlock = createNewBlock();
        Node* newNode = createNewNode(value);
        newNode->next = newNode;
        firstBlock->blockHead = newNode;
        firstBlock->nodeCount = 1;
        return;
    }

    // find correct block for adding new elem
    LinkedBlock* targetBlock = firstBlock;
    int currentIndex = 0;

    while (targetBlock->next && currentIndex + targetBlock->nodeCount <= index) {
        currentIndex += targetBlock->nodeCount;
        targetBlock = targetBlock->next;
    }

    if (index > currentIndex + targetBlock->nodeCount) {
        std::cerr << "Error: Index out of bounds" << std::endl;
        return;
    }

    Node* newNode = createNewNode(value);

    // Insert empty block
    if (!targetBlock->blockHead) {
        targetBlock->blockHead = newNode;
        newNode->next = newNode;
    }
    // Insert at beginning of block
    else if (index - currentIndex == 0) {
        Node* lastNode = targetBlock->blockHead;
        while (lastNode->next != targetBlock->blockHead) {
            lastNode = lastNode->next;
        }
        newNode->next = targetBlock->blockHead;
        lastNode->next = newNode;
        targetBlock->blockHead = newNode;
    }
    // Insert in the middle or at the end of the block
    else {
        Node* currentNode = targetBlock->blockHead;
        for (int i = 0; i < index - currentIndex - 1; i++) {
            currentNode = currentNode->next;
        }
        newNode->next = currentNode->next;
        currentNode->next = newNode;
    }

    targetBlock->nodeCount++;
    if (targetBlock->nodeCount > blockSize) {
        shiftNodes(targetBlock);
    }
}

int UnrolledLinkedList::getElement(int index) {
    LinkedBlock* targetBlock;
    Node* targetNode;
    findElementPosition(index, &targetBlock, &targetNode);

    if (!targetBlock || !targetNode) {
        std::cerr << "Error: Index out of bounds" << std::endl;
        return -1;
    }

    return targetNode->value;
}

void UnrolledLinkedList::printList() {
    LinkedBlock* currentBlock = firstBlock;
    int blockIndex = 0;
    int totalElements = 0;

    while (currentBlock) {
        std::cout << "Block " << blockIndex++ << " (count=" << currentBlock->nodeCount << "): ";
        if (currentBlock->blockHead) {
            Node* currentNode = currentBlock->blockHead;
            do {
                std::cout << currentNode->value << " ";
                totalElements++;
                currentNode = currentNode->next;
            } while (currentNode != currentBlock->blockHead);
        }
        std::cout << "| ";
        currentBlock = currentBlock->next;
    }
    std::cout << "\nTotal elements: " << totalElements << std::endl;
}