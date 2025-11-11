//
// Created by 67553 on 2025/7/9.
//

#include "Shape.h"

Shape::Shape(Box& box1, Board& b) : board(b){
    color = Box::no_color; //默认颜色为无色
    for (int i = 0; i < 4; i++) {
        Boxs[i] = Box();
    }
    Boxs[0] = box1; //将传入的Box赋值给第一个方块
    rotation = 0; //默认旋转状态为0
}

bool Shape::isValid(int type) {
    bool valid = false;
    for (int i = 0; i < 4; i++) {
        int x = rotatePos[type][i].x();
        int y = rotatePos[type][i].y();
        if (x >= 0 && x < 10 && y >= 0 && y < 20 && board.getBox(x, y).getColor() == Box::no_color) {
            valid = true; //如果所有方块的位置都在棋盘范围内且颜色为无色, 则有效
        } else {
            valid = false; //否则无效
            break;
        }
    }
    return valid; //返回是否有效
}

void Shape::compute_rotatePos() {
    for (int i = 0; i < 4; i++) {
        rotatePos[i][1] = Boxs[1].getPos();
    }
}
