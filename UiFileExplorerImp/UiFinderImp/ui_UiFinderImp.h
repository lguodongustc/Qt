/********************************************************************************
** Form generated from reading UI file 'UiFinderImp.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIFINDERIMP_H
#define UI_UIFINDERIMP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QColumnView>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include "UiImageViewerImp.h"

QT_BEGIN_NAMESPACE

class Ui_UiFinderImp
{
public:
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QTreeView *treeView;
    QWidget *page_2;
    QGridLayout *gridLayout;
    QColumnView *columnView;
    UiImageViewerImp *frame;

    void setupUi(QDialog *UiFinderImp)
    {
        if (UiFinderImp->objectName().isEmpty())
            UiFinderImp->setObjectName(QStringLiteral("UiFinderImp"));
        UiFinderImp->resize(481, 300);
        gridLayout_3 = new QGridLayout(UiFinderImp);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(UiFinderImp);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(UiFinderImp);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(UiFinderImp);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        stackedWidget = new QStackedWidget(UiFinderImp);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        treeView = new QTreeView(page);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(90, 50, 256, 192));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout = new QGridLayout(page_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        columnView = new QColumnView(page_2);
        columnView->setObjectName(QStringLiteral("columnView"));

        gridLayout->addWidget(columnView, 0, 1, 1, 1);

        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);

        frame = new UiImageViewerImp(UiFinderImp);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(frame, 0, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);


        retranslateUi(UiFinderImp);

        QMetaObject::connectSlotsByName(UiFinderImp);
    } // setupUi

    void retranslateUi(QDialog *UiFinderImp)
    {
        UiFinderImp->setWindowTitle(QApplication::translate("UiFinderImp", "Finder", 0));
        pushButton_2->setText(QApplication::translate("UiFinderImp", "PushButton", 0));
        pushButton->setText(QApplication::translate("UiFinderImp", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("UiFinderImp", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class UiFinderImp: public Ui_UiFinderImp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIFINDERIMP_H
