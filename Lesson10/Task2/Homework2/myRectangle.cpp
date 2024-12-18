#include "myRectangle.h"
#include <iostream>

myRectangle::myRectangle(int a, int b)
    : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {}

void myRectangle::print_info() const {
    std::cout << "Прямоугольник:\n";
    std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b()
        << " c=" << get_side_c() << " d=" << get_side_d() << "\n";
    std::cout << "Углы: A=90 B=90 C=90 D=90\n";
}
