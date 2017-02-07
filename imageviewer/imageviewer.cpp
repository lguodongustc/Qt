#include "imageviewer.h"
#include "ui_imageviewer.h"

#include <QtWidgets>
#include <QFileDialog>
#include <QMessageBox>

ImageViewer::ImageViewer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageViewer)
{
    ui->setupUi(this);

    openAct = ui->openAct;
    printAct = ui->printAct;
    exitAct = ui->exitAct;
    zoomInAct = ui->zoomInAct;
    zoomOutAct = ui->zoomOutAct;
    normalSizeAct = ui->normalSizeAct;
    fitToWindowAct = ui->fitToWindowAct;
    aboutAct = ui->aboutAct;
    aboutQtAct = ui->aboutQtAct;

    //QImage image("/Users/liguodong/Downloads/test.jpeg");
    //ui->imageLabel->setPixmap(QPixmap::fromImage(image));

    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imageLabel);
    setCentralWidget(scrollArea);

    setWindowTitle(tr("Image Viewer"));
    resize(500, 400);

    connect(openAct,SIGNAL(triggered()),this,SLOT(on_openAct_triggered()));
    connect(printAct, SIGNAL(triggered()), this, SLOT(on_printAct_triggered()));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(on_exitAct_triggered()));
    connect(zoomInAct, SIGNAL(triggered()), this, SLOT(on_zoomInAct_triggered()));
    connect(zoomOutAct, SIGNAL(triggered()), this, SLOT(on_zoomOutAct_triggered()));
    connect(normalSizeAct, SIGNAL(triggered()), this, SLOT(on_normalSizeAct_triggered()));
    connect(fitToWindowAct, SIGNAL(triggered()), this, SLOT(on_fitToWindowAct_triggered()));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(on_aboutAct_triggered()));

}

ImageViewer::~ImageViewer()
{
    delete ui;
}

void ImageViewer::updateActions()
{
    zoomInAct->setEnabled(!fitToWindowAct->isCheckable());
    zoomOutAct->setEnabled(!fitToWindowAct->isCheckable());
    normalSizeAct->setEnabled(!fitToWindowAct->isCheckable());
}

void ImageViewer::scaleImage(double factor)
{
    Q_ASSERT(imageLabel->pixmap());
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap()->size());

    adjustScrollBar(scrollArea->horizontalScrollBar(), factor);
    adjustScrollBar(scrollArea->verticalScrollBar(), factor);
    zoomInAct->setEnabled(scaleFactor < 3.0);
    zoomOutAct->setEnabled(scaleFactor > 0.333);
}

void ImageViewer::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    scrollBar->setValue(int(factor * scrollBar->value()
                            + ((factor - 1) * scrollBar->pageStep()/2)));
}

void ImageViewer::on_openAct_triggered()
{
    qDebug() << "open()";
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());

    if(!fileName.isEmpty()){
        QImage image(fileName);
        if(image.isNull()){
            QMessageBox::information(this, tr("Imgae Viewer"), tr("Cannot load %1.").arg(fileName));
            return;
        }

        imageLabel->setPixmap(QPixmap::fromImage(image));
        scaleFactor = 1.0;

        printAct->setEnabled(true);
        fitToWindowAct->setEnabled(true);
        updateActions();

        if(!fitToWindowAct->isCheckable()){
            qDebug() << "test";
            imageLabel->adjustSize();
        }
    }
}

void ImageViewer::on_printAct_triggered()
{

}

void ImageViewer::on_exitAct_triggered()
{

}

void ImageViewer::on_zoomInAct_triggered()
{
    scaleImage(1.25);
}

void ImageViewer::on_zoomOutAct_triggered()
{
    scaleImage(0.8);
}

void ImageViewer::on_normalSizeAct_triggered()
{
    imageLabel->adjustSize();
    scaleFactor = 1.0;
}

void ImageViewer::on_fitToWindowAct_triggered()
{
    bool fitToWindow = fitToWindowAct->isCheckable();
    scrollArea->setWidgetResizable(fitToWindow);
    if(!fitToWindow)    on_normalSizeAct_triggered();
    updateActions();
}



void ImageViewer::on_aboutAct_triggered()
{
    QMessageBox::about(this, tr("About Image Viewer"),
            tr("<b>Image Viewer</b> example."));
}

void ImageViewer::on_aboutQtAct_triggered()
{

}
