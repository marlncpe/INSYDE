/********************************************************************************
** Form generated from reading UI file 'adalinepage.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADALINEPAGE_H
#define UI_ADALINEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_AdalinePage
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QFormLayout *formLayout_4;
    QLabel *label_18;
    QLineEdit *lineEdit;
    QLabel *label_14;
    QSpinBox *spinBox_2;
    QLabel *label_16;
    QComboBox *comboBox_5;
    QLabel *label_17;
    QComboBox *comboBox_6;
    QFrame *line_5;
    QLabel *conjuntoDeEntranamientoLabel_2;
    QPushButton *pushButton_2;
    QGraphicsView *graphicsView;

    void setupUi(QWizardPage *AdalinePage)
    {
        if (AdalinePage->objectName().isEmpty())
            AdalinePage->setObjectName(QStringLiteral("AdalinePage"));
        AdalinePage->resize(630, 492);
        verticalLayout = new QVBoxLayout(AdalinePage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame = new QFrame(AdalinePage);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        formLayout_4 = new QFormLayout(frame);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_18);

        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEdit);

        label_14 = new QLabel(frame);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_14);

        spinBox_2 = new QSpinBox(frame);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(10000);
        spinBox_2->setValue(2);

        formLayout_4->setWidget(3, QFormLayout::FieldRole, spinBox_2);

        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_4->setWidget(4, QFormLayout::LabelRole, label_16);

        comboBox_5 = new QComboBox(frame);
        comboBox_5->setObjectName(QStringLiteral("comboBox_5"));

        formLayout_4->setWidget(4, QFormLayout::FieldRole, comboBox_5);

        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_4->setWidget(5, QFormLayout::LabelRole, label_17);

        comboBox_6 = new QComboBox(frame);
        comboBox_6->setObjectName(QStringLiteral("comboBox_6"));

        formLayout_4->setWidget(5, QFormLayout::FieldRole, comboBox_6);

        line_5 = new QFrame(frame);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        formLayout_4->setWidget(7, QFormLayout::SpanningRole, line_5);

        conjuntoDeEntranamientoLabel_2 = new QLabel(frame);
        conjuntoDeEntranamientoLabel_2->setObjectName(QStringLiteral("conjuntoDeEntranamientoLabel_2"));

        formLayout_4->setWidget(8, QFormLayout::LabelRole, conjuntoDeEntranamientoLabel_2);

        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        formLayout_4->setWidget(8, QFormLayout::FieldRole, pushButton_2);


        verticalLayout->addWidget(frame);

        graphicsView = new QGraphicsView(AdalinePage);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        verticalLayout->addWidget(graphicsView);


        retranslateUi(AdalinePage);

        QMetaObject::connectSlotsByName(AdalinePage);
    } // setupUi

    void retranslateUi(QWizardPage *AdalinePage)
    {
        AdalinePage->setWindowTitle(QApplication::translate("AdalinePage", "WizardPage", 0));
        label_18->setText(QApplication::translate("AdalinePage", "Nombre", 0));
        lineEdit->setText(QApplication::translate("AdalinePage", "adaline", 0));
        lineEdit->setPlaceholderText(QString());
        label_14->setText(QApplication::translate("AdalinePage", "Numero de entradas", 0));
        label_16->setText(QApplication::translate("AdalinePage", "Funci\303\263n de transferencia", 0));
        comboBox_5->clear();
        comboBox_5->insertItems(0, QStringList()
         << QApplication::translate("AdalinePage", "Lineal", 0)
         << QApplication::translate("AdalinePage", "Sigmoide", 0)
         << QApplication::translate("AdalinePage", "Tangente hiperbolica", 0)
         << QApplication::translate("AdalinePage", "Lineal limitada unipolar", 0)
         << QApplication::translate("AdalinePage", "Lineal limitada bipolar", 0)
        );
        label_17->setText(QApplication::translate("AdalinePage", "Actualizaci\303\263n de pesos", 0));
        comboBox_6->clear();
        comboBox_6->insertItems(0, QStringList()
         << QApplication::translate("AdalinePage", "Sincrona", 0)
         << QApplication::translate("AdalinePage", "Asincrona", 0)
        );
        conjuntoDeEntranamientoLabel_2->setText(QApplication::translate("AdalinePage", "Conjunto de entranamiento", 0));
        pushButton_2->setText(QApplication::translate("AdalinePage", "Asignar", 0));
    } // retranslateUi

};

namespace Ui {
    class AdalinePage: public Ui_AdalinePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADALINEPAGE_H
