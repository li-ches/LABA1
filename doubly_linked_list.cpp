#include "doubly_linked_list.h"
#include <iostream>
using namespace std;

DNode::DNode(int val) : data(val), next(nullptr), prev(nullptr) {}

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    while (head) {
        removeFromHead();
    }
}

void DoublyLinkedList::addToHead(int value) {
    DNode* newNode = new DNode(value);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::addToTail(int value) {
    DNode* newNode = new DNode(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::addAfter(int afterValue, int newValue) {
    DNode* current = head;
    while (current && current->data != afterValue) {
        current = current->next;
    }
    if (current) {
        DNode* newNode = new DNode(newValue);
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        if (current == tail) {
            tail = newNode;
        }
    }
}

void DoublyLinkedList::addBefore(int beforeValue, int newValue) {
    DNode* current = head;
    while (current && current->data != beforeValue) {
        current = current->next;
    }
    if (current) {
        DNode* newNode = new DNode(newValue);
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev) {
            current->prev->next = newNode;
        } else {
            head = newNode;
        }
        current->prev = newNode;
    }
}

void DoublyLinkedList::removeFromHead() {
    if (!head) return;
    DNode* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::removeFromTail() {
    if (!tail) return;
    DNode* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void DoublyLinkedList::removeAfter(int afterValue) {
    DNode* current = head;
    while (current && current->data != afterValue) {
        current = current->next;
    }
    if (current && current->next) {
        DNode* toDelete = current->next;
        current->next = toDelete->next;
        if (toDelete->next) {
            toDelete->next->prev = current;
        } else {
            tail = current;
        }
        delete toDelete;
    }
}

void DoublyLinkedList::removeBefore(int beforeValue) {
    DNode* current = head;
    while (current && current->data != beforeValue) {
        current = current->next;
    }
    if (current && current->prev) {
        DNode* toDelete = current->prev;
        if (toDelete->prev) {
            toDelete->prev->next = current;
        } else {
            head = current;
        }
        current->prev = toDelete->prev;
        delete toDelete;
    }
}
void DoublyLinkedList::removeByValue(int value) {
    DNode* current = head;
    while (current && current->data != value) {
        current = current->next;
    }
    if (current) {
        if (current->prev) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
        delete current;
    }
}

bool DoublyLinkedList::search(int value) {
    DNode* current = head;
    while (current) {
        if (current->data == value) return true;
        current = current->next;
    }
    return false;
}

void DoublyLinkedList::printForward() {
    DNode* current = head;
    cout << "Список: ";
    while (current) {
        cout << current->data;
        if (current->next) cout << " <-> ";
        current = current->next;
    }
    cout << endl;
}

void DoublyLinkedList::printBackward() {
    DNode* current = tail;
    cout << "Список назад: ";
    while (current) {
        cout << current->data;
        if (current->prev) cout << " <-> ";
        current = current->prev;
    }
    cout << endl;
}
