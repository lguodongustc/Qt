#ifndef QTFILEEXPLORER_H
#define QTFILEEXPLORER_H

#include <QDialog>
#include <QFileSystemModel>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDropEvent>
#include <QUrl>
#include <QDirModel>
#include <QFileDialog>

#include <iostream>
class QLabel;

namespace Ui {
class QtFileExplorer;
}

class QtFileExplorer : public QDialog
{
    Q_OBJECT

public:
    explicit QtFileExplorer(QWidget *parent = 0);
    ~QtFileExplorer();

private slots:
    void on_treeView_clicked(const QModelIndex &index);
    void on_listView_clicked(const QModelIndex &index);
    void on_listView_doubleClicked(const QModelIndex &index);

protected:
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
    void resizeEvent(QResizeEvent *event);

private:
    Ui::QtFileExplorer *ui;
    QFileSystemModel *dirModel;
    QFileSystemModel *fileModel;
    QLabel *imageLabel;
    QPixmap *image;
};

#endif // QTFILEEXPLORER_H
