#include "QTColumnView.h"
#include "ui_QTColumnView.h"

QTColumnView::QTColumnView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QTColumnView)
{
    ui->setupUi(this);
}

QTColumnView::~QTColumnView()
{
    delete ui;
}
