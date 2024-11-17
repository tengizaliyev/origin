#include <iostream>
#include "SmartArray.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    try {
        SmartArray arr(5);  // ������ ����� ������ � �������� 5
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);

        std::cout << "������� � �������� 1: " << arr.get_element(1) << std::endl;

        // ��������� ���������� � ������������� ������� (��� �������� ����������)
         std::cout << "������� � �������� 5: " << arr.get_element(5) << std::endl;

    }
    catch (const std::exception& ex) {
        std::cout << "������: " << ex.what() << std::endl;
    }

    return 0;
}
