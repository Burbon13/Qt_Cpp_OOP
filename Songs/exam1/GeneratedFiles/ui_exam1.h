/********************************************************************************
** Form generated from reading UI file 'exam1.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAM1_H
#define UI_EXAM1_H

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

class Ui_exam1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *exam1Class)
    {
        if (exam1Class->objectName().isEmpty())
            exam1Class->setObjectName(QStringLiteral("exam1Class"));
        exam1Class->resize(600, 400);
        menuBar = new QMenuBar(exam1Class);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        exam1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(exam1Class);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        exam1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(exam1Class);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        exam1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(exam1Class);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        exam1Class->setStatusBar(statusBar);

        retranslateUi(exam1Class);

        QMetaObject::connectSlotsByName(exam1Class);
    } // setupUi

    void retranslateUi(QMainWindow *exam1Class)
    {
        exam1Class->setWindowTitle(QApplication::translate("exam1Class", "exam1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class exam1Class: public Ui_exam1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAM1_H
