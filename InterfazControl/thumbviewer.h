#ifndef THUMBVIEWER_H
#define THUMBVIEWER_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

class ThumbViewer : public QWidget
{
    Q_OBJECT
public:
    explicit ThumbViewer(QWidget *parent = 0, QString fp="");

signals:

public slots:

private:
    QPushButton *btn_action;
    QImage *img_thumb;
    QLabel *icon_video;
    QString filePath;
    bool isVideo;
    QGridLayout *layout;
    QImage *thumb;

};

#endif // THUMBVIEWER_H
