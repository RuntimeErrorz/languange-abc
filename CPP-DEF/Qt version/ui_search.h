/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_search
{
public:
    QFormLayout *formLayout;
    QPushButton *eid;
    QPushButton *name;
    QPushButton *unit;
    QPushButton *title;
    QPushButton *salary;

    void setupUi(QDialog *search)
    {
        if (search->objectName().isEmpty())
            search->setObjectName(QString::fromUtf8("search"));
        search->resize(537, 413);
        formLayout = new QFormLayout(search);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        eid = new QPushButton(search);
        eid->setObjectName(QString::fromUtf8("eid"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(eid->sizePolicy().hasHeightForWidth());
        eid->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::SpanningRole, eid);

        name = new QPushButton(search);
        name->setObjectName(QString::fromUtf8("name"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy1);

        formLayout->setWidget(1, QFormLayout::SpanningRole, name);

        unit = new QPushButton(search);
        unit->setObjectName(QString::fromUtf8("unit"));
        sizePolicy.setHeightForWidth(unit->sizePolicy().hasHeightForWidth());
        unit->setSizePolicy(sizePolicy);

        formLayout->setWidget(2, QFormLayout::SpanningRole, unit);

        title = new QPushButton(search);
        title->setObjectName(QString::fromUtf8("title"));
        sizePolicy.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy);

        formLayout->setWidget(3, QFormLayout::SpanningRole, title);

        salary = new QPushButton(search);
        salary->setObjectName(QString::fromUtf8("salary"));
        sizePolicy.setHeightForWidth(salary->sizePolicy().hasHeightForWidth());
        salary->setSizePolicy(sizePolicy);

        formLayout->setWidget(4, QFormLayout::SpanningRole, salary);


        retranslateUi(search);

        QMetaObject::connectSlotsByName(search);
    } // setupUi

    void retranslateUi(QDialog *search)
    {
        search->setWindowTitle(QCoreApplication::translate("search", "Dialog", nullptr));
        eid->setText(QCoreApplication::translate("search", "eid", nullptr));
        name->setText(QCoreApplication::translate("search", "name", nullptr));
        unit->setText(QCoreApplication::translate("search", "unit", nullptr));
        title->setText(QCoreApplication::translate("search", "title", nullptr));
        salary->setText(QCoreApplication::translate("search", "salary", nullptr));
    } // retranslateUi

};

namespace Ui {
    class search: public Ui_search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
