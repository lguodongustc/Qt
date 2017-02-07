#include "QtFileExplorer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtFileExplorer w;
    w.show();

    return a.exec();
}
