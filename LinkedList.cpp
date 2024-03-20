//
// Created by MSI Sword on 3/18/2024.
//
#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node *head;
    Node *tail;
    int length;
public:
    LinkedList(int value) {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    void append(int value) {
        Node *newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
            length++;
        } else {
            tail->next = newNode;
            tail = newNode;
            length++;
        }
    }

    void DeleteLast() {
        if (head == nullptr) {
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            length = 0;
            return;
        }

        Node *temp = head;
        while (temp != nullptr) {
            if (temp->next == tail) {
                tail = temp;
                temp->next = nullptr;
                length--;
            }
            temp = temp->next;
        }
    }

    void DeleteFirst() {
        if (length == 0) {
            return;
        }
        Node *temp = head;

        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = temp->next;
        }
        delete temp;
        length--;
    }

    void Prepend(int value) {
        Node *newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
            length++;
        } else {
            newNode->next = head;
            head = newNode;
            length++;
        }
    }


    Node *get(int index) {

        if (index < 0 || index >= length) {
            return nullptr;
        }
        Node *temp = head;

        int counter = 0;
        while (temp) {

            if (counter == index) {
                return temp;
            }
            temp = temp->next;
            counter++;
        }
        return nullptr;
    }

    bool set(int index, int value) {
        Node *temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;

    }

    bool insert(int index, int value) {
        Node *temp = get(index - 1);
        Node *newNode = new Node(value);
        if (index > length || index < 0) {
            return false;
        }
        if (index == 0) {
            Prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void DeleteNode(int index) {
        Node *temp = get(index);
        Node *prev = get(index - 1);
        if (index >= length || index < 0) {
            return;
        }
        if (index == 0) {
            DeleteFirst();
            length--;
            return;
        }
        if (temp == tail) {
            DeleteLast();
            length--;
            return;
        }

        prev->next = temp->next;
        delete temp;
        length--;
    }

    void reverse() {
        Node *temp = head;
        head = tail;
        tail = temp;

        Node *after = temp->next;
        Node *before = nullptr;

        for (int i = 0; i < length; ++i) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }

    }

    void printList() {
        Node *temp = head;
        int counter = 0;
        while (temp != nullptr) {

            cout << "index: " << counter << " Value: " << temp->value << endl;
            temp = temp->next;
            counter++;
        }
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    ~LinkedList() {
        Node *temp = head;
        while (temp) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
};
