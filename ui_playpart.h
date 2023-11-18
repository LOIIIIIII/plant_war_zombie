/********************************************************************************
** Form generated from reading UI file 'playpart.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYPART_H
#define UI_PLAYPART_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Playpart
{
public:
    QLabel *label;
    QLabel *shop;

    void setupUi(QWidget *Playpart)
    {
        if (Playpart->objectName().isEmpty())
            Playpart->setObjectName("Playpart");
        Playpart->resize(1000, 600);
        label = new QLabel(Playpart);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1000, 600));
        shop = new QLabel(Playpart);
        shop->setObjectName("shop");
        shop->setGeometry(QRect(250, -110, 600, 300));

        retranslateUi(Playpart);

        QMetaObject::connectSlotsByName(Playpart);
    } // setupUi

    void retranslateUi(QWidget *Playpart)
    {
        Playpart->setWindowTitle(QCoreApplication::translate("Playpart", "Form", nullptr));
        label->setText(QString());
        shop->setText(QCoreApplication::translate("Playpart", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Playpart: public Ui_Playpart {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYPART_H
