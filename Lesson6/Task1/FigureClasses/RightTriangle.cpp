#include "RightTriangle.h"
#include <iostream>

RightTriangle::RightTriangle(int a, int b, int c, int A, int B)
    : Triangle(a, b, c, A, B, 90) {}

void RightTriangle::print_info() const {
    std::cout << "Прямоугольный треугольник:\n";
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
    std::cout << "Углы: A=" << A << " B=" << B << " C=90\n";
}
