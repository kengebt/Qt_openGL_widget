/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    GLWidget *widget;
    QPushButton *Move_Up;
    QPushButton *Move_Left;
    QPushButton *Move_Right;
    QPushButton *Move_Origin;
    QPushButton *Move_Down;
    QVBoxLayout *verticalLayout;
    QPushButton *OpenButton_1;
    QPushButton *OpenButton_2;
    QPushButton *OpenButton_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(480, 360);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new GLWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        Move_Up = new QPushButton(widget);
        Move_Up->setObjectName(QStringLiteral("Move_Up"));
        Move_Up->setGeometry(QRect(50, 0, 40, 23));
        Move_Left = new QPushButton(widget);
        Move_Left->setObjectName(QStringLiteral("Move_Left"));
        Move_Left->setGeometry(QRect(0, 30, 40, 23));
        Move_Right = new QPushButton(widget);
        Move_Right->setObjectName(QStringLiteral("Move_Right"));
        Move_Right->setGeometry(QRect(100, 30, 40, 23));
        Move_Origin = new QPushButton(widget);
        Move_Origin->setObjectName(QStringLiteral("Move_Origin"));
        Move_Origin->setGeometry(QRect(50, 30, 40, 23));
        Move_Down = new QPushButton(widget);
        Move_Down->setObjectName(QStringLiteral("Move_Down"));
        Move_Down->setGeometry(QRect(50, 60, 40, 23));

        horizontalLayout->addWidget(widget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        OpenButton_1 = new QPushButton(centralWidget);
        OpenButton_1->setObjectName(QStringLiteral("OpenButton_1"));

        verticalLayout->addWidget(OpenButton_1);

        OpenButton_2 = new QPushButton(centralWidget);
        OpenButton_2->setObjectName(QStringLiteral("OpenButton_2"));

        verticalLayout->addWidget(OpenButton_2);

        OpenButton_3 = new QPushButton(centralWidget);
        OpenButton_3->setObjectName(QStringLiteral("OpenButton_3"));

        verticalLayout->addWidget(OpenButton_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OpenGL window", 0));
        Move_Up->setText(QApplication::translate("MainWindow", "Up", 0));
        Move_Left->setText(QApplication::translate("MainWindow", "Left", 0));
        Move_Right->setText(QApplication::translate("MainWindow", "Right", 0));
        Move_Origin->setText(QApplication::translate("MainWindow", "O", 0));
        Move_Down->setText(QApplication::translate("MainWindow", "Down", 0));
        OpenButton_1->setText(QApplication::translate("MainWindow", "Open1", 0));
        OpenButton_2->setText(QApplication::translate("MainWindow", "Load Ply", 0));
        OpenButton_3->setText(QApplication::translate("MainWindow", "Load Pose", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
