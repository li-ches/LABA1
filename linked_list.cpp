#include "linked_list.h"
#include <iostream>
using namespace std;

Node::Node(int val) : data(val), next(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    // Освобождение памяти - удаляем все узлы
    while (head) {
        removeFirst();
    }
}

void LinkedList::addFirst(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;  // Новый узел указывает на старую голову
    head = newNode;        // Голова теперь новый узел
}

void LinkedList::addLast(int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }

    // Идем до последнего узла
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void LinkedList::removeFirst() {
    if (!head) return;
    Node* temp = head;
    head = head->next;  // Перемещаем голову на следующий узел
    delete temp;
}

void LinkedList::removeLast() {
    if (!head) return;
    if (!head->next) {
        // Только один элемент в списке
        delete head;
        head = nullptr;
        return;
    }

    // Ищем предпоследний узел
    Node* temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

bool LinkedList::find(int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

void LinkedList::removeValue(int val) {
    if (!head) return;

    // Особый случай: удаляем голову
    if (head->data == val) {
        removeFirst();
        return;
    }

    // Ищем узел перед тем, который нужно удалить
    Node* temp = head;
    while (temp->next && temp->next->data != val) {
        temp = temp->next;
    }

    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;  // Пропускаем удаляемый узел
        delete toDelete;
    }
}

void LinkedList::print() {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "null" << endl;
}
