#include "RightTriangle.h"
#include "InvalidFigureException.h"
#include <iostream>

RightTriangle::RightTriangle(int a, int b, int c, int A, int B)
    : Triangle(a, b, c, A, B, 90) {
    if (A + B + 90 != 180) {
        throw InvalidFigureException("������: ����� ����� �������������� ������������ �� ����� 180.");
    }
}

void RightTriangle::print_info() const {
    std::cout << "������������� �����������:\n";
    std::cout << "�������: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << "\n";
    std::cout << "����: A=" << get_angle_A() << " B=" << get_angle_B() << " C=90\n";
}
