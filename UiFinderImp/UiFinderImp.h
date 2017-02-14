#pragma once

#include <QDialog>
#include <QPointer>
#include <QScopedPointer>

class QFileSystemModel;

namespace Ui
{
    class UiFinderImp;
}

class UiFinderImp : public QDialog
{
    Q_OBJECT

public:
    explicit UiFinderImp(QWidget* p_Parent = NULL);
    ~UiFinderImp();

signals:
    void ClickFileName(const QString& p_FileName);

private slots:
    //void OnTreeViewClicked(const QModelIndex& p_Index);
    void OnViewDoubleClicked(const QModelIndex& p_Index);
    void OnDragFileName(const QString& p_FileName);
    //void OnColumnViewClicked(const QModelIndex& p_Index);
    //void OnColumnViewDoubleClicked(const QModelIndex& p_Index);

private:
    QScopedPointer<Ui::UiFinderImp> m_Ui;
    QPointer<QFileSystemModel> m_FileModel;
};
