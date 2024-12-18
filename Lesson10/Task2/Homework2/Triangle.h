#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle {
protected:
    int a, b, c;    // ƒлины сторон
    int A, B, C;    // ”глы

public:
    Triangle(int a, int b, int c, int A, int B, int C);
    virtual void print_info() const;

    int get_side_a() const;
    int get_side_b() const;
    int get_side_c() const;
    int get_angle_A() const;
    int get_angle_B() const;
    int get_angle_C() const;
};

#endif
