#include <iostream>
#include <string>
#include <windows.h>
#include "Counter.h"

int main() {
    SetConsoleOutputCP(1251);
    std::string input;
    int initial_value;
    bool custom_initial = false;

    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> input;

    if (input == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initial_value;
        custom_initial = true;
    }

    Counter counter(custom_initial ? initial_value : 1);

    while (true) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
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
            std::cout << "До свидания!" << std::endl;
            break;
        }
        else {
            std::cout << "Неверная команда. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}
