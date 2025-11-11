//
// Created by 67553 on 2025/7/9.
//

#include "iShape.h"

iShape::iShape(Box& box1, Board& b) : Shape(box1, b) {
    color = Box::cyan; //设置颜色为青色
    int x = box1.getPos().x();
    int y = box1.getPos().y();
    Boxs[1] = b.getBox(x + 1, y); //第二个方块在第一个方块的右方
    Boxs[2] = b.getBox(x + 2, y); //第三个方块在第二个方块的右方
    Boxs[3] = b.getBox(x + 3, y); //第四个方块在第三个方块的右方
    for (int i = 0; i < 4; i++) {
        Boxs[i].setColor(color); //设置所有方块的颜色
    }
}
