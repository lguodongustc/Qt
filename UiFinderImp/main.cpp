#include "UiFinderImp.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UiFinderImp w;
    w.show();

    return a.exec();
}
