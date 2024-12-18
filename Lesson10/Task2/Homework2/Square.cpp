#include "Square.h"
#include <iostream>

Square::Square(int side) : myRectangle(side, side) {}

void Square::print_info() const {
    std::cout << "Квадрат:\n";
    std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b()
        << " c=" << get_side_c() << " d=" << get_side_d() << "\n";
    std::cout << "Углы: A=90 B=90 C=90 D=90\n";
}
