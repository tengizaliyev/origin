#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrilateral.h"
#include "myRectangle.h"
#include "Square.h"
#include "InvalidFigureException.h"
#include <windows.h>
#include <iostream>

int main() {
    SetConsoleOutputCP(1251);

    try {
        std::cout << "������ ����������� (10, 20, 30; ���� 50, 60, 70):\n";
        Triangle triangle(10, 20, 30, 50, 60, 70);
        triangle.print_info();
    }
    catch (const InvalidFigureException& e) {
        std::cout << e.what() << "\n";
    }

    try {
        std::cout << "\n������ ������������� ����������� (10, 20, 30; ���� 50, 60, 90):\n";
        RightTriangle right_triangle(10, 20, 30, 50, 60);
        right_triangle.print_info();
    }
    catch (const InvalidFigureException& e) {
        std::cout << e.what() << "\n";
    }

    try {
        std::cout << "\n������ �������������� ����������� (10, 20; ���� 50, 60):\n";
        IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
        isosceles_triangle.print_info();
    }
    catch (const InvalidFigureException& e) {
        std::cout << e.what() << "\n";
    }

    try {
        std::cout << "\n������ �������������� ����������� (������� 30):\n";
        EquilateralTriangle equilateral_triangle(30);
        equilateral_triangle.print_info();
    }
    catch (const InvalidFigureException& e) {
        std::cout << e.what() << "\n";
    }

    try {
        std::cout << "\n������ �������������� (10, 20, 30, 40; ���� 50, 60, 70, 80):\n";
        Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
        quadrilateral.print_info();
    }
    catch (const InvalidFigureException& e) {
        std::cout << e.what() << "\n";
    }

    try {
        std::cout << "\n������ ������������� (10, 20):\n";
        myRectangle rectangle(10, 20);
        rectangle.print_info();
    }
    catch (const InvalidFigureException& e) {
        std::cout << e.what() << "\n";
    }

    try {
        std::cout << "\n������ ������� (������� 20):\n";
        Square square(20);
        square.print_info();
    }
    catch (const InvalidFigureException& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}
