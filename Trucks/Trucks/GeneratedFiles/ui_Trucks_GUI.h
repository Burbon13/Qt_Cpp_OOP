/********************************************************************************
** Form generated from reading UI file 'Trucks_GUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRUCKS_GUI_H
#define UI_TRUCKS_GUI_H

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

class Ui_Trucks_GUIClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Trucks_GUIClass)
    {
        if (Trucks_GUIClass->objectName().isEmpty())
            Trucks_GUIClass->setObjectName(QStringLiteral("Trucks_GUIClass"));
        Trucks_GUIClass->resize(600, 400);
        menuBar = new QMenuBar(Trucks_GUIClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        Trucks_GUIClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Trucks_GUIClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Trucks_GUIClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Trucks_GUIClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Trucks_GUIClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Trucks_GUIClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Trucks_GUIClass->setStatusBar(statusBar);

        retranslateUi(Trucks_GUIClass);

        QMetaObject::connectSlotsByName(Trucks_GUIClass);
    } // setupUi

    void retranslateUi(QMainWindow *Trucks_GUIClass)
    {
        Trucks_GUIClass->setWindowTitle(QApplication::translate("Trucks_GUIClass", "Trucks_GUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Trucks_GUIClass: public Ui_Trucks_GUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRUCKS_GUI_H
