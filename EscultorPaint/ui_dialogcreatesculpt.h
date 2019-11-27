/********************************************************************************
** Form generated from reading UI file 'dialogcreatesculpt.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCREATESCULPT_H
#define UI_DIALOGCREATESCULPT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogCreateSculpt
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *nxLabel;
    QSpinBox *nxSpinBox;
    QLabel *nyLabel;
    QSpinBox *nySpinBox;
    QLabel *nzLabel;
    QSpinBox *nzSpinBox;
    QLabel *label;

    void setupUi(QDialog *DialogCreateSculpt)
    {
        if (DialogCreateSculpt->objectName().isEmpty())
            DialogCreateSculpt->setObjectName(QStringLiteral("DialogCreateSculpt"));
        DialogCreateSculpt->resize(427, 183);
        buttonBox = new QDialogButtonBox(DialogCreateSculpt);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 140, 371, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(DialogCreateSculpt);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 30, 381, 111));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        nxLabel = new QLabel(formLayoutWidget);
        nxLabel->setObjectName(QStringLiteral("nxLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nxLabel);

        nxSpinBox = new QSpinBox(formLayoutWidget);
        nxSpinBox->setObjectName(QStringLiteral("nxSpinBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nxSpinBox);

        nyLabel = new QLabel(formLayoutWidget);
        nyLabel->setObjectName(QStringLiteral("nyLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, nyLabel);

        nySpinBox = new QSpinBox(formLayoutWidget);
        nySpinBox->setObjectName(QStringLiteral("nySpinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, nySpinBox);

        nzLabel = new QLabel(formLayoutWidget);
        nzLabel->setObjectName(QStringLiteral("nzLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, nzLabel);

        nzSpinBox = new QSpinBox(formLayoutWidget);
        nzSpinBox->setObjectName(QStringLiteral("nzSpinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, nzSpinBox);

        label = new QLabel(DialogCreateSculpt);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 0, 261, 17));

        retranslateUi(DialogCreateSculpt);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogCreateSculpt, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogCreateSculpt, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogCreateSculpt);
    } // setupUi

    void retranslateUi(QDialog *DialogCreateSculpt)
    {
        DialogCreateSculpt->setWindowTitle(QApplication::translate("DialogCreateSculpt", "Dialog", Q_NULLPTR));
        nxLabel->setText(QApplication::translate("DialogCreateSculpt", "nx", Q_NULLPTR));
        nyLabel->setText(QApplication::translate("DialogCreateSculpt", "ny", Q_NULLPTR));
        nzLabel->setText(QApplication::translate("DialogCreateSculpt", "nz", Q_NULLPTR));
        label->setText(QApplication::translate("DialogCreateSculpt", "Dimens\303\265es da escultura", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogCreateSculpt: public Ui_DialogCreateSculpt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCREATESCULPT_H
