//
// Created by 67553 on 2025/7/9.
//

#ifndef LSHAPE_H
#define LSHAPE_H

#include "Shape.h"

class lShape : public Shape {
public:
    lShape(Box &, Board &);
    ~lShape() override = default; //虚析构函数
};

#endif //LSHAPE_H
