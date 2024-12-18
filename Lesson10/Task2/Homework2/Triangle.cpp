#include "Triangle.h"
#include "InvalidFigureException.h"
#include <iostream>

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
    : a(a), b(b), c(c), A(A), B(B), C(C) {
    if (A + B + C != 180) {
        throw InvalidFigureException("Ошибка создания треугольника: сумма углов не равна 180.");
    }
}

void Triangle::print_info() const {
    std::cout << "Треугольник:\n";
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n";
}

// Геттеры
int Triangle::get_side_a() const { return a; }
int Triangle::get_side_b() const { return b; }
int Triangle::get_side_c() const { return c; }
int Triangle::get_angle_A() const { return A; }
int Triangle::get_angle_B() const { return B; }
int Triangle::get_angle_C() const { return C; }
