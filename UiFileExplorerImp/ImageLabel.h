#pragma once

#include <QLabel>

class QFileInfo;
class QDragEnterEvent;
class QDropEvent;

// ImageLabel with customer drag and drop event
class ImageLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ImageLabel(QWidget* p_Parent = NULL);
    static bool s_IsPicFile(const QString& p_FileName);

signals:
    void DragFileUrl(const QString& p_FileUrl);

protected:
    virtual void dragEnterEvent(QDragEnterEvent* event);
    virtual void dropEvent(QDropEvent* event);
};
