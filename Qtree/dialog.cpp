#include "dialog.h"
#include "ui_dialog.h"

#include <QInputDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    model = new QDirModel(this);
    //setReadOnly()设置目录模型是否可写
    model->setReadOnly(false);
    //设置目录模型按照一定的规则进行排列
    model->setSorting(QDir::DirsFirst | QDir::IgnoreCase | QDir::Name);
    //设置模式
    ui->treeView->setModel(model);
    //QModelIndex类用于定位在数据模型中的数据
    QModelIndex index = model->index("/");

    ui->treeView->expand(index);//展开所有可展开的项
    //scrollTo滚动树视图中的内容，直到给定的模型项目的索引是可见的。
    ui->treeView->scrollTo(index);
    //设置当前索引为index
    ui->treeView->setCurrentIndex(index);
    //设置当前列的宽度
    ui->treeView->resizeColumnToContents(0);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_delete_2_clicked()
{
    //delete
    QModelIndex index = ui->treeView->currentIndex();
    if(!index.isValid()) return;
    //根据对象类型进行相应操作
    if(model->fileInfo(index).isDir())
    {
        //Dir 如果是目录
        model->rmdir(index);
    }
    else
    {
        //File 如果是文件
        model->remove(index);
    }
}

void Dialog::on_makedir_clicked()
{
    //make dir
    //确定当前项的索引
    QModelIndex index = ui->treeView->currentIndex();
    //判断索引是否合法
    if(!index.isValid()) return;
    //读取输入文字
    //QInputDialog类通过提供一个简单便捷的对话框来从用户处获得信息
    QString name = QInputDialog::getText(this,"Name","Enter a name:");
    //判断目录名是否为空
    if(name.isEmpty()) return;
    //新建目录
    model->mkdir(index , name);
}

void Dialog::on_treeView_clicked(const QModelIndex &index)
{
    QStringList filters;
    filters << "*.bmp" << "*.jpg" << "*.png" << "*.jpeg";

    QDir dir(model->fileInfo(index).absolutePath());
    dir.setNameFilters(filters);

    std::cout << qPrintable(dir.dirName()) << std::endl;

    QStringList fileList = dir.entryList();

    std::cout << fileList.size() << std::endl;
    if(fileList.size()) {
        QImage image(model->fileInfo(index).absoluteFilePath());
        ui->imageLabel->setPixmap(QPixmap::fromImage(image));
    }
}
