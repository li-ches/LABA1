#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    DNode(int val);
};

class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void addToHead(int value);
    void addToTail(int value);
    void addAfter(int afterValue, int newValue);
    void addBefore(int beforeValue, int newValue);

    void removeFromHead();
    void removeFromTail();
    void removeAfter(int afterValue);
    void removeBefore(int beforeValue);
    void removeByValue(int value);

    bool search(int value);

    void printForward();
    void printBackward();
};

#endif
