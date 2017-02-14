#include <QFileSystemModel>

#include "UiFinderImp.h"

#include "ui_UiFinderImp.h"

UiFinderImp::UiFinderImp(QWidget* p_Parent)
    : QDialog(p_Parent)
    , m_Ui(new Ui::UiFinderImp)
{
    m_Ui->setupUi(this);

    m_FileModel = new QFileSystemModel(this);
    m_FileModel->setRootPath(QDir::rootPath());

    m_Ui->columnView->setModel(m_FileModel);
    m_Ui->treeView->setModel(m_FileModel);

    connect(this, SIGNAL(ClickFileName(QString)), m_Ui->ImageLabel, SLOT(OnClickFileName(QString)));
    connect(m_Ui->ImageLabel, SIGNAL(DragFileName(QString)), this, SLOT(OnDragFileName(QString)));
    connect(m_Ui->treeView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnViewDoubleClicked(QModelIndex)));
    connect(m_Ui->columnView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnViewDoubleClicked(QModelIndex)));
}

UiFinderImp::~UiFinderImp()
{
}

void UiFinderImp::OnViewDoubleClicked(const QModelIndex& p_Index)
{
    const QString& fileName = m_FileModel->fileInfo(p_Index).absoluteFilePath();
    emit ClickFileName(fileName);
}

void UiFinderImp::OnDragFileName(const QString& p_FileName)
{
    const QFileInfo& fileInfo(p_FileName);
    // Set index and scroll for tree view
    m_Ui->treeView->scrollTo(m_FileModel->index(fileInfo.path()));
    m_Ui->treeView->setCurrentIndex(m_FileModel->index(fileInfo.path()));

    // Set index for column view
    //m_Ui->columnView->setRootIndex(m_ListModel->index(fileInfo.path()));
    m_Ui->columnView->setCurrentIndex(m_FileModel->index(fileInfo.filePath()));
}


