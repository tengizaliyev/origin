#include <iostream>
#include <windows.h> // Для SetConsoleCP и SetConsoleOutputCP

// Класс-счётчик
class Counter {
private:
    int count; // Текущее значение счётчика

public:
    // Конструктор по умолчанию (начальное значение 1)
    Counter() : count(1) {}

    // Конструктор с инициализацией начального значения
    Counter(int initial) : count(initial) {}

    // Метод увеличения счётчика
    void increment() {
        count++;
    }

    // Метод уменьшения счётчика
    void decrement() {
        count--;
    }

    // Метод получения текущего значения счётчика
    int getCount() const {
        return count;
    }
};

int main() {
    // Установка кодировки для корректного отображения русских символов
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string userInput;
    int initialCount;
    Counter counter;

    // Запрос у пользователя начального значения
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> userInput;

    // Если пользователь хочет указать начальное значение
    if (userInput == "да") {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> initialCount;
        counter = Counter(initialCount);
    }

    // Цикл обработки команд
    char command;
    while (true) {
        std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
        std::cin >> command;

        switch (command) {
        case '+':
            counter.increment();
            break;
        case '-':
            counter.decrement();
            break;
        case '=':
            std::cout << counter.getCount() << std::endl;
            break;
        case 'x':
            std::cout << "До свидания!\n";
            return 0;
        default:
            std::cout << "Неизвестная команда, попробуйте снова.\n";
            break;
        }
    }

    return 0;
}
