#include "IsoscelesTriangle.h"
#include "InvalidFigureException.h"
#include <iostream>

IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B)
    : Triangle(a, b, a, A, B, A) {
    if (A + B + A != 180) {
        throw InvalidFigureException("������: ����� ����� ��������������� ������������ �� ����� 180.");
    }
}

void IsoscelesTriangle::print_info() const {
    std::cout << "�������������� �����������:\n";
    std::cout << "�������: a=" << get_side_a() << " b=" << get_side_b() << " c=" << get_side_c() << "\n";
    std::cout << "����: A=" << get_angle_A() << " B=" << get_angle_B() << " C=" << get_angle_C() << "\n";
}
