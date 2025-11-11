//
// Created by 67553 on 2025/7/9.
//

#ifndef TSHAPE_H
#define TSHAPE_H

#include "Shape.h"

class tShape : public Shape {
public:
    tShape(Box &, Board &);
    ~tShape() override = default;
};

#endif //TSHAPE_H
