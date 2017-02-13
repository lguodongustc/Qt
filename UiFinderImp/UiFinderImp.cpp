#include "UiFinderImp.h"
#include "ui_UiFinderImp.h"

UiFinderImp::UiFinderImp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UiFinderImp)
{
    ui->setupUi(this);
}

UiFinderImp::~UiFinderImp()
{
    delete ui;
}
