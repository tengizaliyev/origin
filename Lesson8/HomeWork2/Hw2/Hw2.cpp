#include <iostream>

// ���������� ������ SUB
#define SUB(x, y) ((x) - (y))

int main(int argc, char** argv) {
    int a = 6;
    int b = 5;
    int c = 2;

    // ���������� ������ SUB
    std::cout << SUB(a, b) << std::endl;          // ��������� ���������: 1
    std::cout << SUB(a, b) * c << std::endl;      // ��������� ���������: 2
    std::cout << SUB(a, b + c) * c << std::endl;  // ��������� ���������: -2

    return 0;
}
