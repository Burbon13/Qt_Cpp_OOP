/********************************************************************************
** Form generated from reading UI file 'SongGUI.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGGUI_H
#define UI_SONGGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SongGUIClass
{
public:

    void setupUi(QWidget *SongGUIClass)
    {
        if (SongGUIClass->objectName().isEmpty())
            SongGUIClass->setObjectName(QStringLiteral("SongGUIClass"));
        SongGUIClass->resize(600, 400);

        retranslateUi(SongGUIClass);

        QMetaObject::connectSlotsByName(SongGUIClass);
    } // setupUi

    void retranslateUi(QWidget *SongGUIClass)
    {
        SongGUIClass->setWindowTitle(QApplication::translate("SongGUIClass", "SongGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SongGUIClass: public Ui_SongGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGGUI_H
