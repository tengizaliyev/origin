#ifndef SMART_ARRAY_H
#define SMART_ARRAY_H

#include <stdexcept>

class SmartArray {
private:
    int* data;       // ��������� �� ������ ������
    int capacity;    // ������������ ������� �������
    int size;        // ������� ������ �������

public:
    SmartArray(int capacity);    // ����������� � ��������� �������
    ~SmartArray();               // ����������

    void add_element(int value); // ���������� ��������
    int get_element(int index) const; // ��������� �������� �� �������
    int get_size() const;        // ��������� �������� ������� �������
};

#endif
