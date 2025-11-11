/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *MainBoard;
    QFrame *NextBoard;
    QPushButton *pB_start;
    QPushButton *pB_pause;
    QLabel *label;
    QLabel *lb_score;
    QPushButton *pB_new;
    QLabel *label_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(650, 680);
        MainBoard = new QFrame(Widget);
        MainBoard->setObjectName(QString::fromUtf8("MainBoard"));
        MainBoard->setGeometry(QRect(38, 28, 304, 604));
        MainBoard->setFrameShape(QFrame::Box);
        MainBoard->setFrameShadow(QFrame::Raised);
        MainBoard->setLineWidth(2);
        NextBoard = new QFrame(Widget);
        NextBoard->setObjectName(QString::fromUtf8("NextBoard"));
        NextBoard->setGeometry(QRect(408, 68, 184, 184));
        NextBoard->setFrameShape(QFrame::Box);
        NextBoard->setFrameShadow(QFrame::Raised);
        NextBoard->setLineWidth(2);
        pB_start = new QPushButton(Widget);
        pB_start->setObjectName(QString::fromUtf8("pB_start"));
        pB_start->setGeometry(QRect(430, 460, 141, 41));
        pB_pause = new QPushButton(Widget);
        pB_pause->setObjectName(QString::fromUtf8("pB_pause"));
        pB_pause->setGeometry(QRect(430, 520, 141, 41));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(440, 290, 91, 41));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setLineWidth(1);
        lb_score = new QLabel(Widget);
        lb_score->setObjectName(QString::fromUtf8("lb_score"));
        lb_score->setGeometry(QRect(520, 290, 121, 41));
        lb_score->setFont(font);
        pB_new = new QPushButton(Widget);
        pB_new->setObjectName(QString::fromUtf8("pB_new"));
        pB_new->setGeometry(QRect(430, 580, 141, 41));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(410, 20, 171, 41));
        QFont font1;
        font1.setPointSize(11);
        label_3->setFont(font1);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pB_start->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        pB_pause->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\345\276\227\345\210\206:", nullptr));
        lb_score->setText(QCoreApplication::translate("Widget", "0", nullptr));
        pB_new->setText(QCoreApplication::translate("Widget", "\346\226\260\346\270\270\346\210\217", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\344\270\252:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
