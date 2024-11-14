#include "Square.h"
#include <iostream>

Square::Square(int side) : myRectangle(side, side) {}

void Square::print_info() const {
    std::cout << "�������:\n";
    std::cout << "�������: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
    std::cout << "����: A=90 B=90 C=90 D=90\n";
}
