//
// Created by 67553 on 2025/7/8.
//

#include "Board.h"

//前两个参数代表棋盘在窗口的位置, 后两个代表棋盘的大小(以此来表示主副棋盘)
Board::Board(int x, int y, int board_height, int board_width) {
    board_h = board_height;
    board_w = board_width;
    board = new Box*[board_h]; //初始化棋盘
    for (int i = 0; i < board_h; ++i) {
        board[i] = new Box[board_w]; //为每一行分配内存
        for (int j = 0; j < board_w; ++j) {
            board[i][j] = Box(QPoint(j, i), QPointF(x + j * 30, y + i * 30));
            //初始化每个方块
        }
    }
}

Board &Board::copy(const Board &b) {
    board_h = b.board_h;
    board_w = b.board_w;
    board = new Box*[board_h]; //重新分配内存
    for (int i = 0; i < board_h; ++i) {
        board[i] = new Box[board_w]; //为每一行分配内存
        for (int j = 0; j < board_w; ++j) {
            board[i][j] = b.board[i][j]; //拷贝每个方块
        }
    }
    return *this;
}

void Board::clean() const{
    for (int i = 0; i < board_h; ++i) {
        for (int j = 0; j < board_w; ++j) {
            board[i][j].setColor(Box::no_color); //清空棋盘上的方块颜色
        }
    }
}

bool Board::isFull(int row) const{
    for (int i = 0; i < board_w; ++i) {
        if (board[row][i].getColor() == Box::no_color) {
            return false; //如果有一个方块颜色是无色的, 则该行不满
        }
    }
    return true; //如果所有方块颜色都不是无色的, 则该行满了
}

bool Board::isEmpty(int row) const{
    for (int i = 0; i < board_w; ++i) {
        if (board[row][i].getColor() != Box::no_color) {
            return false; //如果有一个方块颜色不是无色的, 则该行不空
        }
    }
    return true; //如果所有方块颜色都是无色的, 则该行空了
}

bool Board::issomeBox(int row) const{
    return (!isFull(row) && !isEmpty(row)); //如果该行不满且不空, 则返回true
}

void Board::cleanRow(int row) {
    for (int i = 0; i < board_w; ++i) {
        board[row][i].setColor(Box::no_color); //清空指定行的方块颜色
    }
}

void Board::changeRow(int row, int down) {
    for (int i = 0; i < board_w; ++i) {
        int color = board[row][i].getColor(); //获取当前方块颜色
        board[down][i].setColor(color); //将当前方块颜色设置到下方行
        board[row][i].setColor(Box::no_color); //清空当前方块颜色
    }
}

QPoint Board::startPos(int shape, int type) {
    int w = 0; //水平方向
    int h = 0; //垂直方向
    switch (shape) {
        case oShape: //O形
            w = board_w / 2 - 1; //水平位置
            h = (type == Main ? 0 : board_h / 2 - 1); //垂直位置
            break;
        case iShape: //I形
            w = board_w / 2 - 2; //水平位置
            h = (type == Main ? 0 : board_h / 2 - 1); //垂直位置
            break;
        case tShape: //T形
            w = board_w / 2 - 2; //水平位置
            h = (type == Main ? 1 : board_h / 2); //垂直位置
            break;
        case sShape: //S形
            w = board_w / 2 - 2; //水平位置
            h = (type == Main ? 1 : board_h / 2); //垂直位置
            break;
        case zShape: //Z形
            w = board_w / 2 - 2; //水平位置
            h = (type == Main ? 0 : board_h / 2 - 1); //垂直位置
            break;
        case lShape: //L形
            w = board_w / 2 - 2; //水平位置
            h = (type == Main ? 1 : board_h / 2); //垂直位置
            break;
        case jShape: //J形
            w = board_w / 2 - 2; //水平位置
            h = (type == Main ? 0 : board_h / 2 - 1); //垂直位置
            break;
        default:
            break;
    }
    return QPoint(w, h); //返回起始位置
}

Board::~Board() {
    for (int i = 0; i < board_h; ++i) {
        delete[] board[i]; //释放每一行的内存
    }
    delete[] board; //释放棋盘的内存
}

