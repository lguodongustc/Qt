#ifndef UIFINDERIMP_H
#define UIFINDERIMP_H

#include <QDialog>

namespace Ui {
class UiFinderImp;
}

class UiFinderImp : public QDialog
{
    Q_OBJECT

public:
    explicit UiFinderImp(QWidget *parent = 0);
    ~UiFinderImp();

private:
    Ui::UiFinderImp *ui;
};

#endif // UIFINDERIMP_H
