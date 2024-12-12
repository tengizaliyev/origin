#include <iostream>
#include <windows.h>

class Fraction
{
private:
    int numerator_;   // Числитель
    int denominator_; // Знаменатель

    // Вспомогательная функция для приведения дробей к общему знаменателю
    static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

    // Вспомогательная функция для нахождения НОД (наибольший общий делитель)
    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    // Конструктор
    Fraction(int numerator, int denominator)
        : numerator_(numerator), denominator_(denominator) {}

    // Перегрузка оператора ==
    bool operator==(const Fraction& other) const {
        return (numerator_ * other.denominator_) == (other.numerator_ * denominator_);
    }

    // Перегрузка оператора !=
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    // Перегрузка оператора <
    bool operator<(const Fraction& other) const {
        return (numerator_ * other.denominator_) < (other.numerator_ * denominator_);
    }

    // Перегрузка оператора >
    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    // Перегрузка оператора <=
    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    // Перегрузка оператора >=
    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }
};

int main()
{
    SetConsoleOutputCP(1251); // Устанавливаем кодировку для русского языка

    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

    return 0;
}
