//
// Created by 67553 on 2025/7/9.
//

#ifndef JSHAPE_H
#define JSHAPE_H

#include "Shape.h"

class jShape : public Shape {
public:
    jShape(Box &, Board &);
    ~jShape() override = default; //虚析构函数
};

#endif //JSHAPE_H
