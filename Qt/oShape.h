//
// Created by 67553 on 2025/7/9.
//

#ifndef OSHAPE_H
#define OSHAPE_H

#include "Shape.h"

class oShape : public Shape {
public:
    oShape(Box &, Board &);
    ~oShape() override = default; //虚析构函数
};

#endif //OSHAPE_H
