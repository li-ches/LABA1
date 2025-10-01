#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    int* data;
    int front;     // Индекс первого элемента
    int rear;      // Индекс следующего свободного места
    int capacity;
    int size;
    void resize();  // Увеличение размера

public:
    Queue();
    ~Queue();

    // Основные операции очереди
    void push(int value);  // Добавление в конец O(1)
    void pop();           // Удаление из начала O(1)
    int peek();           // Чтение первого элемента O(1)
    bool isEmpty();       // Проверка пустоты
    void print();         // Вывод очереди
};

#endif
