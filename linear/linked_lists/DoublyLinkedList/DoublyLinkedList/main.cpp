#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

int main()
{
    DoublyLinkedList sortedDoublyLinkedList;
    sortedDoublyLinkedList.add(3);
    sortedDoublyLinkedList.add(1);
    sortedDoublyLinkedList.add(2);

    cout << "size: " << sortedDoublyLinkedList.getSize() << endl;
    sortedDoublyLinkedList.printList();

    sortedDoublyLinkedList.add(3);
    sortedDoublyLinkedList.add(4);

    sortedDoublyLinkedList.remove(2);
    sortedDoublyLinkedList.remove(1);
    sortedDoublyLinkedList.remove(4);

    cout << "size: " << sortedDoublyLinkedList.getSize() << endl;
    sortedDoublyLinkedList.printList();
}