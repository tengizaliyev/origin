#ifndef COUNTER_H
#define COUNTER_H

class Counter {
private:
    int count;

public:
    Counter(int initial = 1); // ����������� � ��������� ��������� �� ���������
    void increment();         // ��������� �������� �� 1
    void decrement();         // ��������� �������� �� 1
    int getValue() const;     // �������� ������� ��������
};

#endif
