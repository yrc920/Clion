//
// Created by 67553 on 2025/7/8.
//

#ifndef BOX_H
#define BOX_H

#include <QDebug>
#include <QColor>
#include <QPointF>

class Box {
private:
    QPoint pos; //方块在棋盘中的位置
    QPointF position; //方块的实际位置
    int color; //方块的颜色
    Box& copy(const Box&);
public:
    enum {no_color, red, orange, yellow, green, cyan, blue, purple}; //方块颜色
    Box() {} //默认构造函数
    Box(QPoint pos1, QPointF position1, int color1 = no_color) : pos(pos1), position(position1), color(color1) {}
    Box(const Box& c) { copy(c); } //拷贝构造函数
    Box& operator=(const Box& c) { return copy(c); }

    int getColor() const { return color; } //获取方块颜色
    void setColor(int color1) { color = color1; } //设置方块颜色
    QPoint getPos() const { return pos; } //获取方块在棋盘中的位置
    QPointF getPosition() const { return position; } //获取方块的实际位置
    QColor getColorValue() const; //获取方块颜色
};

#endif //BOX_H
