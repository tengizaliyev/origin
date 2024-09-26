#include <iostream>
#include <windows.h> // Для использования SetConsoleCP и SetConsoleOutputCP

// Перечисление для месяцев
enum Months {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

int main() {
    // Установка кодировки для ввода и вывода русских символов
    SetConsoleCP(1251); // Ввод с консоли в кодировке 1251
    SetConsoleOutputCP(1251); // Вывод в консоли в кодировке 1251

    int monthNumber;

    while (true) {
        std::cout << "Введите номер месяца: ";
        std::cin >> monthNumber;

        // Проверка на завершение программы
        if (monthNumber == 0) {
            std::cout << "До свидания\n";
            break;
        }

        // Приведение к перечислению и обработка значений
        switch (static_cast<Months>(monthNumber)) {
        case January:
            std::cout << "Январь\n";
            break;
        case February:
            std::cout << "Февраль\n";
            break;
        case March:
            std::cout << "Март\n";
            break;
        case April:
            std::cout << "Апрель\n";
            break;
        case May:
            std::cout << "Май\n";
            break;
        case June:
            std::cout << "Июнь\n";
            break;
        case July:
            std::cout << "Июль\n";
            break;
        case August:
            std::cout << "Август\n";
            break;
        case September:
            std::cout << "Сентябрь\n";
            break;
        case October:
            std::cout << "Октябрь\n";
            break;
        case November:
            std::cout << "Ноябрь\n";
            break;
        case December:
            std::cout << "Декабрь\n";
            break;
        default:
            std::cout << "Неправильный номер!\n";
            break;
        }
    }

    return 0;
}
