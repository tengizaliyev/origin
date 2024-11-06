#include <iostream>
#include <string>
#include <cmath>
#include <windows.h>
using namespace std;

class Figure {
public:
    virtual int sides_count() const { return 0; }
    virtual bool check() const { return sides_count() == 0; }

    virtual void print_info() const {
        cout << (check() ? "����������" : "������������") << endl;
        cout << "���������� ������: " << sides_count() << endl;
    }
};

class Triangle : public Figure {
protected:
    int a, b, c;  // ����� ������
    int A, B, C;  // ����

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {}

    int sides_count() const override { return 3; }

    bool check() const override {
        return (A + B + C == 180);
    }

    void print_info() const override {
        cout << "�����������:\n";
        cout << (check() ? "����������" : "������������") << endl;
        cout << "���������� ������: " << sides_count() << endl;
        cout << "�������: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "����: A=" << A << " B=" << B << " C=" << C << endl;
    }
};

// ������������� �����������
class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {}

    bool check() const override {
        return Triangle::check() && (C == 90);
    }

    void print_info() const override {
        cout << "������������� �����������:\n";
        Figure::print_info();  // �������� ����� �������� ������ ������ ���� ���
        cout << "�������: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "����: A=" << A << " B=" << B << " C=" << C << endl;
    }
};

// �������������� �����������
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A) {}

    bool check() const override {
        return Triangle::check() && (a == c) && (A == C);
    }

    void print_info() const override {
        cout << "�������������� �����������:\n";
        Figure::print_info();
        cout << "�������: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "����: A=" << A << " B=" << B << " C=" << C << endl;
    }
};

// �������������� �����������
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side)
        : Triangle(side, side, side, 60, 60, 60) {}

    bool check() const override {
        return Triangle::check() && (a == b && b == c) && (A == 60 && B == 60 && C == 60);
    }

    void print_info() const override {
        cout << "�������������� �����������:\n";
        Figure::print_info();
        cout << "�������: a=" << a << " b=" << b << " c=" << c << endl;
        cout << "����: A=" << A << " B=" << B << " C=" << C << endl;
    }
};

class Quadrilateral : public Figure {
protected:
    int a, b, c, d;  // ����� ������
    int A, B, C, D;  // ����

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    int sides_count() const override { return 4; }

    bool check() const override {
        return (A + B + C + D == 360);
    }

    void print_info() const override {
        cout << "��������������:\n";
        cout << (check() ? "����������" : "������������") << endl;
        cout << "���������� ������: " << sides_count() << endl;
        cout << "�������: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "����: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
};

// �������������
class MyRectangle : public Quadrilateral {
public:
    MyRectangle(int a, int b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {}

    bool check() const override {
        return Quadrilateral::check() && (a == c && b == d) && (A == 90 && B == 90 && C == 90 && D == 90);
    }

    void print_info() const override {
        cout << "�������������:\n";
        Figure::print_info();
        cout << "�������: a=" << a << " b=" << b << " c=" << a << " d=" << b << endl;
        cout << "����: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
};

// �������
class Square : public MyRectangle {
public:
    Square(int side) : MyRectangle(side, side) {}

    bool check() const override {
        return MyRectangle::check() && (a == b && b == c && c == d);
    }

    void print_info() const override {
        cout << "�������:\n";
        Figure::print_info();
        cout << "�������: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "����: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
};

// ��������������
class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {}

    bool check() const override {
        return Quadrilateral::check() && (a == c && b == d) && (A == C && B == D);
    }

    void print_info() const override {
        cout << "��������������:\n";
        Figure::print_info();
        cout << "�������: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "����: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
};

// ����
class Rhombus : public Parallelogram {
public:
    Rhombus(int side, int A, int B)
        : Parallelogram(side, side, A, B) {}

    bool check() const override {
        return Parallelogram::check() && (a == b && b == c && c == d);
    }

    void print_info() const override {
        cout << "����:\n";
        Figure::print_info();
        cout << "�������: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
        cout << "����: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
};

// ������� ��� ������ ���������� � ������
void print_info(const Figure* shape) {
    shape->print_info();
}

int main() {
    SetConsoleOutputCP(1251); // ������������� ��������� ��� ��������� ������� ��������

    Figure* shapes[] = {
        new Triangle(10, 20, 30, 50, 60, 70),
        new RightTriangle(10, 20, 30, 50, 90),
        new IsoscelesTriangle(10, 20, 50, 60),
        new EquilateralTriangle(30),
        new Quadrilateral(10, 20, 30, 40, 50, 60, 70, 80),
        new MyRectangle(10, 20),
        new Square(20),
        new Parallelogram(20, 30, 30, 40),
        new Rhombus(30, 30, 40)
    };

    for (Figure* shape : shapes) {
        print_info(shape);
        cout << endl;
    }

    // ������� ������
    for (Figure* shape : shapes) {
        delete shape;
    }

    return 0;
}
