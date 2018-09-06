/********************************************************************************
** Form generated from reading UI file 'xh254zhy.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XH254ZHY_H
#define UI_XH254ZHY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_xh254zhyClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *xh254zhyClass)
    {
        if (xh254zhyClass->objectName().isEmpty())
            xh254zhyClass->setObjectName(QStringLiteral("xh254zhyClass"));
        xh254zhyClass->resize(600, 400);
        menuBar = new QMenuBar(xh254zhyClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        xh254zhyClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(xh254zhyClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        xh254zhyClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(xh254zhyClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        xh254zhyClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(xh254zhyClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        xh254zhyClass->setStatusBar(statusBar);

        retranslateUi(xh254zhyClass);

        QMetaObject::connectSlotsByName(xh254zhyClass);
    } // setupUi

    void retranslateUi(QMainWindow *xh254zhyClass)
    {
        xh254zhyClass->setWindowTitle(QApplication::translate("xh254zhyClass", "xh254zhy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class xh254zhyClass: public Ui_xh254zhyClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XH254ZHY_H
