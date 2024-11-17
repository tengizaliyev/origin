#include <iostream>
#include "SmartArray.h"
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1251);
    try {
        SmartArray arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        std::cout << "Исходный массив:\n";
        for (int i = 0; i < arr.get_size(); ++i) {
            std::cout << arr.get_element(i) << " ";
        }
        std::cout << "\n";

        SmartArray new_array(2);
        new_array.add_element(44);
        new_array.add_element(24);

        std::cout << "Другой массив до присваивания:\n";
        for (int i = 0; i < new_array.get_size(); ++i) {
            std::cout << new_array.get_element(i) << " ";
        }
        std::cout << "\n";

        arr = new_array; // Присваиваем один массив другому

        std::cout << "Исходный массив после присваивания:\n";
        for (int i = 0; i < arr.get_size(); ++i) {
            std::cout << arr.get_element(i) << " ";
        }
        std::cout << "\n";

    }
    catch (const std::exception& ex) {
        std::cout << "Ошибка: " << ex.what() << std::endl;
    }

    return 0;
}
