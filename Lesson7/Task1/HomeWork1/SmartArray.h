#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H

#include <stdexcept>

class SmartArray {
private:
    int* data;       // Указатель на массив данных
    int capacity;    // Максимальная ёмкость массива
    int size;        // Текущий размер массива

public:
    SmartArray(int capacity);    // Конструктор с указанием ёмкости
    ~SmartArray();               // Деструктор

    void add_element(int value); // Добавление элемента
    int get_element(int index) const; // Получение элемента по индексу
    int get_size() const;        // Получение текущего размера массива
};

#endif
