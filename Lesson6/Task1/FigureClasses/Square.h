#ifndef SQUARE_H
#define SQUARE_H

#include "myRectangle.h"

class Square : public myRectangle {
public:
    Square(int side);
    void print_info() const override;
};

#endif
