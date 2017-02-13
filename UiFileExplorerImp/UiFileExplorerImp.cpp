#include <QFileSystemModel>

#include "UiFileExplorerImp.h"

#include "ui_UiFileExplorerImp.h"

UiFileExplorerImp::UiFileExplorerImp(QWidget* p_Parent)
    : QDialog(p_Parent)
    , m_Ui(new Ui::UiFileExplorerImp)
    , m_CurPixmap(QPixmap())
{
    // Ui has one treeView, one Listview and one label named imageLable
    m_Ui->setupUi(this);

    // Set Ui image label properties.
    m_Ui->imageLabel->setMinimumSize(1, 1);
    m_Ui->imageLabel->setAcceptDrops(true);

#ifdef _WIN32
    const QString rootPath = "C:/";
#elif __APPLE__
    const QString rootPath = "/";
#elif __linux__
    const QString rootPath = "/";
#elif __unix__
    const QString rootPath = "/";
#else
#   error "Unknow compiler"
#endif

    // Create new tree model for tree view
    m_TreeModel = new QFileSystemModel(this);
    m_TreeModel->setRootPath(rootPath);
    m_TreeModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);

    // Connect tree model with ui tree view
    // Set some ui tree view properties
    m_Ui->treeView->setModel(m_TreeModel);
    m_Ui->treeView->setHeaderHidden(true);
    // Default
    m_Ui->treeView->hideColumn(1);
    m_Ui->treeView->hideColumn(2);
    m_Ui->treeView->hideColumn(3);

    // Create new list model for list view
    m_ListModel = new QFileSystemModel(this);
    m_ListModel->setRootPath(rootPath);
    m_ListModel->setFilter(QDir::NoDotAndDotDot | QDir::Dirs | QDir::Files);

    // Connect list model with ui list view
    //set some list view properties
    m_Ui->listView->setModel(m_ListModel);
    m_Ui->listView->setDragEnabled(true);

    // Connect ui imageLabel, treeview and listview with slot functions
    connect(m_Ui->imageLabel, SIGNAL(DragFileUrl(QString)), this, SLOT(OnDragFileUrl(QString)));
    connect(m_Ui->treeView, SIGNAL(clicked(QModelIndex)), this, SLOT(OnTreeViewClicked(QModelIndex)));
    connect(m_Ui->listView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(OnListViewDoubleClicked(QModelIndex)));
}

UiFileExplorerImp::~UiFileExplorerImp()
{

}

void UiFileExplorerImp::resizeEvent(QResizeEvent* p_Event)
{
    if (!m_CurPixmap.isNull())
    {
        DrawCurPixmap();
    }
}

void UiFileExplorerImp::DrawCurPixmap()
{
    // Draw image and make it fit to window when resize
    m_Ui->imageLabel->setPixmap(m_CurPixmap.scaled(m_Ui->imageLabel->width(), m_Ui->imageLabel->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void UiFileExplorerImp::OnTreeViewClicked(const QModelIndex& p_Index)
{
    // Set list view from the tree view
    const QString rootPath = m_TreeModel->fileInfo(p_Index).absoluteFilePath();
    m_Ui->listView->setRootIndex(m_ListModel->index(rootPath));
}

void UiFileExplorerImp::OnListViewDoubleClicked(const QModelIndex& p_Index)
{
    // Filter fileName
    const QString fileName = m_ListModel->fileInfo(p_Index).absoluteFilePath();

    if (m_Ui->imageLabel->s_IsPicFile(fileName))
    {
        // Set image and draw fitable image
        m_CurPixmap = QPixmap(m_ListModel->fileInfo(p_Index).absoluteFilePath());
        DrawCurPixmap();
    }
    else
    {
        m_CurPixmap = QPixmap();
        m_Ui->imageLabel->clear();
    }
}

void UiFileExplorerImp::OnDragFileUrl(const QString& p_FileUrl)
{
    const QPixmap curPixmap(p_FileUrl);
    const QFileInfo fileInfo(p_FileUrl);

    // Set current Pixmap and draw in the imagelabel
    m_CurPixmap = curPixmap;
    DrawCurPixmap();

    // Set index and scroll for tree view
    m_Ui->treeView->scrollTo(m_TreeModel->index(fileInfo.path()));
    m_Ui->treeView->setCurrentIndex(m_TreeModel->index(fileInfo.path()));

    // Set index for list view
    m_Ui->listView->setRootIndex(m_ListModel->index(fileInfo.path()));
    m_Ui->listView->setCurrentIndex(m_ListModel->index(fileInfo.filePath()));
}
