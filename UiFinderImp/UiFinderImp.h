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

private:
    QScopedPointer<Ui::UiFinderImp> m_Ui;
    QPointer<QFileSystemModel> m_FileModel;
};
