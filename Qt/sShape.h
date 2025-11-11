//
// Created by 67553 on 2025/7/9.
//

#ifndef SSHAPE_H
#define SSHAPE_H

#include "Shape.h"

class sShape : public Shape {
public:
    sShape(Box &, Board &);
    ~sShape() override = default; //虚析构函数
};

#endif //SSHAPE_H
