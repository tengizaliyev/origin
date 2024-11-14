// main.cpp
#include <iostream>
#include <windows.h>
#include "math_functions.h"

int main() {
    SetConsoleOutputCP(1251);
    double num1, num2;
    int operation;

    std::cout << "¬ведите первое число: ";
    std::cin >> num1;
    std::cout << "¬ведите второе число: ";
    std::cin >> num2;

    std::cout << "¬ыберите операцию (1 - сложение, 2 - вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
    std::cin >> operation;

    try {
        double result;
        switch (operation) {
        case 1:
            result = add(num1, num2);
            std::cout << num1 << " + " << num2 << " = " << result << std::endl;
            break;
        case 2:
            result = subtract(num1, num2);
            std::cout << num1 << " - " << num2 << " = " << result << std::endl;
            break;
        case 3:
            result = multiply(num1, num2);
            std::cout << num1 << " * " << num2 << " = " << result << std::endl;
            break;
        case 4:
            result = divide(num1, num2);
            std::cout << num1 << " / " << num2 << " = " << result << std::endl;
            break;
        case 5:
            result = power(num1, static_cast<int>(num2));
            std::cout << num1 << " в степени " << static_cast<int>(num2) << " = " << result << std::endl;
            break;
        default:
            std::cout << "Ќеверна€ операци€." << std::endl;
            break;
        }
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
