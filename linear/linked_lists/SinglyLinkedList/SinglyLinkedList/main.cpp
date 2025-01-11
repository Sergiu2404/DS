
#include "SinglyLinkedList.h"
using namespace std;

int main()
{
    LinkedList linkedList;

    linkedList.addElement(4);
    linkedList.addElement(2);
    linkedList.addElement(3);
    linkedList.addElement(1);

    linkedList.printList();
    cout << endl << "size: " << linkedList.getSize() << endl;
    
    linkedList.removeElement(1);
    linkedList.removeElement(3);
    linkedList.removeElement(4);

    linkedList.printList();
    cout << endl << "size after remove: " << linkedList.getSize() << endl;
}