#include "SmartArray.h"
#include <algorithm> // ��� std::copy

// �����������
SmartArray::SmartArray(int capacity) : capacity(capacity), size(0) {
    if (capacity <= 0) {
        throw std::invalid_argument("������ ������� ������ ���� �������������");
    }
    data = new int[capacity];
}

// ����������� �����������
SmartArray::SmartArray(const SmartArray& other) {
    copy_from(other);
}

// �������� ������������
SmartArray& SmartArray::operator=(const SmartArray& other) {
    if (this != &other) { // ������ �� ����������������
        delete[] data;    // ����������� ������ ������
        copy_from(other); // �������� ������ �� ������� �������
    }
    return *this;
}

// ����������
SmartArray::~SmartArray() {
    delete[] data;
}

// ��������������� ����� ��� ����������� ������
void SmartArray::copy_from(const SmartArray& other) {
    capacity = other.capacity;
    size = other.size;
    data = new int[capacity];
    std::copy(other.data, other.data + size, data); // �������� ��������
}

// ����� ��� ���������� ��������
void SmartArray::add_element(int value) {
    if (size >= capacity) {
        throw std::out_of_range("��������� ������������ ���������� ��������� � �������");
    }
    data[size] = value;
    size++;
}

// ����� ��� ��������� �������� �� �������
int SmartArray::get_element(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("������������ ������");
    }
    return data[index];
}

// ����� ��� ��������� �������� ������� �������
int SmartArray::get_size() const {
    return size;
}
