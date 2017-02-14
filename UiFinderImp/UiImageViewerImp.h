#pragma once

#include <QLabel>

class UiImageViewerImp : public QLabel
{
    Q_OBJECT

public:
    explicit UiImageViewerImp(QWidget* p_Parent = NULL);
    ~UiImageViewerImp();

signals:
    void DragFileName(const QString& p_FileName);

protected:
    virtual void dragEnterEvent(QDragEnterEvent* p_Event);
    virtual void dropEvent(QDropEvent* p_Event);
    virtual void resizeEvent(QResizeEvent* event);

private slots:
    void OnClickFileName(const QString& p_FileName);

private:
    QImage m_CurImg;

private:
    void DrawCurPixmap();
    static bool s_IsPicFile(const QString& p_FileName);
};

