//
// Created by 67553 on 2025/7/9.
//

#ifndef ZSHAPE_H
#define ZSHAPE_H

#include "Shape.h"

class zShape : public Shape{
public:
    zShape(Box &, Board &);
    ~zShape() override = default; //虚析构函数
};

#endif //ZSHAPE_H
