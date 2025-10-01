#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "array/array.h"
#include "linked_list/linked_list.h"
#include "doubly_linked_list/doubly_linked_list.h"
#include "stack/stack.h"
#include "queue/queue.h"
#include "complete_binary_tree/complete_binary_tree.h"
using namespace std;

// Глобальные структуры данных
Array arr;
LinkedList fList;
DoublyLinkedList lList;
Stack sStack;
Queue qQueue;
CompleteBinaryTree tTree;

// Функции для работы с файлами
void saveToFile(const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    file << "ARRAY ";
    for (int i = 0; i < arr.length(); i++) {
        file << arr.get(i) << " ";
    }
    file << endl;

    file.close();
    cout << "Данные сохранены в " << filename << endl;
}

void loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла для чтения!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "ARRAY") {
            int value;
            while (ss >> value) {
                arr.add(value);
            }
        }
    }

    file.close();
    cout << "Данные загружены из " << filename << endl;
}

void arrayMenu() {
    int choice, value, index;

    while (true) {
        cout << "\n=== МАССИВ ===" << endl;
        cout << "1. MPUSH - Добавить число" << endl;
        cout << "2. MINSERT - Вставить по индексу" << endl;
        cout << "3. MGET - Получить элемент" << endl;
        cout << "4. MDEL - Удалить по индексу" << endl;
        cout << "5. MCHANGE - Заменить элемент" << endl;
        cout << "6. MLEN - Длина массива" << endl;
        cout << "7. PRINT M - Вывести массив" << endl;
        cout << "8. Сохранить в файл" << endl;
        cout << "9. Загрузить из файла" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите операцию: ";
        cin >> choice;
switch (choice) {
            case 1:
                cout << "Введите число: ";
                cin >> value;
                arr.add(value);
                cout << "MPUSH выполнено" << endl;
                break;
            case 2:
                cout << "Введите индекс: ";
                cin >> index;
                cout << "Введите число: ";
                cin >> value;
                arr.insert(index, value);
                cout << "MINSERT выполнено" << endl;
                break;
            case 3:
                cout << "Введите индекс: ";
                cin >> index;
                value = arr.get(index);
                if (value != -1) {
                    cout << "MGET: " << value << endl;
                } else {
                    cout << "Неверный индекс!" << endl;
                }
                break;
            case 4:
                cout << "Введите индекс: ";
                cin >> index;
                arr.remove(index);
                cout << "MDEL выполнено" << endl;
                break;
            case 5:
                cout << "Введите индекс: ";
                cin >> index;
                cout << "Введите новое значение: ";
                cin >> value;
                arr.change(index, value);
                cout << "MCHANGE выполнено" << endl;
                break;
            case 6:
                cout << "MLEN: " << arr.length() << endl;
                break;
            case 7:
                cout << "PRINT M: ";
                arr.print();
                break;
            case 8: {
                string filename;
                cout << "Введите имя файла: ";
                cin >> filename;
                saveToFile(filename);
                break;
            }
            case 9: {
                string filename;
                cout << "Введите имя файла: ";
                cin >> filename;
                loadFromFile(filename);
                break;
            }
            case 0:
                return;
            default:
                cout << "Неверный выбор!" << endl;
        }
    }
}

