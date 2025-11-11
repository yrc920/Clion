//
// Created by 67553 on 2025/7/9.
//

#ifndef SHAPE_H
#define SHAPE_H

#include "Board.h"

class Shape {
protected:
    Box Boxs[4]; //存储形状的四个方块
    int color; //形状的颜色
    int rotation; //形状的旋转状态
    Board board; //所在棋盘
    QPoint rotatePos[4][4]; //每种旋转状态下,每个方块相对于中心方块的位置
    bool isValid(int); //判断是否可以旋转
    virtual void compute_rotatePos();
public:
    Shape(Box &, Board &); //传入第一个方块和所在棋盘
    int getColor() const { return color; } //获取形状的颜色
    Box& getBox(int i) { return Boxs[i]; } //获取指定索引的方块
    void setBox(int i, const Box &b) { Boxs[i] = b; } //设置指定索引的方块
    virtual void rotate();
    virtual ~Shape() = default; //虚析构函数
};

#endif //SHAPE_H
