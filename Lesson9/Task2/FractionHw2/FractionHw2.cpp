#include <iostream>
#include <numeric> // Для std::gcd
#include <windows.h>

class Fraction {
private:
    int numerator_;   // Числитель
    int denominator_; // Знаменатель

    // Сокращение дроби
    void reduce() {
        int gcd = std::gcd(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;
        if (denominator_ < 0) { // Знаменатель не должен быть отрицательным
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

public:
    // Конструктор
    Fraction(int numerator = 0, int denominator = 1)
        : numerator_(numerator), denominator_(denominator) {
        reduce();
    }

    // Перегрузка операторов сравнения
    bool operator==(const Fraction& other) const {
        return (numerator_ * other.denominator_) == (other.numerator_ * denominator_);
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return (numerator_ * other.denominator_) < (other.numerator_ * denominator_);
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    // Перегрузка арифметических операторов
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator_ * other.denominator_ + other.numerator_ * denominator_,
            denominator_ * other.denominator_);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_,
            denominator_ * other.denominator_);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
    }

    // Унарный минус
    Fraction operator-() const {
        return Fraction(-numerator_, denominator_);
    }

    // Префиксный инкремент
    Fraction& operator++() {
        numerator_ += denominator_;
        reduce();
        return *this;
    }

    // Постфиксный инкремент
    Fraction operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    // Префиксный декремент
    Fraction& operator--() {
        numerator_ -= denominator_;
        reduce();
        return *this;
    }

    // Постфиксный декремент
    Fraction operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    // Вывод дроби
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
        out << fraction.numerator_ << "/" << fraction.denominator_;
        return out;
    }

    // Ввод дроби
    friend std::istream& operator>>(std::istream& in, Fraction& fraction) {
        char slash;
        in >> fraction.numerator_ >> slash >> fraction.denominator_;
        fraction.reduce();
        return in;
    }
};

int main() {
    SetConsoleOutputCP(1251); // Устанавливаем кодировку для русского языка

    Fraction f1, f2;

    std::cout << "Введите числитель дроби 1: ";
    int num1, denom1;
    std::cin >> num1;
    std::cout << "Введите знаменатель дроби 1: ";
    std::cin >> denom1;
    f1 = Fraction(num1, denom1);

    std::cout << "Введите числитель дроби 2: ";
    int num2, denom2;
    std::cin >> num2;
    std::cout << "Введите знаменатель дроби 2: ";
    std::cin >> denom2;
    f2 = Fraction(num2, denom2);

    std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << '\n';
    std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << '\n';
    std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << '\n';
    std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << '\n';

    std::cout << "++" << f1 << " * " << f2 << " = " << (++f1 * f2) << '\n';
    std::cout << "Значение дроби 1 = " << f1 << '\n';

    std::cout << f1 << "-- * " << f2 << " = " << (f1-- * f2) << '\n';
    std::cout << "Значение дроби 1 = " << f1 << '\n';

    return 0;
}