void linkedListMenu() {
    int choice, value;

    while (true) {
        cout << "\n=== ОДНОСВЯЗНЫЙ СПИСОК ===" << endl;
        cout << "1. FPUSH_HEAD - Добавить в начало" << endl;
        cout << "2. FPUSH_TAIL - Добавить в конец" << endl;
        cout << "3. FDEL_HEAD - Удалить из начала" << endl;
        cout << "4. FDEL_TAIL - Удалить из конца" << endl;
        cout << "5. FSEARCH - Поиск по значению" << endl;
        cout << "6. FDEL_VALUE - Удалить по значению" << endl;
        cout << "7. PRINT F - Вывести список" << endl;
        cout << "8. Сохранить в файл" << endl;
        cout << "9. Загрузить из файла" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите операцию: ";
        cin >> choice;
switch (choice) {
            case 1:
                cout << "Введите число: ";
                cin >> value;
                fList.addFirst(value);
                cout << "FPUSH_HEAD выполнено" << endl;
                break;
            case 2:
                cout << "Введите число: ";
                cin >> value;
                fList.addLast(value);
                cout << "FPUSH_TAIL выполнено" << endl;
                break;
            case 3:
                fList.removeFirst();
                cout << "FDEL_HEAD выполнено" << endl;
                break;
            case 4:
                fList.removeLast();
                cout << "FDEL_TAIL выполнено" << endl;
                break;
            case 5:
                cout << "Введите число для поиска: ";
                cin >> value;
                if (fList.find(value)) {
                    cout << "FSEARCH: Элемент найден" << endl;
                } else {
                    cout << "FSEARCH: Элемент не найден" << endl;
                }
                break;
            case 6:
                cout << "Введите число для удаления: ";
                cin >> value;
                fList.removeValue(value);
                cout << "FDEL_VALUE выполнено" << endl;
                break;
            case 7:
                cout << "PRINT F: ";
                fList.print();
                break;
            case 8: {
                string filename;
                cout << "Введите имя файла: ";
                cin >> filename;
                saveToFile(filename);
                break;
            }
            case 9: {
                string filename;
                cout << "Введите имя файла: ";
                cin >> filename;
                loadFromFile(filename);
                break;
            }
            case 0:
                return;
            default:
                cout << "Неверный выбор!" << endl;
        }
    }
}

void stackMenu() {
    int choice, value;

    while (true) {
        cout << "\n=== СТЕК ===" << endl;
        cout << "1. SPUSH - Добавить" << endl;
        cout << "2. SPOP - Удалить" << endl;
        cout << "3. STOP - Посмотреть верхний" << endl;
        cout << "4. SISEMPTY - Проверить пустоту" << endl;
        cout << "5. PRINT S - Вывести стек" << endl;
        cout << "6. Сохранить в файл" << endl;
        cout << "7. Загрузить из файла" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Введите число: ";
                cin >> value;
                sStack.push(value);
                cout << "SPUSH выполнено" << endl;
                break;
            case 2:
                sStack.pop();
                cout << "SPOP выполнено" << endl;
                break;
            case 3:
                value = sStack.top();
                if (value != -1) {
                    cout << "STOP: " << value << endl;
                } else {
                    cout << "Стек пуст!" << endl;
                }
                break;
            case 4:
                if (sStack.isEmpty()) {
                    cout << "SISEMPTY: true" << endl;
                } else {
                    cout << "SISEMPTY: false" << endl;
                }
                break;
            case 5:
                cout << "PRINT S: ";
                sStack.print();
                break;
            case 6: {
                string filename;
                cout << "Введите имя файла: ";
                cin >> filename;
                saveToFile(filename);
                break;
            }
            case 7: {
                string filename;
                cout << "Введите имя файла: ";
                cin >> filename;
                loadFromFile(filename);
                break;
            }
            case 0:
                return;
            default:
                cout << "Неверный выбор!" << endl;
        }
    }
}

void queueMenu() {
    int choice, value;
while (true) {
        cout << "\n=== ОЧЕРЕДЬ ===" << endl;
        cout << "1. QPUSH - Добавить" << endl;
        cout << "2. QPOP - Удалить" << endl;
        cout << "3. QPEEK - Посмотреть первый" << endl;
        cout << "4. QISEMPTY - Проверить пустоту" << endl;
        cout << "5. PRINT Q - Вывести очередь" << endl;
        cout << "6. Сохранить в файл" << endl;
        cout << "7. Загрузить из файла" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Введите число: ";
                cin >> value;
                qQueue.push(value);
                cout << "QPUSH выполнено" << endl;
                break;
            case 2:
                qQueue.pop();
                cout << "QPOP выполнено" << endl;
                break;
            case 3:
                value = qQueue.peek();
                if (value != -1) {
                    cout << "QPEEK: " << value << endl;
                } else {
                    cout << "Очередь пуста!" << endl;
                }
                break;
            case 4:
                if (qQueue.isEmpty()) {
                    cout << "QISEMPTY: true" << endl;
                } else {
                    cout << "QISEMPTY: false" << endl;
                }
                break;
            case 5:
                cout << "PRINT Q: ";
                qQueue.print();
                break;
            case 6: {
                string filename;
                cout << "Введите имя файла: ";
                cin >> filename;
                saveToFile(filename);
                break;
            }
            case 7: {
                string filename;
                cout << "Введите имя файла: ";
                cin >> filename;
                loadFromFile(filename);
                break;
            }
            case 0:
                return;
            default:
                cout << "Неверный выбор!" << endl;
        }
    }
}

