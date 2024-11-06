#include <iostream>
#include <windows.h> // ��� SetConsoleCP � SetConsoleOutputCP

// ����� ��� ���������� �������������� ��������
class Calculator {
private:
    double num1;
    double num2;

public:
    // ������ ��� ��������� �������� num1 � num2
    bool set_num1(double num1) {
        if (num1 != 0) {
            this->num1 = num1;
            return true;
        }
        return false;
    }

    bool set_num2(double num2) {
        if (num2 != 0) {
            this->num2 = num2;
            return true;
        }
        return false;
    }

    // ����� ��������
    double add() {
        return num1 + num2;
    }

    // ����� ���������
    double multiply() {
        return num1 * num2;
    }

    // ����� ��������� num2 �� num1
    double subtract_1_2() {
        return num1 - num2;
    }

    // ����� ��������� num1 �� num2
    double subtract_2_1() {
        return num2 - num1;
    }

    // ����� ������� num1 �� num2
    double divide_1_2() {
        return num1 / num2;
    }

    // ����� ������� num2 �� num1
    double divide_2_1() {
        return num2 / num1;
    }
};

int main() {
    // ��������� ��������� ��� ����������� ����������� ������� ��������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Calculator calc;
    double input1, input2;

    while (true) {
        // ���� ������� �����
        std::cout << "������� num1: ";
        std::cin >> input1;

        // �������� �����
        if (!calc.set_num1(input1)) {
            std::cout << "�������� ����! num1 �� ������ ���� ����� 0.\n";
            continue; // ������ ������ �����
        }

        // ���� ������� �����
        std::cout << "������� num2: ";
        std::cin >> input2;

        // �������� �����
        if (!calc.set_num2(input2)) {
            std::cout << "�������� ����! num2 �� ������ ���� ����� 0.\n";
            continue; // ������ ������ �����
        }

        // ����� ����������� �������������� ��������
        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }

    return 0;
}
