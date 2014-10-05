/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QWidget *centralWidget;
    QPushButton *HowToPlay;
    QPushButton *Exit;
    QPushButton *StartGame;
    QPushButton *TopScores;

    void setupUi(QMainWindow *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QStringLiteral("Menu"));
        Menu->setEnabled(true);
        Menu->resize(500, 500);
        QFont font;
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferAntialias);
        Menu->setFont(font);
        centralWidget = new QWidget(Menu);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        HowToPlay = new QPushButton(centralWidget);
        HowToPlay->setObjectName(QStringLiteral("HowToPlay"));
        HowToPlay->setGeometry(QRect(175, 190, 150, 50));
        Exit = new QPushButton(centralWidget);
        Exit->setObjectName(QStringLiteral("Exit"));
        Exit->setGeometry(QRect(175, 330, 150, 50));
        StartGame = new QPushButton(centralWidget);
        StartGame->setObjectName(QStringLiteral("StartGame"));
        StartGame->setGeometry(QRect(175, 120, 150, 50));
        TopScores = new QPushButton(centralWidget);
        TopScores->setObjectName(QStringLiteral("TopScores"));
        TopScores->setGeometry(QRect(175, 260, 150, 50));
        Menu->setCentralWidget(centralWidget);

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QMainWindow *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Menu", 0));
        HowToPlay->setText(QApplication::translate("Menu", "How to play", 0));
        Exit->setText(QApplication::translate("Menu", "Exit", 0));
        StartGame->setText(QApplication::translate("Menu", "Start Game", 0));
        TopScores->setText(QApplication::translate("Menu", "Top Scores", 0));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
