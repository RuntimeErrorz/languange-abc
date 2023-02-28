/********************************************************************************
** Form generated from reading UI file 'summary.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMMARY_H
#define UI_SUMMARY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_summary
{
public:
    QFormLayout *formLayout;
    QPushButton *gender;
    QPushButton *unit;
    QPushButton *title;

    void setupUi(QDialog *summary)
    {
        if (summary->objectName().isEmpty())
            summary->setObjectName(QString::fromUtf8("summary"));
        summary->resize(346, 293);
        formLayout = new QFormLayout(summary);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        gender = new QPushButton(summary);
        gender->setObjectName(QString::fromUtf8("gender"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gender->sizePolicy().hasHeightForWidth());
        gender->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::SpanningRole, gender);

        unit = new QPushButton(summary);
        unit->setObjectName(QString::fromUtf8("unit"));
        sizePolicy.setHeightForWidth(unit->sizePolicy().hasHeightForWidth());
        unit->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::SpanningRole, unit);

        title = new QPushButton(summary);
        title->setObjectName(QString::fromUtf8("title"));
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::SpanningRole, title);


        retranslateUi(summary);

        QMetaObject::connectSlotsByName(summary);
    } // setupUi

    void retranslateUi(QDialog *summary)
    {
        summary->setWindowTitle(QCoreApplication::translate("summary", "Dialog", nullptr));
        gender->setText(QCoreApplication::translate("summary", "gender", nullptr));
        unit->setText(QCoreApplication::translate("summary", "unit", nullptr));
        title->setText(QCoreApplication::translate("summary", "title", nullptr));
    } // retranslateUi

};

namespace Ui {
    class summary: public Ui_summary {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMMARY_H
