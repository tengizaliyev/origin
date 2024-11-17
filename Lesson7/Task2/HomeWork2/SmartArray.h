#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H

#include <stdexcept>

class SmartArray {
private:
    int* data;       // Указатель на массив данных
    int capacity;    // Максимальная ёмкость массива
    int size;        // Текущий размер массива

    void copy_from(const SmartArray& other); // Вспомогательный метод для копирования

public:
    SmartArray(int capacity);                // Конструктор с ёмкостью
    SmartArray(const SmartArray& other);     // Конструктор копирования
    SmartArray& operator=(const SmartArray& other); // Оператор присваивания
    ~SmartArray();                           // Деструктор

    void add_element(int value);             // Добавление элемента
    int get_element(int index) const;        // Получение элемента по индексу
    int get_size() const;                    // Получение текущего размера
};

#endif
