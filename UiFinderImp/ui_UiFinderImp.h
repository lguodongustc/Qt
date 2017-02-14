/********************************************************************************
** Form generated from reading UI file 'UiFinderImp.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include "UiImageViewerImp.h"

QT_BEGIN_NAMESPACE

class Ui_UiFinderImp
{
public:
    UiImageViewerImp *ImageLabel;
    QWidget *widget;
    QFormLayout *formLayout;
    QToolButton *BackButton;
    QToolButton *ForwardButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QColumnView *columnView;
    QWidget *page_2;
    QTreeView *treeView;
    QWidget *widget1;
    QFormLayout *formLayout_2;
    QToolButton *ColumnViewButton;
    QToolButton *TreeViewButton;

    void setupUi(QDialog *UiFinderImp)
    {
        if (UiFinderImp->objectName().isEmpty())
            UiFinderImp->setObjectName(QStringLiteral("UiFinderImp"));
        UiFinderImp->resize(724, 408);
        ImageLabel = new UiImageViewerImp(UiFinderImp);
        ImageLabel->setObjectName(QStringLiteral("ImageLabel"));
        ImageLabel->setGeometry(QRect(500, 38, 217, 363));
        widget = new QWidget(UiFinderImp);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(7, 7, 47, 26));
        formLayout = new QFormLayout(widget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        BackButton = new QToolButton(widget);
        BackButton->setObjectName(QStringLiteral("BackButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, BackButton);

        ForwardButton = new QToolButton(widget);
        ForwardButton->setObjectName(QStringLiteral("ForwardButton"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ForwardButton);

        stackedWidget = new QStackedWidget(UiFinderImp);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(7, 38, 488, 363));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        columnView = new QColumnView(page);
        columnView->setObjectName(QStringLiteral("columnView"));
        columnView->setGeometry(QRect(7, 0, 451, 361));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        treeView = new QTreeView(page_2);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setGeometry(QRect(7, 7, 441, 341));
        stackedWidget->addWidget(page_2);
        treeView->raise();
        ForwardButton->raise();
        BackButton->raise();
        widget1 = new QWidget(UiFinderImp);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(229, 8, 46, 26));
        formLayout_2 = new QFormLayout(widget1);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        ColumnViewButton = new QToolButton(widget1);
        ColumnViewButton->setObjectName(QStringLiteral("ColumnViewButton"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, ColumnViewButton);

        TreeViewButton = new QToolButton(widget1);
        TreeViewButton->setObjectName(QStringLiteral("TreeViewButton"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, TreeViewButton);


        retranslateUi(UiFinderImp);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UiFinderImp);
    } // setupUi

    void retranslateUi(QDialog *UiFinderImp)
    {
        UiFinderImp->setWindowTitle(QApplication::translate("UiFinderImp", "UiFinderImp", 0));
        ImageLabel->setText(QString());
        BackButton->setText(QApplication::translate("UiFinderImp", "<", 0));
        ForwardButton->setText(QApplication::translate("UiFinderImp", ">", 0));
        ColumnViewButton->setText(QApplication::translate("UiFinderImp", "|||", 0));
        TreeViewButton->setText(QApplication::translate("UiFinderImp", "-", 0));
    } // retranslateUi

};

namespace Ui {
    class UiFinderImp: public Ui_UiFinderImp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIFINDERIMP_H
