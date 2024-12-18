#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

class Quadrilateral {
protected:
    int a, b, c, d;  // ����� ������
    int A, B, C, D;  // ����

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
    virtual void print_info() const;

    // �������
    int get_side_a() const;
    int get_side_b() const;
    int get_side_c() const;
    int get_side_d() const;
    int get_angle_A() const;
    int get_angle_B() const;
    int get_angle_C() const;
    int get_angle_D() const;
};

#endif
