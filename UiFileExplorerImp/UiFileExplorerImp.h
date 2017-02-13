#pragma once

#include <QDialog>
#include <QPointer>

class QFileInfo;
class QFileSystemModel;

// Class generated from UiFileExplorerImp.ui
namespace Ui
{
    class UiFileExplorerImp;
}

// Class for the main window of UiFileExplorerImp
class UiFileExplorerImp : public QDialog
{
    Q_OBJECT

public:
    explicit UiFileExplorerImp(QWidget* p_Parent = NULL);
    ~UiFileExplorerImp();

protected:
    virtual void resizeEvent(QResizeEvent* event);

private slots:
    void OnTreeViewClicked(const QModelIndex& p_Index);
    void OnListViewDoubleClicked(const QModelIndex& p_Index);
    void OnDragFileUrl(const QString& p_FileUrl);

private:
    QScopedPointer<Ui::UiFileExplorerImp> m_Ui;

    // Make two file system models to filter them seperately
    QPointer<QFileSystemModel> m_TreeModel;
    QPointer<QFileSystemModel> m_ListModel;

    // Store current pixmap
    QPixmap m_CurPixmap;

    void DrawCurPixmap();
};
