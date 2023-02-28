/********************************************************************************
** Form generated from reading UI file 'mainone.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINONE_H
#define UI_MAINONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_mainone
{
public:
    QFormLayout *formLayout;
    QGridLayout *gridLayout_4;
    QPushButton *SumButton;
    QPushButton *DeleteButton;
    QPushButton *ChangeButton;
    QPushButton *QuitButton;
    QPushButton *DisplayButton;
    QPushButton *AddButton;
    QPushButton *SearchButton;

    void setupUi(QDialog *mainone)
    {
        if (mainone->objectName().isEmpty())
            mainone->setObjectName(QString::fromUtf8("mainone"));
        mainone->resize(771, 539);
        formLayout = new QFormLayout(mainone);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        SumButton = new QPushButton(mainone);
        SumButton->setObjectName(QString::fromUtf8("SumButton"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SumButton->sizePolicy().hasHeightForWidth());
        SumButton->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(SumButton, 10, 0, 1, 1);

        DeleteButton = new QPushButton(mainone);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        sizePolicy.setHeightForWidth(DeleteButton->sizePolicy().hasHeightForWidth());
        DeleteButton->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(DeleteButton, 3, 0, 1, 1);

        ChangeButton = new QPushButton(mainone);
        ChangeButton->setObjectName(QString::fromUtf8("ChangeButton"));
        sizePolicy.setHeightForWidth(ChangeButton->sizePolicy().hasHeightForWidth());
        ChangeButton->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(ChangeButton, 5, 0, 1, 1);

        QuitButton = new QPushButton(mainone);
        QuitButton->setObjectName(QString::fromUtf8("QuitButton"));
        QuitButton->setEnabled(true);
        sizePolicy.setHeightForWidth(QuitButton->sizePolicy().hasHeightForWidth());
        QuitButton->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(QuitButton, 11, 0, 1, 1);

        DisplayButton = new QPushButton(mainone);
        DisplayButton->setObjectName(QString::fromUtf8("DisplayButton"));
        DisplayButton->setEnabled(true);
        sizePolicy.setHeightForWidth(DisplayButton->sizePolicy().hasHeightForWidth());
        DisplayButton->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(DisplayButton, 0, 0, 1, 1);

        AddButton = new QPushButton(mainone);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        sizePolicy.setHeightForWidth(AddButton->sizePolicy().hasHeightForWidth());
        AddButton->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(AddButton, 2, 0, 1, 1);

        SearchButton = new QPushButton(mainone);
        SearchButton->setObjectName(QString::fromUtf8("SearchButton"));
        SearchButton->setEnabled(true);
        sizePolicy.setHeightForWidth(SearchButton->sizePolicy().hasHeightForWidth());
        SearchButton->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(SearchButton, 4, 0, 1, 1);


        formLayout->setLayout(0, QFormLayout::SpanningRole, gridLayout_4);

        QWidget::setTabOrder(DisplayButton, AddButton);
        QWidget::setTabOrder(AddButton, DeleteButton);
        QWidget::setTabOrder(DeleteButton, SearchButton);
        QWidget::setTabOrder(SearchButton, ChangeButton);
        QWidget::setTabOrder(ChangeButton, SumButton);
        QWidget::setTabOrder(SumButton, QuitButton);

        retranslateUi(mainone);

        QMetaObject::connectSlotsByName(mainone);
    } // setupUi

    void retranslateUi(QDialog *mainone)
    {
        mainone->setWindowTitle(QCoreApplication::translate("mainone", "Dialog", nullptr));
        SumButton->setText(QCoreApplication::translate("mainone", "Summaize", nullptr));
        DeleteButton->setText(QCoreApplication::translate("mainone", "Delete", nullptr));
        ChangeButton->setText(QCoreApplication::translate("mainone", "Change", nullptr));
        QuitButton->setText(QCoreApplication::translate("mainone", "quit", nullptr));
        DisplayButton->setText(QCoreApplication::translate("mainone", "Display", nullptr));
        AddButton->setText(QCoreApplication::translate("mainone", "Add", nullptr));
        SearchButton->setText(QCoreApplication::translate("mainone", "Search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainone: public Ui_mainone {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINONE_H
