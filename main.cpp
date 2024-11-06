#include <iostream>
#include <windows.h>
using namespace std;

// Базовый класс фигуры
class Shape {
public:
    virtual void print_info() const = 0; // Чисто виртуальный метод для вывода информации
};

// Класс треугольник
class Triangle : public Shape {
protected:
    int a, b, c;   // Длины сторон
    int A, B, C;   // Углы

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {}

    void print_info() const override {
        cout << "Треугольник:\nСтороны: a=" << a << " b=" << b << " c=" << c;
        cout << "\nУглы: A=" << A << " B=" << B << " C=" << C << endl;
    }
};

// Прямоугольный треугольник
class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {}

    void print_info() const override {
        cout << "Прямоугольный треугольник:\nСтороны: a=" << a << " b=" << b << " c=" << c;
        cout << "\nУглы: A=" << A << " B=" << B << " C=90" << endl;
    }
};

// Равнобедренный треугольник
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A) {}

    void print_info() const override {
        cout << "Равнобедренный треугольник:\nСтороны: a=" << a << " b=" << b << " c=" << a;
        cout << "\nУглы: A=" << A << " B=" << B << " C=" << A << endl;
    }
};

// Равносторонний треугольник
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side)
        : Triangle(side, side, side, 60, 60, 60) {}

    void print_info() const override {
        cout << "Равносторонний треугольник:\nСтороны: a=" << a << " b=" << b << " c=" << c;
        cout << "\nУглы: A=60 B=60 C=60" << endl;
    }
};

// Класс четырехугольник
class Quadrilateral : public Shape {
protected:
    int a, b, c, d; // Длины сторон
    int A, B, C, D; // Углы

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    void print_info() const override {
        cout << "Четырёхугольник:\nСтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d;
        cout << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
};

// Прямоугольник 
class MyRectangle : public Quadrilateral {
public:
    MyRectangle(int a, int b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {}

    void print_info() const override {
        cout << "Прямоугольник:\nСтороны: a=" << a << " b=" << b << " c=" << a << " d=" << b;
        cout << "\nУглы: A=90 B=90 C=90 D=90" << endl;
    }
};

// Квадрат
class Square : public MyRectangle {
public:
    Square(int side) : MyRectangle(side, side) {}

    void print_info() const override {
        cout << "Квадрат:\nСтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d;
        cout << "\nУглы: A=90 B=90 C=90 D=90" << endl;
    }
};

// Параллелограмм
class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {}

    void print_info() const override {
        cout << "Параллелограмм:\nСтороны: a=" << a << " b=" << b << " c=" << a << " d=" << b;
        cout << "\nУглы: A=" << A << " B=" << B << " C=" << A << " D=" << B << endl;
    }
};

// Ромб
class Rhombus : public Parallelogram {
public:
    Rhombus(int side, int A, int B)
        : Parallelogram(side, side, A, B) {}

    void print_info() const override {
        cout << "Ромб:\nСтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d;
        cout << "\nУглы: A=" << A << " B=" << B << " C=" << A << " D=" << B << endl;
    }
};

// Функция для вывода информации о фигуре
void print_info(const Shape* shape) {
    shape->print_info();
}

int main() {
    SetConsoleOutputCP(1251); // Устанавливаем кодировку для поддержки русских символов
    Triangle t(10, 20, 30, 50, 60, 70);
    RightTriangle rt(10, 20, 30, 50, 60);
    IsoscelesTriangle it(10, 20, 50, 60);
    EquilateralTriangle et(30);
    Quadrilateral q(10, 20, 30, 40, 50, 60, 70, 80);
    MyRectangle rect(10, 20); 
    Square s(20);
    Parallelogram p(20, 30, 30, 40);
    Rhombus rh(30, 30, 40);
    print_info(&t);
    print_info(&rt);
    print_info(&it);
    print_info(&et);
    print_info(&q);
    print_info(&rect);  
    print_info(&s);
    print_info(&p);
    print_info(&rh);

    return 0;
}
