#include "EquilateralTriangle.h"
#include "InvalidFigureException.h"
#include <iostream>

EquilateralTriangle::EquilateralTriangle(int side)
    : Triangle(side, side, side, 60, 60, 60) {}

void EquilateralTriangle::print_info() const {
    std::cout << "Равносторонний треугольник:\n";
    std::cout << "Стороны: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << "\n";
    std::cout << "Углы: A=60 B=60 C=60\n";
}
