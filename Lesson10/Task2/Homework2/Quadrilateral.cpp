#include "Quadrilateral.h"
#include "InvalidFigureException.h"
#include <iostream>

Quadrilateral::Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
    : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
    if (A + B + C + D != 360) {
        throw InvalidFigureException("Ошибка создания четырехугольника: сумма углов не равна 360.");
    }
}

void Quadrilateral::print_info() const {
    std::cout << "Четырёхугольник:\n";
    std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
    std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
}

// Геттеры
int Quadrilateral::get_side_a() const { return a; }
int Quadrilateral::get_side_b() const { return b; }
int Quadrilateral::get_side_c() const { return c; }
int Quadrilateral::get_side_d() const { return d; }
int Quadrilateral::get_angle_A() const { return A; }
int Quadrilateral::get_angle_B() const { return B; }
int Quadrilateral::get_angle_C() const { return C; }
int Quadrilateral::get_angle_D() const { return D; }
