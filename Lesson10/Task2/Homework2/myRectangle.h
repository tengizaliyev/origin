#ifndef MYRECTANGLE_H
#define MYRECTANGLE_H

#include "Quadrilateral.h"

class myRectangle : public Quadrilateral {
public:
    myRectangle(int a, int b);
    void print_info() const override;
};

#endif
