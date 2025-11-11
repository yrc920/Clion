//
// Created by 67553 on 2025/6/24.
//

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "Game.h"
#include <QTimer>
#include <QKeyEvent>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget {
Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *) override; //重写绘图事件
    void keyReleaseEvent(QKeyEvent * event) override;
    void keyPressEvent(QKeyEvent * event) override;
    ~Widget() override;

private slots:
    void start_game(); //开始游戏的槽函数
    void pause_game(); //暂停游戏的槽函数
    void new_game(); //新游戏的槽函数
    void timer_start(); //定时器触发的槽函数，用于游戏循环

private:
    Ui::Widget *ui;
    Game* game; //游戏逻辑对象
    QTimer *timer; //定时器用于游戏循环
    bool isStarted; //游戏是否开始
};

#endif //WIDGET_H
