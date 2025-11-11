//
// Created by 67553 on 2025/7/9.
//

#ifndef GAME_H
#define GAME_H

#include "Shape.h"
#include "lShape.h"
#include "jShape.h"
#include "oShape.h"
#include "sShape.h"
#include "zShape.h"
#include "iShape.h"
#include "tShape.h"

class Game {
private:
    Board mainBoard; //主棋盘
    Board nextBoard; //下一个形状的预览棋盘
    int nextShape; //下一个形状的类型
    Shape *shape; //当前形状指针
    bool movedown; //是否可以向下移动

    Shape* placeShape(Board& , int, int); //放置形状到棋盘上
    bool canMove(int, bool); //判断形状是否可以移动到指定位置
    void move(int); //移动形状到指定位置
    void traverseRow(int* row = NULL); //遍历行，清除满行的方块
public:
    enum {Down = 0, Left = -1, Right = 1}; //移动方向
    Game(int, int, int, int); //构造函数，初始化主棋盘和下一个形状的预览棋盘
    Board &getMainBoard() { return mainBoard; } //获取主棋盘
    Board &getNextBoard() { return nextBoard; } //获取下一个形状的预览棋盘
    bool isMovedown() const { return movedown; } //获取是否可以向下移动

    void main_placeShape(); //在主棋盘上放置形状
    void next_placeShape(); //在下一个形状的预览棋盘上放置形状
    void moveDown(); //向下移动形状
    void moveLeft(); //向左移动形状
    void moveRight(); //向右移动形状
    void cleanRow(); //清除满行的方块
    int numFullRows(); //获取满行的数量
    int countScore(); //计算得分
    void rowMoveDown(); //清除满行后，所有上方的行向下移动
    ~Game();
};

#endif //GAME_H
