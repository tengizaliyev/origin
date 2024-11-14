#include "Quadrilateral.h"
#include <iostream>

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
    : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

void Quadrilateral::print_info() const {
    std::cout << "��������������:\n";
    std::cout << "�������: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
    std::cout << "����: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
}
