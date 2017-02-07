#include "QtFileExplorer.h"
#include "ui_QtFileExplorer.h"

QtFileExplorer::QtFileExplorer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtFileExplorer)
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

    /*
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
    ui->treeView->resizeColumnToContents(0);*/
}

QtFileExplorer::~QtFileExplorer()
{
    delete ui;
}

void QtFileExplorer::dragEnterEvent(QDragEnterEvent*event){
//如果类型是jpg或者png才能接受拖动。
//这里的compare字符串比较函数，相等的时候返回0，所以要取反
   if(!event->mimeData()->urls()[0].fileName().right(3).compare("jpg")
           ||!event->mimeData()->urls()[0].fileName().right(3).compare("png"))
       event->acceptProposedAction();
    else
       event->ignore();//否则不接受鼠标事件
}

void QtFileExplorer::dropEvent(QDropEvent*event){
    const QMimeData*qm=event->mimeData();//获取MIMEData
    QPixmap qp(qm->urls()[0].toLocalFile());//toLocalFile()是获取拖动文件的本地路径。
    QFileInfo fileInfo(qm->urls()[0].toLocalFile());

    std::cout << qPrintable(fileInfo.path()) << std::endl;
    ui->imageLabel->resize(qp.width(),qp.height());//让label大小契合图片实际大小
    ui->imageLabel->setPixmap(qp);//显示图片
    ui->listView->setRootIndex(fileModel->setRootPath(fileInfo.path()));
    ui->treeView->setCurrentIndex(fileModel->setRootPath(fileInfo.path()));
}

void QtFileExplorer::on_treeView_clicked(const QModelIndex &index)
{
    QString rootPath = dirModel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(fileModel->setRootPath(rootPath));
}

void QtFileExplorer::on_listView_clicked(const QModelIndex &index)
{
    QStringList filters;
    filters << "*.bmp" << "*.jpg" << "*.png" << "*.jpeg";

    QDir dir(fileModel->fileInfo(index).absolutePath());
    dir.setNameFilters(filters);

    std::cout << qPrintable(dir.dirName()) << std::endl;

    QStringList fileList = dir.entryList();

    std::cout << fileList.size() << std::endl;
    if(fileList.size()) {
        QImage image(fileModel->fileInfo(index).absoluteFilePath());
        ui->imageLabel->setPixmap(QPixmap::fromImage(image));
    }
}
