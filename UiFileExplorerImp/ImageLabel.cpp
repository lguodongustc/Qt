#include <QMimeData>
#include <QImageReader>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QFileInfo>

#include "ImageLabel.h"

ImageLabel::ImageLabel(QWidget* p_Parent): QLabel(p_Parent)
{
}

bool ImageLabel::s_IsPicFile(const QString& p_FileName)
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

void ImageLabel::dragEnterEvent(QDragEnterEvent* p_Event)
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

void ImageLabel::dropEvent(QDropEvent* p_Event)
{
    const QMimeData* mimeData = p_Event->mimeData();

    if (mimeData->urls().isEmpty() || mimeData->urls()[0].isEmpty())
    {
        p_Event->ignore();
        return;
    }

    const QString fileUrl = mimeData->urls()[0].toLocalFile();
    emit DragFileUrl(fileUrl);
    p_Event->acceptProposedAction();
}
