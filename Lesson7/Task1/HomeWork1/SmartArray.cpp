#include "SmartArray.h"

// Конструктор
SmartArray::SmartArray(int capacity) : capacity(capacity), size(0) {
    if (capacity <= 0) {
        throw std::invalid_argument("Размер массива должен быть положительным");
    }
    data = new int[capacity];
}

// Деструктор
SmartArray::~SmartArray() {
    delete[] data;
}

// Метод для добавления нового элемента в массив
void SmartArray::add_element(int value) {
    if (size >= capacity) {
        throw std::out_of_range("Превышено максимальное количество элементов в массиве");
    }
    data[size] = value;
    size++;
}

// Метод для получения элемента по индексу
int SmartArray::get_element(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Некорректный индекс");
    }
    return data[index];
}

// Метод для получения текущего размера массива
int SmartArray::get_size() const {
    return size;
}
