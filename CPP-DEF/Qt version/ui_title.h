/********************************************************************************
** Form generated from reading UI file 'title.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLE_H
#define UI_TITLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_title
{
public:
    QFormLayout *formLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;

    void setupUi(QDialog *title)
    {
        if (title->objectName().isEmpty())
            title->setObjectName(QString::fromUtf8("title"));
        title->resize(594, 502);
        formLayout = new QFormLayout(title);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        pushButton_2 = new QPushButton(title);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::SpanningRole, pushButton_2);

        pushButton = new QPushButton(title);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        formLayout->setWidget(1, QFormLayout::SpanningRole, pushButton);

        pushButton_5 = new QPushButton(title);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::SpanningRole, pushButton_5);

        pushButton_4 = new QPushButton(title);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::SpanningRole, pushButton_4);

        pushButton_3 = new QPushButton(title);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::SpanningRole, pushButton_3);


        retranslateUi(title);

        QMetaObject::connectSlotsByName(title);
    } // setupUi

    void retranslateUi(QDialog *title)
    {
        title->setWindowTitle(QCoreApplication::translate("title", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("title", "Manager", nullptr));
        pushButton->setText(QCoreApplication::translate("title", "HRSpecialist", nullptr));
        pushButton_5->setText(QCoreApplication::translate("title", "TreasuryAttache", nullptr));
        pushButton_4->setText(QCoreApplication::translate("title", "SalesExecutive", nullptr));
        pushButton_3->setText(QCoreApplication::translate("title", "AdministrativeCommissioner", nullptr));
    } // retranslateUi

};

namespace Ui {
    class title: public Ui_title {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLE_H
