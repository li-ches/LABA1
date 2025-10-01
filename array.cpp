#include "array.h"
#include <iostream>
using namespace std;

// Увеличение размера массива при переполнении
void Array::resize() {
    capacity *= 2;
    int* newData = new int[capacity];
    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

Array::Array() {
    capacity = 10;
    size = 0;
    data = new int[capacity];
}

Array::~Array() {
    delete[] data;
}

void Array::add(int value) {
    if (size == capacity) {
        resize();  // Увеличиваем размер при необходимости
    }
    data[size] = value;
    size++;
}

void Array::insert(int index, int value) {
    if (index < 0 || index > size) return;

    if (size == capacity) {
        resize();
    }

    // Сдвигаем элементы для вставки
    for (int i = size; i > index; i--) {
        data[i] = data[i-1];
    }
    data[index] = value;
    size++;
}

int Array::get(int index) {
    if (index < 0 || index >= size) return -1;
    return data[index];  // Прямой доступ O(1)
}

void Array::remove(int index) {
    if (index < 0 || index >= size) return;

    // Сдвигаем элементы после удаления
    for (int i = index; i < size-1; i++) {
        data[i] = data[i+1];
    }
    size--;
}

void Array::change(int index, int value) {
    if (index < 0 || index >= size) return;
    data[index] = value;
}

int Array::length() {
    return size;
}

void Array::print() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
