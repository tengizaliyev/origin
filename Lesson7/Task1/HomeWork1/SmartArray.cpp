#include "SmartArray.h"

// �����������
SmartArray::SmartArray(int capacity) : capacity(capacity), size(0) {
    if (capacity <= 0) {
        throw std::invalid_argument("������ ������� ������ ���� �������������");
    }
    data = new int[capacity];
}

// ����������
SmartArray::~SmartArray() {
    delete[] data;
}

// ����� ��� ���������� ������ �������� � ������
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
