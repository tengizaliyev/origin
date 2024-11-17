#include <iostream>
#include "SmartArray.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    try {
        SmartArray arr(5);  // —оздаЄм умный массив с Ємкостью 5
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);

        std::cout << "Ёлемент с индексом 1: " << arr.get_element(1) << std::endl;

        // ѕопробуем обратитьс€ к некорректному индексу (дл€ проверки исключений)
         std::cout << "Ёлемент с индексом 5: " << arr.get_element(5) << std::endl;

    }
    catch (const std::exception& ex) {
        std::cout << "ќшибка: " << ex.what() << std::endl;
    }

    return 0;
}
