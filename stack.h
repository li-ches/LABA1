#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* data;
    int size;
    int capacity;
    void resize();  // Увеличение размера

public:
    Stack();
    ~Stack();

    // Основные операции стека
    void push(int value);  // Добавление элемента O(1)
    void pop();           // Удаление элемента O(1)
    int top();            // Чтение верхнего элемента O(1)
    bool isEmpty();       // Проверка пустоты
    void print();         // Вывод стека
};

#endif
