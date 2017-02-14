#include <QFileSystemModel>
#include <QPainter>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QImageReader>

#include "UiImageViewerImp.h"

UiImageViewerImp::UiImageViewerImp(QWidget* p_Parent)
    : QLabel(p_Parent)
{
    this->setMinimumSize(1, 1);
    this->setAcceptDrops(true);
}

UiImageViewerImp::~UiImageViewerImp()
{

}

void UiImageViewerImp::dragEnterEvent(QDragEnterEvent* p_Event)
{
    const QMimeData* mimeData = p_Event->mimeData();
    if (!mimeData->urls().isEmpty() && s_IsPicFile(mimeData->urls()[0].fileName()))
    {
        p_Event->acceptProposedAction();
    }
    else
    {
        p_Event->ignore();
    }
}

void UiImageViewerImp::dropEvent(QDropEvent* p_Event)
{
    const QMimeData* mimeData = p_Event->mimeData();

    if (mimeData->urls().isEmpty() || mimeData->urls()[0].isEmpty())
    {
        return;
    }
    const QString& fileName = mimeData->urls()[0].toLocalFile();
    emit DragFileName(fileName);

    m_CurImg.load(fileName);
    DrawCurPixmap();
}

void UiImageViewerImp::resizeEvent(QResizeEvent* p_Event)
{
    DrawCurPixmap();
}

void UiImageViewerImp::DrawCurPixmap()
{
    if (m_CurImg.isNull())
    {
        return;
    }

    QPainter painter(this);
    const QPixmap& pixmap = QPixmap::fromImage(m_CurImg.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    painter.drawPixmap(0, 0, pixmap);
}

bool UiImageViewerImp::s_IsPicFile(const QString& p_FileName)
{
    const QList<QByteArray> imgForms = QImageReader::supportedImageFormats();

    for (int i = 0; i < imgForms.size(); ++i)
    {
        if (p_FileName.endsWith("." + imgForms[i], Qt::CaseInsensitive))
        {
            return true;
        }
    }

    return false;
}

void UiImageViewerImp::OnClickFileName(const QString& p_FileName)
{
    if (s_IsPicFile(p_FileName))
    {
        m_CurImg.load(p_FileName);
        DrawCurPixmap();
    }
    else
    {
        m_CurImg = QImage();
        clear();
    }
}
