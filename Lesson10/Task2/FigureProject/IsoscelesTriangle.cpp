#include "IsoscelesTriangle.h"
#include <iostream>

IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B)
    : Triangle(a, b, a, A, B, A) {}

void IsoscelesTriangle::print_info() const {
    std::cout << "�������������� �����������:\n";
    std::cout << "�������: a=" << a << " b=" << b << " c=" << a << "\n";
    std::cout << "����: A=" << A << " B=" << B << " C=" << A << "\n";
}
