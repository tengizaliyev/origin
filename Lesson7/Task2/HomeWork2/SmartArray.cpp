#include "SmartArray.h"
#include <algorithm> // Для std::copy

// Конструктор
SmartArray::SmartArray(int capacity) : capacity(capacity), size(0) {
    if (capacity <= 0) {
        throw std::invalid_argument("Размер массива должен быть положительным");
    }
    data = new int[capacity];
}

// Конструктор копирования
SmartArray::SmartArray(const SmartArray& other) {
    copy_from(other);
}

// Оператор присваивания
SmartArray& SmartArray::operator=(const SmartArray& other) {
    if (this != &other) { // Защита от самоприсваивания
        delete[] data;    // Освобождаем старую память
        copy_from(other); // Копируем данные из другого объекта
    }
    return *this;
}

// Деструктор
SmartArray::~SmartArray() {
    delete[] data;
}

// Вспомогательный метод для копирования данных
void SmartArray::copy_from(const SmartArray& other) {
    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];
    std::copy(other.data, other.data + size, data); // Копируем элементы
}

// Метод для добавления элемента
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
