#include "IsoscelesTriangle.h"
#include <iostream>

IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B)
    : Triangle(a, b, a, A, B, A) {}

void IsoscelesTriangle::print_info() const {
    std::cout << "Равнобедренный треугольник:\n";
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << a << "\n";
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << A << "\n";
}
