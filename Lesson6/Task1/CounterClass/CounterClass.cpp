#include <iostream>
#include <string>
#include <windows.h>
#include "Counter.h"

int main() {
    SetConsoleOutputCP(1251);
    std::string input;
    int initial_value;
    bool custom_initial = false;

    std::cout << "�� ������ ������� ��������� �������� ��������? ������� �� ��� ���: ";
    std::cin >> input;

    if (input == "��") {
        std::cout << "������� ��������� �������� ��������: ";
        std::cin >> initial_value;
        custom_initial = true;
    }

    Counter counter(custom_initial ? initial_value : 1);

    while (true) {
        std::cout << "������� ������� ('+', '-', '=' ��� 'x'): ";
        std::cin >> input;

        if (input == "+") {
            counter.increment();
        }
        else if (input == "-") {
            counter.decrement();
        }
        else if (input == "=") {
            std::cout << counter.getValue() << std::endl;
        }
        else if (input == "x") {
            std::cout << "�� ��������!" << std::endl;
            break;
        }
        else {
            std::cout << "�������� �������. ���������� �����." << std::endl;
        }
    }

    return 0;
}
