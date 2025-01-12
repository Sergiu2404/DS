// Unrolled Linked List Implementation
// Summary:
// An unrolled linked list is a data structure optimized for cache efficiency and space usage. Instead of storing one element per node,
// each node (block) contains multiple elements, which improves memory locality. The structure uses circular linked lists within blocks
// and ensures that all blocks, except the last one, hold a fixed number of elements. This structure supports efficient element search
// and insertion with O(\sqrt{n}) complexity.
//
// Features:
// - Search: To find the k-th element, traverse the list of blocks to find the target block (O(\sqrt{n})), then locate the element in the block (O(\sqrt{n})).
// - Insertion: Inserting an element requires shifting elements to maintain the fixed block size. In case a block overflows, a new block is created.
// - Shifting: Elements are shifted between blocks in O(1) per operation, ensuring efficient redistribution.
//
// Advantages:
// - Reduced space usage compared to traditional linked lists by reducing the number of links.
#include "UnrolledLinkedList.h"
#include <cassert>



void printTestSeparator(const std::string& testName) {
    std::cout << "\n=== " << testName << " ===" << std::endl;
}
// verify element at index
void verifyElement(UnrolledLinkedList& list, int index, int expectedValue) {
    int actualValue = list.getElement(index);
    std::cout << "Verifying index " << index << ": ";
    if (actualValue == expectedValue) {
        std::cout << "PASS (value = " << actualValue << ")" << std::endl;
    }
    else {
        std::cout << "FAIL (expected " << expectedValue << ", got " << actualValue << ")" << std::endl;
    }
}

int main() {
    UnrolledLinkedList list(3);

    // 1: Basic Insertion
    printTestSeparator("Test 1: Basic Insertion");
    std::cout << "Adding elements 10, 20, 30" << std::endl;
    list.addElement(0, 10);
    list.addElement(1, 20);
    list.addElement(2, 30);
    list.printList();

    verifyElement(list, 0, 10);
    verifyElement(list, 1, 20);
    verifyElement(list, 2, 30);


    // 2:Insert and cause block split
    printTestSeparator("Test 2: Insert causing block split");
    std::cout << "Adding elements 40, 50 (should cause block split)" << std::endl;
    list.addElement(3, 40);
    list.addElement(4, 50);
    list.printList();

    verifyElement(list, 3, 40);
    verifyElement(list, 4, 50);


    // 3: Insert in middle
    printTestSeparator("Test 3: Insert in middle");
    std::cout << "Adding element 25 at index 2" << std::endl;
    list.addElement(2, 25);
    list.printList();

    verifyElement(list, 1, 20);
    verifyElement(list, 2, 25);
    verifyElement(list, 3, 30);


    // 4: multiple insertions
    printTestSeparator("Test 4: Multiple insertions");
    std::cout << "Adding elements 60, 70, 80, 90, 100" << std::endl;
    list.addElement(6, 60);
    list.addElement(7, 70);
    list.addElement(8, 80);
    list.addElement(9, 90);
    list.addElement(10, 100);
    list.printList();

    verifyElement(list, 6, 60);
    verifyElement(list, 8, 80);
    verifyElement(list, 10, 100);


    // 5: Edge cases
    printTestSeparator("Test 5: Edge cases");
    std::cout << "Testing invalid indices:" << std::endl;

    // try get element at invalid or nonexisting index
    std::cout << "Attempting to get element at index -1:" << std::endl;
    list.getElement(-1);

    std::cout << "Attempting to get element at very large index:" << std::endl;
    list.getElement(1000);


    // 6: Final state
    printTestSeparator("Test 6: Final state verification");
    std::cout << "Final list state:" << std::endl;
    list.printList();

    std::cout << "\nExpected values in order: 10, 20, 25, 30, 40, 50, 60, 70, 80, 90, 100" << std::endl;

    // verify all the elem
    int expectedValues[] = { 10, 20, 25, 30, 40, 50, 60, 70, 80, 90, 100 };
    for (int i = 0; i < 11; i++) {
        verifyElement(list, i, expectedValues[i]);
    }

    std::cout << "\nTest complete! The list will be automatically cleaned up by the destructor." << std::endl;
    return 0;
}