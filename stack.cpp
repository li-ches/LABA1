#include "stack.h"
#include <iostream>
using namespace std;

void Stack::resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

Stack::Stack() {
    capacity = 10;
    size = 0;
    data = new int[capacity];
}

Stack::~Stack() {
    delete[] data;
}

void Stack::push(int value) {
    if (size == capacity) {
        resize();
    }
    data[size] = value;
    size++;
}

void Stack::pop() {
    if (size > 0) {
        size--;  // LIFO - удаляем с вершины
    }
}

int Stack::top() {
    if (size > 0) {
        return data[size - 1];  // Вершина стека
    }
    return -1;
}

bool Stack::isEmpty() {
    return size == 0;
}

void Stack::print() {
    cout << "Стек: ";
    for (int i = size - 1; i >= 0; i--) {
        cout << data[i] << " ";  // Выводим сверху вниз
    }
    cout << endl;
}
