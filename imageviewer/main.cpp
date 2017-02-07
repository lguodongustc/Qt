#include "imageviewer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImageViewer w;

    w.menuBar()->setNativeMenuBar(false);           //tricky???
    w.show();

    return a.exec();
}
