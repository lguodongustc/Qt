#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDirModel>
#include <QFileDialog>
#include <iostream>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_delete_2_clicked();

    void on_makedir_clicked();

    void on_treeView_clicked(const QModelIndex &index);

private:
    Ui::Dialog *ui;

    QDirModel *model;
};

#endif // DIALOG_H
