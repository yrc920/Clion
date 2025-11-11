//
// Created by 67553 on 2025/7/9.
//

#include "oShape.h"

oShape::oShape(Box& box1, Board& b) : Shape(box1, b) {
    color = Box::yellow;
    int x = box1.getPos().x();
    int y = box1.getPos().y();
    Boxs[1] = b.getBox(x, y + 1); //第二个方块在第一个方块的下方
    Boxs[2] = b.getBox(x + 1, y); //第三个方块在第一个方块的右方
    Boxs[3] = b.getBox(x + 1, y + 1); //第四个方块在第二个方块的右方
    for (int i = 0; i < 4; i++) {
        Boxs[i].setColor(color); //设置所有方块的颜色
    }
}

