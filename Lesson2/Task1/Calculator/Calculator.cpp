#include <iostream>
#include <windows.h> // Для SetConsoleCP и SetConsoleOutputCP

// Класс для выполнения арифметических операций
class Calculator {
private:
    double num1;
    double num2;

public:
    // Методы для установки значений num1 и num2
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

    // Метод сложения
    double add() {
        return num1 + num2;
    }

    // Метод умножения
    double multiply() {
        return num1 * num2;
    }

    // Метод вычитания num2 из num1
    double subtract_1_2() {
        return num1 - num2;
    }

    // Метод вычитания num1 из num2
    double subtract_2_1() {
        return num2 - num1;
    }

    // Метод деления num1 на num2
    double divide_1_2() {
        return num1 / num2;
    }

    // Метод деления num2 на num1
    double divide_2_1() {
        return num2 / num1;
    }
};

int main() {
    // Установка кодировки для корректного отображения русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Calculator calc;
    double input1, input2;

    while (true) {
        // Ввод первого числа
        std::cout << "Введите num1: ";
        std::cin >> input1;

        // Проверка ввода
        if (!calc.set_num1(input1)) {
            std::cout << "Неверный ввод! num1 не должен быть равен 0.\n";
            continue; // Просим ввести снова
        }

        // Ввод второго числа
        std::cout << "Введите num2: ";
        std::cin >> input2;

        // Проверка ввода
        if (!calc.set_num2(input2)) {
            std::cout << "Неверный ввод! num2 не должен быть равен 0.\n";
            continue; // Просим ввести снова
        }

        // Вывод результатов арифметических операций
        std::cout << "num1 + num2 = " << calc.add() << std::endl;
        std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
        std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
        std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
        std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
        std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
    }

    return 0;
}
