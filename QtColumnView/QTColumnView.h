#ifndef QTCOLUMNVIEW_H
#define QTCOLUMNVIEW_H

#include <QDialog>

namespace Ui {
class QTColumnView;
}

class QTColumnView : public QDialog
{
    Q_OBJECT

public:
    explicit QTColumnView(QWidget *parent = 0);
    ~QTColumnView();

private:
    Ui::QTColumnView *ui;
};

#endif // QTCOLUMNVIEW_H
