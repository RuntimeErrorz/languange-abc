/********************************************************************************
** Form generated from reading UI file 'unit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNIT_H
#define UI_UNIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_unit
{
public:
    QFormLayout *formLayout;
    QPushButton *HumanResources;
    QPushButton *Accounting;
    QPushButton *Sales;
    QPushButton *pushButton_4;

    void setupUi(QDialog *unit)
    {
        if (unit->objectName().isEmpty())
            unit->setObjectName(QString::fromUtf8("unit"));
        unit->resize(621, 485);
        formLayout = new QFormLayout(unit);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        HumanResources = new QPushButton(unit);
        HumanResources->setObjectName(QString::fromUtf8("HumanResources"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HumanResources->sizePolicy().hasHeightForWidth());
        HumanResources->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::SpanningRole, HumanResources);

        Accounting = new QPushButton(unit);
        Accounting->setObjectName(QString::fromUtf8("Accounting"));
        sizePolicy.setHeightForWidth(Accounting->sizePolicy().hasHeightForWidth());
        Accounting->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::SpanningRole, Accounting);

        Sales = new QPushButton(unit);
        Sales->setObjectName(QString::fromUtf8("Sales"));
        sizePolicy.setHeightForWidth(Sales->sizePolicy().hasHeightForWidth());
        Sales->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::SpanningRole, Sales);

        pushButton_4 = new QPushButton(unit);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::SpanningRole, pushButton_4);


        retranslateUi(unit);

        QMetaObject::connectSlotsByName(unit);
    } // setupUi

    void retranslateUi(QDialog *unit)
    {
        unit->setWindowTitle(QCoreApplication::translate("unit", "Dialog", nullptr));
        HumanResources->setText(QCoreApplication::translate("unit", "HumanResources", nullptr));
        Accounting->setText(QCoreApplication::translate("unit", "Accounting", nullptr));
        Sales->setText(QCoreApplication::translate("unit", "Sales", nullptr));
        pushButton_4->setText(QCoreApplication::translate("unit", "Administration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class unit: public Ui_unit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNIT_H
