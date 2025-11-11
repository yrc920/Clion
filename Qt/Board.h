//
// Created by 67553 on 2025/7/8.
//

#ifndef BOARD_H
#define BOARD_H

#include "Box.h"

class Board {
private:
    int board_w; //棋盘的宽
    int board_h; //棋盘的高
    Box **board; //棋盘上的方块
    Board& copy(const Board&);
public:
    enum {Main, Next}; //棋盘的类型
    enum {oShape, iShape, tShape, sShape, zShape, lShape, jShape}; //形状的类型
    Board() {} //默认构造函数
    Board(int, int, int, int);
    Board(const Board& b) {copy(b);} //拷贝构造函数
    Board& operator=(const Board& b) { return copy(b); }

    Box& getBox(int x, int y) const { return board[y][x]; } //获取指定位置的方块
    int getBoxColor(const Box &b) const { return b.getColor(); } //获取方块颜色
    void setBoxColor(Box &b, int color) { b.setColor(color); } //设置方块颜色
    void clean() const; //清空棋盘上的方块颜色
    bool isFull(int) const; //判断指定行是否为满
    bool isEmpty(int) const; //判断指定行是否为空
    bool issomeBox(int) const; //判断指定行是否有方块,且不为满
    void cleanRow(int); //清空指定行
    void changeRow(int, int); //将指定行向下移动(用于消除行时的移动)
    QPoint startPos(int, int); //图案在棋盘上的起始位置
    ~Board();
};

#endif //BOARD_H
