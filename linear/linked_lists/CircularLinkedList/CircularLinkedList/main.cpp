
#include "CircularLinkedList.h"


using namespace std;

int main()
{
    CircularLinkedList cll;

    cout << "Inserting elements at the end:" << endl;
    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.printList();

    cout << "Inserting element at the front:" << endl;
    cll.insertAtFront(5);
    cll.printList();

    cout << "Length of the list: " << cll.length() << endl;

    cout << "Deleting last element:" << endl;
    cll.deleteLast();
    cll.printList();

    cout << "Deleting front element:" << endl;
    cll.deleteFront();
    cll.printList();

    cout << "Getting an element (value 20):" << endl;
    CLLNode* node = cll.getElement(20);
    if (node) {
        cout << "Found node with value: " << node->value << endl;
    }

    cout << "Getting an element (value 100):" << endl;
    node = cll.getElement(100);

    return 0;
}