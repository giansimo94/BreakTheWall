/********************************************************************************
** Form generated from reading UI file 'topscores.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPSCORES_H
#define UI_TOPSCORES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TopScores
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QVBoxLayout *verticalLayout;
    QPushButton *Azzera;
    QPushButton *Esci;

    void setupUi(QDialog *TopScores)
    {
        if (TopScores->objectName().isEmpty())
            TopScores->setObjectName(QStringLiteral("TopScores"));
        TopScores->resize(255, 420);
        horizontalLayout = new QHBoxLayout(TopScores);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView = new QTableView(TopScores);
        tableView->setObjectName(QStringLiteral("tableView"));
#ifndef QT_NO_STATUSTIP
        tableView->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        tableView->setWhatsThis(QStringLiteral(""));
#endif // QT_NO_WHATSTHIS
        tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(tableView);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Azzera = new QPushButton(TopScores);
        Azzera->setObjectName(QStringLiteral("Azzera"));

        verticalLayout->addWidget(Azzera);

        Esci = new QPushButton(TopScores);
        Esci->setObjectName(QStringLiteral("Esci"));

        verticalLayout->addWidget(Esci);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(TopScores);

        QMetaObject::connectSlotsByName(TopScores);
    } // setupUi

    void retranslateUi(QDialog *TopScores)
    {
        TopScores->setWindowTitle(QApplication::translate("TopScores", "Top Scores", 0));
        Azzera->setText(QApplication::translate("TopScores", "Azzera", 0));
        Esci->setText(QApplication::translate("TopScores", "Esci", 0));
    } // retranslateUi

};

namespace Ui {
    class TopScores: public Ui_TopScores {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPSCORES_H
