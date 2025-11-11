//
// Created by 67553 on 2025/6/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Widget.h" resolved

#include "widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);
    setWindowTitle("俄罗斯方块");
    setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);// 禁止最大化按钮
    setFixedSize(650, 680); //固定窗口大小
    ui->pB_new->setEnabled(false); //新游戏按钮初始状态为禁用
    ui->pB_pause->setEnabled(false); //暂停按钮初始状态为禁用

    game = new Game(ui->MainBoard->x(), ui->MainBoard->y(), ui->NextBoard->x(), ui->NextBoard->y()); //初始化游戏逻辑对象
    timer = new QTimer(); //创建定时器
    timer->setInterval(400); //设置定时器间隔为400毫秒
    connect(timer, &QTimer::timeout, this, &Widget::timer_start);
    connect(ui->pB_start, &QPushButton::clicked, this, &Widget::start_game); //连接开始按钮的点击信号到槽函数
    connect(ui->pB_pause, &QPushButton::clicked, this, &Widget::pause_game); //连接暂停按钮的点击信号到槽函数
    connect(ui->pB_new, &QPushButton::clicked, this, &Widget::new_game); //连接新游戏按钮的点击信号到槽函数
    isStarted = false; //游戏初始状态为未开始
    setFocusPolicy(Qt::StrongFocus); //设置焦点策略为强制获取焦点
}

void Widget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 10; j++) {
            Box box = game->getMainBoard().getBox(j, i); //获取主棋盘上的方块
            QPointF pos = box.getPosition(); //获取方块的位置
            QSizeF size(30, 30); //方块的大小
            QRectF rect(pos, size); //创建方块的矩形区域
            QColor color = box.getColorValue(); //获取方块的颜色
            painter.fillRect(rect, color); //填充方块颜色
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            Box box = game->getNextBoard().getBox(j, i); //获取下一个形状的预览棋盘上的方块
            QPointF pos = box.getPosition(); //获取方块的位置
            QSizeF size(30, 30); //方块的大小
            QRectF rect(pos, size); //创建方块的矩形区域
            QColor color = box.getColorValue(); //获取方块的颜色
            painter.fillRect(rect, color); //填充方块颜色
        }
    }
}

void Widget::start_game() {
    game->next_placeShape();
    game->main_placeShape();
    game->getNextBoard().clean(); //清空下一个形状的预览棋盘
    game->next_placeShape();
    update(); //更新界面
    isStarted = true; //设置游戏状态为已开始
    timer->start(); //启动定时器
    ui->pB_start->setEnabled(false); //禁用开始按钮
    ui->pB_new->setEnabled(true); //启用新游戏按钮
    ui->pB_pause->setEnabled(true); //启用暂停按钮
}

void Widget::pause_game() {
    if (isStarted) {
        timer->stop(); //停止定时器
        isStarted = false; //设置游戏状态为未开始
        ui->pB_start->setEnabled(true); //启用开始按钮
        ui->pB_pause->setText("继续"); //将暂停按钮文本改为“继续”
    } else {
        timer->start(); //重新启动定时器
        isStarted = true; //设置游戏状态为已开始
        ui->pB_start->setEnabled(false); //禁用开始按钮
        ui->pB_pause->setText("暂停"); //将暂停按钮文本改为“暂停”
    }
    update(); //更新界面
}

void Widget::new_game() {
    isStarted = false; //设置游戏状态为未开始
    timer->stop(); //停止定时器
    delete game; //删除游戏逻辑对象
    game = nullptr; //将游戏逻辑对象指针设置为nullptr
    game = new Game(ui->MainBoard->x(), ui->MainBoard->y(), ui->NextBoard->x(), ui->NextBoard->y()); //重新初始化游戏逻辑对象
    ui->lb_score->setText("0"); //重置得分显示
    ui->pB_start->setEnabled(true); //启用开始按钮
    ui->pB_new->setEnabled(false); //禁用新游戏按钮
    ui->pB_pause->setEnabled(false); //禁用暂停按钮
    update(); //更新界面
}

void Widget::timer_start() {
    if (game->isMovedown()) {
        game->moveDown(); //向下移动形状
    } else {
        if (game->numFullRows() > 0) {
            int score = game->countScore(); //计算得分
            score += ui->lb_score->text().toInt(); //累加得分
            ui->lb_score->setText(QString::number(score)); //更新得分显示
            game->cleanRow(); //清除满行
            game->rowMoveDown(); //将上方的行向下移动
        }
        game->main_placeShape(); //在主棋盘上放置新的形状
        game->getNextBoard().clean(); //清空下一个形状的预览棋盘
        game->next_placeShape(); //在下一个形状的预览棋盘上放置新的形状
    }
    update(); //更新界面
}

void Widget::keyReleaseEvent(QKeyEvent * event) {
    int key = event->key();
    if (isStarted) {
        switch (key) {
            case Qt::Key_Down:
                timer->setInterval(400); //恢复正常速度
                break;

            default:
                break;
        }
    }
}

void Widget::keyPressEvent(QKeyEvent * event) {
    if (game->isMovedown() && isStarted) {
        int key = event->key();
        switch (key) {
            case Qt::Key_Left:
                game->moveLeft(); //向左移动形状
                break;
            case Qt::Key_Right:
                game->moveRight(); //向右移动形状
                break;
            case Qt::Key_Down:
                if (timer->interval() != 100) { //如果定时器间隔不是100毫秒
                    timer->setInterval(100); //加快下落速度
                }
                break;
            default:
                break;
        }
    }
}

Widget::~Widget() {
    delete ui;
    delete game; //删除游戏逻辑对象
    delete timer; //删除定时器
}
