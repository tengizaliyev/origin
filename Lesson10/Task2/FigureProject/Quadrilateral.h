#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

class Quadrilateral {
protected:
    int a, b, c, d;  
    int A, B, C, D; 

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D);
    virtual void print_info() const;
};

#endif
