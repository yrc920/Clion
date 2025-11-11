//
// Created by 67553 on 2025/7/9.
//

#include "Game.h"
#include <QRandomGenerator>
#include <QDateTime>

Game::Game(int main_x, int main_y, int next_x, int next_y) :
    mainBoard(main_x, main_y, 20, 10), nextBoard(next_x, next_y, 6, 6) {
    nextShape = Board::oShape; //默认下一个形状为oShape
    movedown = true; //初始状态可以向下移动
    shape = nullptr; //当前形状指针初始化为nullptr
}

Shape* Game::placeShape(Board& b, int type, int num) {
    Shape* newShape = nullptr;
    switch (num) {
        case Board::lShape: {
            QPoint point = b.startPos(Board::lShape, type);
            Box box1 = b.getBox(point.x(), point.y());
            newShape = new lShape(box1, b); //创建lShape对象
        }
            break;
        case Board::jShape: {
            QPoint point = b.startPos(Board::jShape, type);
            Box box1 = b.getBox(point.x(), point.y());
            newShape = new jShape(box1, b); //创建jShape对象
        }
            break;
        case Board::iShape: {
            QPoint point = b.startPos(Board::iShape, type);
            Box box1 = b.getBox(point.x(), point.y());
            newShape = new iShape(box1, b); //创建iShape对象
        }
            break;
        case Board::tShape: {
            QPoint point = b.startPos(Board::tShape, type);
            Box box1 = b.getBox(point.x(), point.y());
            newShape = new tShape(box1, b); //创建tShape对象
        }
            break;
        case Board::oShape: {
            QPoint point = b.startPos(Board::oShape, type);
            Box box1 = b.getBox(point.x(), point.y());
            newShape = new oShape(box1, b); //创建oShape对象
        }
            break;
        case Board::sShape: {
            QPoint point = b.startPos(Board::sShape, type);
            Box box1 = b.getBox(point.x(), point.y());
            newShape = new sShape(box1, b); //创建sShape对象
        }
            break;
        case Board::zShape: {
            QPoint point = b.startPos(Board::zShape, type);
            Box box1 = b.getBox(point.x(), point.y());
            newShape = new zShape(box1, b); //创建zShape对象
        }
            break;
        default:
            break;
    }
    return newShape; //返回新创建的形状指针
}

void Game::main_placeShape() {
    movedown = true; //重置向下移动状态
    if (shape) {
        delete shape; //删除之前的形状
        shape = nullptr; //将形状指针设置为nullptr
    }
    shape = placeShape(mainBoard, Board::Main, nextShape); //创建新的形状
}

void Game::next_placeShape() {
    QRandomGenerator randGenerator(QDateTime::currentMSecsSinceEpoch());
    int type = randGenerator.bounded(1, 8);
    placeShape(nextBoard, Board::Next, type); //在下一个形状的预览棋盘上放置新形状
    nextShape = type; //更新下一个形状的类型
}

bool Game::canMove(int direction, bool down) {
    bool canMove = false; //默认可以移动
    int color = Box::no_color; //默认颜色为无色
    for (int i = 0; i < 4; i++) {
        Box& box1 = shape->getBox(i); //获取当前形状的每个方块
        color = box1.getColor(); //保存当前方块的颜色
        box1.setColor(Box::no_color); //将当前方块颜色设置为无色
    }
    for (int i = 0; i < 4; i++) {
        int x = shape->getBox(i).getPos().x(); //计算新的水平位置
        int y = shape->getBox(i).getPos().y(); //计算新的垂直位置
        if (direction == Down) {
            y += 1; //向下移动
        } else if (direction == Left) {
            x -= 1; //向左移动
        } else if (direction == Right) {
            x += 1; //向右移动
        }
        if (x >= 0 && x < 10 && y >= 0 && y < 20 && mainBoard.getBox(x, y).getColor() == Box::no_color) {
            canMove = true; //如果新的位置在棋盘范围内且颜色为无色, 则可以移动
        } else {
            if ((y >= 20 || mainBoard.getBox(x, y).getColor() != Box::no_color)&& down) {
                movedown = false; //如果向下移动到达底部或碰到其他方块, 则不能向下移动
            }
            canMove = false; //否则不能移动
            break;
        }
    }
    if (!canMove) {
        for (int i = 0; i < 4; i++) {
            shape->getBox(i).setColor(color); //如果不能移动, 恢复原来的颜色
        }
    }
    return canMove; //返回是否可以移动
}

void Game::move(int direction) {
    for (int i = 0; i < 4; i++) {
        int x = shape->getBox(i).getPos().x(); //获取当前方块的水平位置
        int y = shape->getBox(i).getPos().y(); //获取当前方块的垂直位置
        if (direction == Down) {
            y += 1; //向下移动
        } else if (direction == Left) {
            x -= 1; //向左移动
        } else if (direction == Right) {
            x += 1; //向右移动
        }
        Box& box1 = mainBoard.getBox(x, y); //获取新的位置的方块
        shape->setBox(i, box1); //将图案的位置更新
        box1.setColor(shape->getColor()); //设置新的方块颜色为图案的颜色
    }
}

void Game::moveDown() {
    bool canMoveDown = canMove(Down, true); //检查是否可以向下移动
    if (canMoveDown) move(Down); //如果可以向下移动, 则执行向下移动
}

void Game::moveLeft() {
    bool canMoveLeft = canMove(Left, false); //检查是否可以向左移动
    if (canMoveLeft) move(Left); //如果可以向左移动, 则执行向左移动
}

void Game::moveRight() {
    bool canMoveRight = canMove(Right, false); //检查是否可以向右移动
    if (canMoveRight) move(Right); //如果可以向右移动, 则执行向右移动
}

void Game::traverseRow(int* row) {
    for (int i = 19; i >= 0; i--) {
        if (mainBoard.isFull(i)) {
            if (row) {
                ++*row; //如果传入了行数指针, 则增加行数
            }
            else {
                mainBoard.cleanRow(i); //如果没有传入行数指针, 则清空该行
            }
        }
    }
}

void Game::cleanRow() {
    traverseRow(); //清除满行
}

int Game::numFullRows() {
    int num = 0; //满行计数器
    traverseRow(&num); //遍历行, 统计满行数量
    return num; //返回满行数量
}

int Game::countScore() {
    int num = numFullRows(); //获取满行数量
    return num * num; //得分为满行数量的平方
}

void Game::rowMoveDown() {
    int empty = 19; //从底部开始向上查找空行
    int somebox = 19; //从底部开始向上查找有方块的行
    for (int i = empty; i >= 0; i--) {
        if (mainBoard.isEmpty(i)) {
            somebox = i - 1; //如果当前行为空, 则记录上一个有方块的行
            for (int j = somebox; j >= 0; j--) {
                if (mainBoard.issomeBox(j)) {
                    mainBoard.changeRow(j, i); //将有方块的行向下移动到空行的位置
                    break;
                }
            }
        }
    }
}

Game::~Game() {
    if (shape) {
        delete shape; //释放当前形状的内存
        shape = nullptr; //将形状指针设置为nullptr
    }
    mainBoard.clean(); //清空主棋盘
    nextBoard.clean(); //清空下一个形状的预览棋盘
}
