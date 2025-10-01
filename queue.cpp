#include "queue.h"
#include <iostream>
using namespace std;

void Queue::resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[(front + i) % size];  // Копируем с учетом кругового буфера
    }
    delete[] data;
    data = newData;
    front = 0;
    rear = size;
}

Queue::Queue() {
    capacity = 10;
    data = new int[capacity];
    front = 0;
    rear = 0;
    size = 0;
}

Queue::~Queue() {
    delete[] data;
}

void Queue::push(int value) {
    if (size == capacity) {
        resize();
    }
    data[rear] = value;
    rear = (rear + 1) % capacity;  // Круговой буфер
    size++;
}

void Queue::pop() {
    if (size > 0) {
        front = (front + 1) % capacity;  // FIFO - удаляем из начала
        size--;
    }
}

int Queue::peek() {
    if (size > 0) {
        return data[front];  // Первый элемент
    }
    return -1;
}

bool Queue::isEmpty() {
    return size == 0;
}

void Queue::print() {
    cout << "Очередь: ";
    for (int i = 0; i < size; i++) {
        int index = (front + i) % capacity;
        cout << data[index] << " ";
    }
    cout << endl;
}
