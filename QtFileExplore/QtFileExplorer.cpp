#include "QtFileExplorer.h"
#include "ui_QtFileExplorer.h"

QtFileExplorer::QtFileExplorer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtFileExplorer)
{
    ui->setupUi(this);
    //timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this, SLOT(on_listView_clicked(const QModelIndex &)));


    QString rootPath = "/";
    dirModel = new QFileSystemModel(this);
    dirModel->setRootPath(rootPath);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    ui->treeView->setModel(dirModel);
    ui->treeView->setHeaderHidden(true);
    ui->treeView->hideColumn(1);
    ui->treeView->hideColumn(2);
    ui->treeView->hideColumn(3);

    fileModel = new QFileSystemModel(this);
    fileModel->setRootPath(rootPath);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);
    ui->listView->setModel(fileModel);
    ui->listView->setHeaderHidden(true);
    ui->listView->hideColumn(1);
    ui->listView->hideColumn(2);
    ui->listView->hideColumn(3);
}

QtFileExplorer::~QtFileExplorer()
{
    delete ui;
}

void QtFileExplorer::dragEnterEvent(QDragEnterEvent *event)
{
   if(!event->mimeData()->urls()[0].fileName().right(3).compare("jpg")
           ||!event->mimeData()->urls()[0].fileName().right(3).compare("png")
           ||!event->mimeData()->urls()[0].fileName().right(3).compare("bmp")
           ||!event->mimeData()->urls()[0].fileName().right(4).compare("jpeg"))
       event->acceptProposedAction();
    else
       event->ignore();
}

void QtFileExplorer::dropEvent(QDropEvent *event)
{
    const QMimeData *qm = event->mimeData();
    image = new QPixmap(qm->urls()[0].toLocalFile());
    QFileInfo fileInfo(qm->urls()[0].toLocalFile());

    std::cout << qPrintable(fileInfo.absoluteFilePath()) << std::endl;
    ui->imageLabel->setPixmap(image->scaled(image->width()/2, image->height()/2, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->imageLabel->setScaledContents(true);
    ui->imageLabel->setMinimumSize(1, 1);

    ui->treeView->scrollTo(dirModel->index(fileInfo.path()));
    ui->treeView->setCurrentIndex(dirModel->index(fileInfo.path()));

    ui->listView->setRootIndex(fileModel->index(fileInfo.path()));
    ui->listView->setCurrentIndex(fileModel->index(fileInfo.filePath()));
}

void QtFileExplorer::resizeEvent(QResizeEvent *event){
    if(image){
        ui->imageLabel->setPixmap(image->scaled(image->width()/2, image->height()/2, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->imageLabel->setScaledContents(true);
        ui->imageLabel->setMinimumSize(1, 1);
    }
}

void QtFileExplorer::on_treeView_clicked(const QModelIndex &index)
{
    QString rootPath = dirModel->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(fileModel->index(rootPath));
}

void QtFileExplorer::on_listView_clicked(const QModelIndex &index)
{
    /*
    //isDoubleClicked = false;
    //timer->stop();
    QFileIconProvider icon_provider;
    QFileInfo fileInfo(fileModel->fileInfo(index).absoluteFilePath());
    std::cout << qPrintable(fileModel->fileInfo(index).absoluteFilePath()) << std::endl;
    QIcon icon = icon_provider.icon(fileInfo);
    ui->imageLabel->setPixmap(icon.pixmap(QSize(64, 64)));
    */
}

void QtFileExplorer::on_listView_doubleClicked(const QModelIndex &index)
{
    QStringList filters;
    filters << "*.bmp" << "*.jpg" << "*.png" << "*.jpeg";

    QDir dir(fileModel->fileInfo(index).absolutePath());
    dir.setNameFilters(filters);

    std::cout << qPrintable(dir.dirName()) << std::endl;

    QStringList fileList = dir.entryList();

    std::cout << fileList.size() << std::endl;
    if(fileList.size()) {
        image = new QPixmap(fileModel->fileInfo(index).absoluteFilePath());
        ui->imageLabel->setPixmap(image->scaled(image->width()/2, image->height()/2, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->imageLabel->setScaledContents(true);
        ui->imageLabel->setMinimumSize(1, 1);
    }
    else image=NULL;
}
