#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct Node {
    int data;
    Node* next;
    Node(int val);
};

class LinkedList {
private:
    Node* head;  // Указатель на первый узел

public:
    LinkedList();
    ~LinkedList();

    // Операции добавления
    void addFirst(int val);  // В начало O(1)
    void addLast(int val);   // В конец O(n)

    // Операции удаления
    void removeFirst();      // Из начала O(1)
    void removeLast();       // Из конца O(n)

    // Поисковые операции
    bool find(int val);      // Поиск по значению O(n)
    void removeValue(int val); // Удаление по значению O(n)

    void print();            // Вывод списка
};

#endif
