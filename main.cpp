#include <iostream>
#include "LinkedList.cpp"
int main() {

LinkedList list(5);

    list.append(10);
    list.append(15);
    list.append(20);

    cout << "Original list:" << endl;
    list.printList();
    list.getLength();
    cout << endl;

    list.DeleteLast();
    cout << "List after deleting the last node:" << endl;
    list.printList();
    list.getLength();
    cout << endl;

    list.DeleteFirst();
    cout << "List after deleting the first node:" << endl;
    list.printList();
    list.getLength();
    cout << endl;

    list.insert(1, 25);
    cout << "List after inserting 25 at index 1:" << endl;
    list.printList();
    list.getLength();
    cout << endl;

    list.DeleteNode(1); 
    cout << "List after deleting the node at index 1:" << endl;
    list.printList();
    list.getLength();
    cout << endl;

    list.reverse();
    cout << "List after reversing it:" << endl;
    list.printList();
    list.getLength();
    cout << endl;
}
