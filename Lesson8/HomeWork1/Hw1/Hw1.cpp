#include <iostream>
#include <windows.h> // ��� SetConsoleOutputCP

// ���������� ��������� MODE
#define MODE 1

#ifndef MODE
#error "���������� ���������� MODE!"
#endif

#if MODE == 0
int main() {
    SetConsoleOutputCP(1251); 
    std::cout << "������� � ������ ����������" << std::endl;
    return 0;
}
#elif MODE == 1
int add(int a, int b) {
    return a + b;
}

int main() {
    SetConsoleOutputCP(1251); 
    std::cout << "������� � ������ ������" << std::endl;

    int num1, num2;
    std::cout << "������� ����� 1: ";
    std::cin >> num1;
    std::cout << "������� ����� 2: ";
    std::cin >> num2;

    int result = add(num1, num2);
    std::cout << "��������� ��������: " << result << std::endl;

    return 0;
}
#else
int main() {
    SetConsoleOutputCP(1251); 
    std::cout << "����������� �����. ���������� ������" << std::endl;
    return 0;
}
#endif
