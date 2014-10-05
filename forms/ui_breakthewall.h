/********************************************************************************
** Form generated from reading UI file 'breakthewall.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREAKTHEWALL_H
#define UI_BREAKTHEWALL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BreakTheWall
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *Brk_rimanenti;
    QLabel *Brk_distrutti;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QLabel *Punti;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *BreakTheWall)
    {
        if (BreakTheWall->objectName().isEmpty())
            BreakTheWall->setObjectName(QStringLiteral("BreakTheWall"));
        BreakTheWall->resize(600, 700);
        verticalLayout = new QVBoxLayout(BreakTheWall);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(BreakTheWall);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 0, 111, 17));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 0, 121, 16));
        Brk_rimanenti = new QLabel(groupBox);
        Brk_rimanenti->setObjectName(QStringLiteral("Brk_rimanenti"));
        Brk_rimanenti->setGeometry(QRect(420, 0, 67, 17));
        Brk_distrutti = new QLabel(groupBox);
        Brk_distrutti->setObjectName(QStringLiteral("Brk_distrutti"));
        Brk_distrutti->setGeometry(QRect(150, 0, 67, 17));

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BreakTheWall);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 0, 582, 17));
        Punti = new QLabel(groupBox_2);
        Punti->setObjectName(QStringLiteral("Punti"));
        Punti->setGeometry(QRect(150, 0, 582, 17));

        verticalLayout->addWidget(groupBox_2);

        graphicsView = new QGraphicsView(BreakTheWall);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(graphicsView);


        retranslateUi(BreakTheWall);

        QMetaObject::connectSlotsByName(BreakTheWall);
    } // setupUi

    void retranslateUi(QDialog *BreakTheWall)
    {
        BreakTheWall->setWindowTitle(QApplication::translate("BreakTheWall", "Break The Wall", 0));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("BreakTheWall", "Brick Distrutti:", 0));
        label_2->setText(QApplication::translate("BreakTheWall", "Brick Rimanenti:", 0));
        Brk_rimanenti->setText(QString());
        Brk_distrutti->setText(QString());
        groupBox_2->setTitle(QString());
        label_3->setText(QApplication::translate("BreakTheWall", "Punteggio:", 0));
        Punti->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BreakTheWall: public Ui_BreakTheWall {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BREAKTHEWALL_H
