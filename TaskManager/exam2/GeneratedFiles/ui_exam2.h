/********************************************************************************
** Form generated from reading UI file 'exam2.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAM2_H
#define UI_EXAM2_H

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

class Ui_exam2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *exam2Class)
    {
        if (exam2Class->objectName().isEmpty())
            exam2Class->setObjectName(QStringLiteral("exam2Class"));
        exam2Class->resize(600, 400);
        menuBar = new QMenuBar(exam2Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        exam2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(exam2Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        exam2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(exam2Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        exam2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(exam2Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        exam2Class->setStatusBar(statusBar);

        retranslateUi(exam2Class);

        QMetaObject::connectSlotsByName(exam2Class);
    } // setupUi

    void retranslateUi(QMainWindow *exam2Class)
    {
        exam2Class->setWindowTitle(QApplication::translate("exam2Class", "exam2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exam2Class: public Ui_exam2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAM2_H
