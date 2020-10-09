/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QPushButton *pushButton;
    QFrame *line;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox;
    QDoubleSpinBox *doubleSpinBox_2;
    QPushButton *pushButton_2;
    QFrame *line_2;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_6;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1800, 900);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 1804, 945));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(1600, 900));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(label);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(3, 3, 3, 3);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(194, 35));
        pushButton->setMaximumSize(QSize(180, 35));

        verticalLayout->addWidget(pushButton);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);

        doubleSpinBox = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setMinimumSize(QSize(194, 35));
        doubleSpinBox->setMaximumSize(QSize(180, 35));
        doubleSpinBox->setLayoutDirection(Qt::LeftToRight);
        doubleSpinBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(doubleSpinBox);

        doubleSpinBox_2 = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));

        verticalLayout->addWidget(doubleSpinBox_2);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        line_2 = new QFrame(horizontalLayoutWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        doubleSpinBox_3 = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));

        verticalLayout->addWidget(doubleSpinBox_3);

        doubleSpinBox_4 = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));

        verticalLayout->addWidget(doubleSpinBox_4);

        doubleSpinBox_5 = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));

        verticalLayout->addWidget(doubleSpinBox_5);

        doubleSpinBox_6 = new QDoubleSpinBox(horizontalLayoutWidget);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));

        verticalLayout->addWidget(doubleSpinBox_6);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\246\201\345\270\246\345\256\275\345\272\246\345\244\204\347\220\206\347\250\213\345\272\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\275\254\345\214\226\345\233\276\345\203\217", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\350\275\254\345\214\226", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "x\350\275\264\347\274\251\346\224\276", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\347\274\251\346\224\276", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\347\272\277\346\200\247\346\213\237\345\220\210", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\347\202\271\345\207\273\346\213\237\345\220\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