void treeMenu() {
    int choice, value;

    while (true) {
        cout << "\n=== COMPLETE BINARY TREE ===" << endl;
        cout << "1. TINSERT - Добавить узел" << endl;
        cout << "2. TSEARCH - Поиск узла" << endl;
        cout << "3. TDEL - Удалить узел" << endl;
        cout << "4. PRINT T LEVEL - Обход в ширину" << endl;
        cout << "5. PRINT T DEPTH - Обходы в глубину" << endl;
        cout << "6. TISEMPTY - Проверить пустоту" << endl;
        cout << "7. TCLEAR - Очистить дерево" << endl;
        cout << "8. Сохранить в файл" << endl;
        cout << "9. Загрузить из файла" << endl;
        cout << "0. Назад" << endl;
        cout << "Выберите операцию: ";
        cin >> choice;
switch (choice) {
            case 1:
                cout << "Введите число: ";
                cin >> value;
                tTree.addNode(value);
                cout << "TINSERT выполнено" << endl;
                break;
            case 2:
                cout << "Введите число для поиска: ";
                cin >> value;
                if (tTree.searchNode(value)) {
                    cout << "TSEARCH: Элемент найден" << endl;
                } else {
                    cout << "TSEARCH: Элемент не найден" << endl;
                }
                break;
            case 3:
                cout << "Введите число для удаления: ";
                cin >> value;
                tTree.removeNode(value);
                cout << "TDEL выполнено" << endl;
                break;
            case 4:
                cout << "PRINT T LEVEL: ";
                tTree.levelOrder();
                break;
            case 5:
                cout << "PRINT T DEPTH: " << endl;
                tTree.depthFirstTraversals();
                break;
            case 6:
                if (tTree.isEmpty()) {
                    cout << "TISEMPTY: true" << endl;
                } else {
                    cout << "TISEMPTY: false" << endl;
                }
                break;
            case 7:
                tTree.clear();
                cout << "TCLEAR выполнено" << endl;
                break;
            case 8: {
                string filename;
                cout << "Введите имя файла: ";
                cin >> filename;
                saveToFile(filename);
                break;
            }
            case 9: {
                string filename;
                cout << "Введите имя файла: ";
                cin >> filename;
                loadFromFile(filename);
                break;
            }
            case 0:
                return;
            default:
                cout << "Неверный выбор!" << endl;
        }
    }
}

int main() {
    int mainChoice;
    
    while (true) {
        cout << "\n=== СТРУКТУРЫ ДАННЫХ ===" << endl;
        cout << "1. Массив (M)" << endl;
        cout << "2. Односвязный список (F)" << endl;
        cout << "3. Двусвязный список (L)" << endl;
        cout << "4. Стек (S)" << endl;
        cout << "5. Очередь (Q)" << endl;
        cout << "6. Complete Binary Tree (T)" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите режим: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: 
                arrayMenu(); 
                break;
            case 2: 
                linkedListMenu(); 
                break;
            case 3: 
                // doublyLinkedListMenu(); 
                cout << "Двусвязный список временно отключен" << endl;
                break;
            case 4: 
                stackMenu(); 
                break;
            case 5: 
                queueMenu(); 
                break;
            case 6: 
                treeMenu(); 
                break;
            case 0: 
                cout << "Выход..." << endl;
                return 0;
            default: 
                cout << "Неверный выбор!" << endl;
        }
    }
    
    return 0;
}
