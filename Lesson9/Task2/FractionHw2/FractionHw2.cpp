#include <iostream>
#include <numeric> // ��� std::gcd
#include <windows.h>

class Fraction {
private:
    int numerator_;   // ���������
    int denominator_; // �����������

    // ���������� �����
    void reduce() {
        int gcd = std::gcd(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;
        if (denominator_ < 0) { // ����������� �� ������ ���� �������������
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

public:
    // �����������
    Fraction(int numerator = 0, int denominator = 1)
        : numerator_(numerator), denominator_(denominator) {
        reduce();
    }

    // ���������� ���������� ���������
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

    // ���������� �������������� ����������
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

    // ������� �����
    Fraction operator-() const {
        return Fraction(-numerator_, denominator_);
    }

    // ���������� ���������
    Fraction& operator++() {
        numerator_ += denominator_;
        reduce();
        return *this;
    }

    // ����������� ���������
    Fraction operator++(int) {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    // ���������� ���������
    Fraction& operator--() {
        numerator_ -= denominator_;
        reduce();
        return *this;
    }

    // ����������� ���������
    Fraction operator--(int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    // ����� �����
    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
        out << fraction.numerator_ << "/" << fraction.denominator_;
        return out;
    }

    // ���� �����
    friend std::istream& operator>>(std::istream& in, Fraction& fraction) {
        char slash;
        in >> fraction.numerator_ >> slash >> fraction.denominator_;
        fraction.reduce();
        return in;
    }
};

int main() {
    SetConsoleOutputCP(1251); // ������������� ��������� ��� �������� �����

    Fraction f1, f2;

    std::cout << "������� ��������� ����� 1: ";
    int num1, denom1;
    std::cin >> num1;
    std::cout << "������� ����������� ����� 1: ";
    std::cin >> denom1;
    f1 = Fraction(num1, denom1);

    std::cout << "������� ��������� ����� 2: ";
    int num2, denom2;
    std::cin >> num2;
    std::cout << "������� ����������� ����� 2: ";
    std::cin >> denom2;
    f2 = Fraction(num2, denom2);

    std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << '\n';
    std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << '\n';
    std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << '\n';
    std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << '\n';

    std::cout << "++" << f1 << " * " << f2 << " = " << (++f1 * f2) << '\n';
    std::cout << "�������� ����� 1 = " << f1 << '\n';

    std::cout << f1 << "-- * " << f2 << " = " << (f1-- * f2) << '\n';
    std::cout << "�������� ����� 1 = " << f1 << '\n';

    return 0;
}
