#include <iostream>
#include <string>
#include <windows.h>

// Определение собственного исключения
class bad_length : public std::exception {
public:
    const char* what() const noexcept override {
        return "Вы ввели слово запретной длины!";
    }
};

// Функция для проверки длины строки
int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw bad_length(); // Выбрасываем исключение, если длина строки совпадает с запретной
    }
    return str.length();
}

int main() {
    SetConsoleOutputCP(1251); // Устанавливаем кодировку для русского языка
    SetConsoleCP(1251);

    int forbidden_length;
    std::string input;

    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;
    std::cin.ignore(); // Очистка буфера после ввода числа

    try {
        while (true) {
            std::cout << "Введите слово: ";
            std::getline(std::cin, input);

            int length = function(input, forbidden_length);
            std::cout << "Длина слова \"" << input << "\" равна " << length << std::endl;
        }
    }
    catch (const bad_length& e) {
        std::cout << e.what() << std::endl;
        std::cout << "До свидания!" << std::endl;
    }

    return 0;
}
