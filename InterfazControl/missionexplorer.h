#ifndef MISSIONEXPLORER_H
#define MISSIONEXPLORER_H

#include <QWidget>
#include <QGridLayout>
#include <QStyle>
#include <QDesktopWidget>
#include <QObject>
#include <QListWidget>
#include <QDirIterator>
#include "player.h"
#include "qmpwidget.h"
#include "playercontrols.h"
#include "thumbviewer.h"

class MissionExplorer : public QWidget
{
    Q_OBJECT
public:
    explicit MissionExplorer(QWidget *parent = 0, QString missionPath="Untitled");

signals:

public slots:
private:
    QGridLayout *layout;
    QMPwidget widget;
    Player *player;
    PlayerControls *controls;
    QListWidget *listFiles;
    QString missionPath;
    ThumbViewer *thumbElement;
    void createPreviewList();

};

#endif // MISSIONEXPLORER_H
