#include "Triangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Quadrilateral.h"
#include "myRectangle.h"
#include "Square.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(1251);
    Triangle triangle(10, 20, 30, 50, 60, 70);
    triangle.print_info();

    RightTriangle right_triangle(10, 20, 30, 50, 60);
    right_triangle.print_info();

    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    isosceles_triangle.print_info();

    EquilateralTriangle equilateral_triangle(30);
    equilateral_triangle.print_info();

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80);
    quadrilateral.print_info();

    myRectangle rectangle(10, 20);
    rectangle.print_info();

    Square square(20);
    square.print_info();

    return 0;
}
