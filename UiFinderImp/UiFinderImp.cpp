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
}

UiFinderImp::~UiFinderImp()
{
}
