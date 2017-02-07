#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QString rootPath = "/";
    dirModel = new QFileSystemModel(this);
    dirModel->setRootPath(rootPath);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    ui->treeView->setModel(dirModel);

    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath(rootPath);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);

    ui->listView->setModel(fileModel);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_treeView_clicked(const QModelIndex &index)
{
    QString rootPath = dirModel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(fileModel->setRootPath(rootPath));
}
