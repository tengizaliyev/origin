#include <iostream>
#include <windows.h>
using namespace std;

// ������� ����� ������
class Shape {
public:
    virtual void print_info() const = 0; // ����� ����������� ����� ��� ������ ����������
};

// ����� �����������
class Triangle : public Shape {
protected:
    int a, b, c;   // ����� ������
    int A, B, C;   // ����

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {}

    void print_info() const override {
        cout << "�����������:\n�������: a=" << a << " b=" << b << " c=" << c;
        cout << "\n����: A=" << A << " B=" << B << " C=" << C << endl;
    }
};

// ������������� �����������
class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {}

    void print_info() const override {
        cout << "������������� �����������:\n�������: a=" << a << " b=" << b << " c=" << c;
        cout << "\n����: A=" << A << " B=" << B << " C=90" << endl;
    }
};

// �������������� �����������
class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A) {}

    void print_info() const override {
        cout << "�������������� �����������:\n�������: a=" << a << " b=" << b << " c=" << a;
        cout << "\n����: A=" << A << " B=" << B << " C=" << A << endl;
    }
};

// �������������� �����������
class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int side)
        : Triangle(side, side, side, 60, 60, 60) {}

    void print_info() const override {
        cout << "�������������� �����������:\n�������: a=" << a << " b=" << b << " c=" << c;
        cout << "\n����: A=60 B=60 C=60" << endl;
    }
};

// ����� ���������������
class Quadrilateral : public Shape {
protected:
    int a, b, c, d; // ����� ������
    int A, B, C, D; // ����

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    void print_info() const override {
        cout << "��������������:\n�������: a=" << a << " b=" << b << " c=" << c << " d=" << d;
        cout << "\n����: A=" << A << " B=" << B << " C=" << C << " D=" << D << endl;
    }
};

// ������������� 
class MyRectangle : public Quadrilateral {
public:
    MyRectangle(int a, int b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90) {}

    void print_info() const override {
        cout << "�������������:\n�������: a=" << a << " b=" << b << " c=" << a << " d=" << b;
        cout << "\n����: A=90 B=90 C=90 D=90" << endl;
    }
};

// �������
class Square : public MyRectangle {
public:
    Square(int side) : MyRectangle(side, side) {}

    void print_info() const override {
        cout << "�������:\n�������: a=" << a << " b=" << b << " c=" << c << " d=" << d;
        cout << "\n����: A=90 B=90 C=90 D=90" << endl;
    }
};

// ��������������
class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrilateral(a, b, a, b, A, B, A, B) {}

    void print_info() const override {
        cout << "��������������:\n�������: a=" << a << " b=" << b << " c=" << a << " d=" << b;
        cout << "\n����: A=" << A << " B=" << B << " C=" << A << " D=" << B << endl;
    }
};

// ����
class Rhombus : public Parallelogram {
public:
    Rhombus(int side, int A, int B)
        : Parallelogram(side, side, A, B) {}

    void print_info() const override {
        cout << "����:\n�������: a=" << a << " b=" << b << " c=" << c << " d=" << d;
        cout << "\n����: A=" << A << " B=" << B << " C=" << A << " D=" << B << endl;
    }
};

// ������� ��� ������ ���������� � ������
void print_info(const Shape* shape) {
    shape->print_info();
}

int main() {
    SetConsoleOutputCP(1251); // ������������� ��������� ��� ��������� ������� ��������
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
