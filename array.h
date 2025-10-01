#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
    int* data;      // Указатель на массив
    int size;       // Текущий размер
    int capacity;   // Вместимость

    void resize();  // Увеличение размера массива

public:
    Array();
    ~Array();

    // Основные операции
    void add(int value);            // Добавление в конец
    void insert(int index, int value); // Вставка по индексу
    int get(int index);             // Получение элемента
    void remove(int index);         // Удаление по индексу
    void change(int index, int value); // Замена элемента
    int length();                   // Длина массива
    void print();                   // Вывод массива
};

#endif
