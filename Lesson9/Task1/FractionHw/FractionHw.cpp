#include <iostream>
#include <windows.h>

class Fraction
{
private:
    int numerator_;   // ���������
    int denominator_; // �����������

    // ��������������� ������� ��� ���������� ������ � ������ �����������
    static int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

    // ��������������� ������� ��� ���������� ��� (���������� ����� ��������)
    static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    // �����������
    Fraction(int numerator, int denominator)
        : numerator_(numerator), denominator_(denominator) {}

    // ���������� ��������� ==
    bool operator==(const Fraction& other) const {
        return (numerator_ * other.denominator_) == (other.numerator_ * denominator_);
    }

    // ���������� ��������� !=
    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    // ���������� ��������� <
    bool operator<(const Fraction& other) const {
        return (numerator_ * other.denominator_) < (other.numerator_ * denominator_);
    }

    // ���������� ��������� >
    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    // ���������� ��������� <=
    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    // ���������� ��������� >=
    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }
};

int main()
{
    SetConsoleOutputCP(1251); // ������������� ��������� ��� �������� �����

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
