//
// Created by 67553 on 2025/7/8.
//

#include "Box.h"

Box &Box::copy(const Box& c) {
    color = c.color;
    pos = c.pos;
    position = c.position;
    return *this;
}

QColor Box::getColorValue() const{
    QColor qcolor;
    switch (color) {
        case red:
            qcolor = QColor(255, 0, 0);
            break;
        case orange:
            qcolor = QColor(255, 165, 0);
            break;
        case yellow:
            qcolor = QColor(255, 255, 0);
            break;
        case green:
            qcolor = QColor(0, 255, 0);
            break;
        case cyan:
            qcolor = QColor(0, 255, 255);
            break;
        case blue:
            qcolor = QColor(0, 0, 255);
            break;
        case purple:
            qcolor = QColor(128, 0, 128);
            break;
        default:
            qcolor = QColor(0, 0, 0, 0); //默认无色
    }
    return qcolor;
}

