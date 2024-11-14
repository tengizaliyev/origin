#ifndef COUNTER_H
#define COUNTER_H

class Counter {
private:
    int count;

public:
    Counter(int initial = 1); // Конструктор с начальным значением по умолчанию
    void increment();         // Увеличить значение на 1
    void decrement();         // Уменьшить значение на 1
    int getValue() const;     // Получить текущее значение
};

#endif
