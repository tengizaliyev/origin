#include <iostream>
#include <windows.h> // Для SetConsoleOutputCP

// Определяем константу MODE
#define MODE 1

#ifndef MODE
#error "Необходимо определить MODE!"
#endif

#if MODE == 0
int main() {
    SetConsoleOutputCP(1251); 
    std::cout << "Работаю в режиме тренировки" << std::endl;
    return 0;
}
#elif MODE == 1
int add(int a, int b) {
    return a + b;
}

int main() {
    SetConsoleOutputCP(1251); 
    std::cout << "Работаю в боевом режиме" << std::endl;

    int num1, num2;
    std::cout << "Введите число 1: ";
    std::cin >> num1;
    std::cout << "Введите число 2: ";
    std::cin >> num2;

    int result = add(num1, num2);
    std::cout << "Результат сложения: " << result << std::endl;

    return 0;
}
#else
int main() {
    SetConsoleOutputCP(1251); 
    std::cout << "Неизвестный режим. Завершение работы" << std::endl;
    return 0;
}
#endif
