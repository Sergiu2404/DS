//   The ptrdiff pointer field contains	the	difference between the pointer to the next node	and	the
// pointer to the previous node. The	pointer	difference is calculated by	using exclusive - or ( XOR )
// operation.
// ptrdiff = pointer	to previous	node XOR pointer to	next node.
//   The ptrDiff of the start node (head) is the XOR of the NULL and next node (next node to the head).
// Simmilarly, the ptrdiff of the end node is the XOR of previous node (previous to end) and NULL.
//   
//   Suppose nodes A, B and C:
// ptrdiff of B will be (addr of A) XOR (addr of C);
// This approach comes with reduced memory usage compared to original DLL



#include "XORLinkedList.h"

int main() {
    XOR_LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    list.printList(); //10 20 30 40

    XOR_Node* node = list.getNode(20);
    if (node) {
        std::cout << "Found node with value: " << node->value << std::endl;
    }

    list.deleteFromEnd();
    list.printList(); // 10 20 30

    list.deleteFromEnd();
    list.printList(); // 10 20

    return 0;
}
