/********************************************************************************
** Form generated from reading UI file 'addnetsite.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNETSITE_H
#define UI_ADDNETSITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNetSite
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_5;
    QLabel *label_4;
    QLineEdit *description;
    QLineEdit *number;
    QLineEdit *name;
    QLabel *label_2;
    QLineEdit *status;
    QLabel *label_3;
    QLineEdit *authCode;
    QLabel *label_6;
    QPushButton *createAuthCode;
    QSpacerItem *horizontalSpacer_8;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *okBtn;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *cancleBtn;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QDialog *AddNetSite)
    {
        if (AddNetSite->objectName().isEmpty())
            AddNetSite->setObjectName(QString::fromUtf8("AddNetSite"));
        AddNetSite->resize(353, 265);
        verticalLayout = new QVBoxLayout(AddNetSite);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(AddNetSite);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(66, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(65, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(AddNetSite);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 6, 1, 1, 1);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 1, 1, 1);

        description = new QLineEdit(widget_2);
        description->setObjectName(QString::fromUtf8("description"));

        gridLayout->addWidget(description, 5, 2, 1, 1);

        number = new QLineEdit(widget_2);
        number->setObjectName(QString::fromUtf8("number"));

        gridLayout->addWidget(number, 1, 2, 1, 1);

        name = new QLineEdit(widget_2);
        name->setObjectName(QString::fromUtf8("name"));

        gridLayout->addWidget(name, 4, 2, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        status = new QLineEdit(widget_2);
        status->setObjectName(QString::fromUtf8("status"));

        gridLayout->addWidget(status, 8, 2, 1, 1);

        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 1, 1, 1);

        authCode = new QLineEdit(widget_2);
        authCode->setObjectName(QString::fromUtf8("authCode"));

        gridLayout->addWidget(authCode, 6, 2, 1, 1);

        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 8, 1, 1, 1);

        createAuthCode = new QPushButton(widget_2);
        createAuthCode->setObjectName(QString::fromUtf8("createAuthCode"));

        gridLayout->addWidget(createAuthCode, 6, 4, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 6, 5, 1, 1);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(AddNetSite);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        okBtn = new QPushButton(widget_3);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));

        horizontalLayout_2->addWidget(okBtn);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        cancleBtn = new QPushButton(widget_3);
        cancleBtn->setObjectName(QString::fromUtf8("cancleBtn"));

        horizontalLayout_2->addWidget(cancleBtn);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addWidget(widget_3);

        QWidget::setTabOrder(number, name);
        QWidget::setTabOrder(name, description);
        QWidget::setTabOrder(description, authCode);
        QWidget::setTabOrder(authCode, createAuthCode);
        QWidget::setTabOrder(createAuthCode, status);
        QWidget::setTabOrder(status, okBtn);
        QWidget::setTabOrder(okBtn, cancleBtn);

        retranslateUi(AddNetSite);

        QMetaObject::connectSlotsByName(AddNetSite);
    } // setupUi

    void retranslateUi(QDialog *AddNetSite)
    {
        AddNetSite->setWindowTitle(QCoreApplication::translate("AddNetSite", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddNetSite", "\350\257\267\350\276\223\345\205\245\347\275\221\347\202\271\344\277\241\346\201\257", nullptr));
        label_5->setText(QCoreApplication::translate("AddNetSite", "\347\275\221\347\202\271\346\216\210\346\235\203\347\240\201:", nullptr));
        label_4->setText(QCoreApplication::translate("AddNetSite", "\347\275\221\347\202\271\346\217\217\350\277\260:", nullptr));
        label_2->setText(QCoreApplication::translate("AddNetSite", "\347\275\221\347\202\271\347\274\226\345\217\267:", nullptr));
        label_3->setText(QCoreApplication::translate("AddNetSite", "\347\275\221\347\202\271\345\220\215\347\247\260:", nullptr));
        label_6->setText(QCoreApplication::translate("AddNetSite", "\347\275\221\347\202\271\347\212\266\346\200\201:", nullptr));
        createAuthCode->setText(QCoreApplication::translate("AddNetSite", "\347\224\237\346\210\220", nullptr));
        okBtn->setText(QCoreApplication::translate("AddNetSite", "\347\241\256\345\256\232", nullptr));
        cancleBtn->setText(QCoreApplication::translate("AddNetSite", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNetSite: public Ui_AddNetSite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNETSITE_H
