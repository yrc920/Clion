//
// Created by 67553 on 2025/7/9.
//

#ifndef ISHAPE_H
#define ISHAPE_H

#include "Shape.h"

class iShape : public Shape {
public:
    iShape(Box &, Board &);
    ~iShape() override = default; //虚析构函数
};

#endif //ISHAPE_H
