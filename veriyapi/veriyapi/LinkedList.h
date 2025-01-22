#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    void insertAt(int position, int value);
    void insertAtEnd(int value);
    void deleteAt(int position);
    void deleteAtEnd();
    void clear();
    void display() const;
    int size() const;
    void listMenu();
    void insertMenu();
    void deleteMenu();

private:
    Node* head;
    int listSize;
};

#endif // LINKEDLIST