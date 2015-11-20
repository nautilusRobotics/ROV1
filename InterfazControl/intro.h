#ifndef INTRO_H
#define INTRO_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QPixmap>
#include <QLineEdit>
#include <QToolTip>
#include <missionwidget.h>
#include <QMessageBox>
#include <QStyle>
#include <QListWidget>
#include <myitem.h>
#include <QDirIterator>
#include <QFileInfo>
#include <QShowEvent>
#include <QGraphicsScene>
#include "missionexplorer.h"
#include "exportmanager.h"


class intro : public QWidget
{
    Q_OBJECT
public:
    explicit intro(QWidget *parent=0);

signals:

public slots:
    void handleNewBtn();
    void createProjectList();
    void runMission(QString missionName);
    void exploreMission(QString missionName);
    void deleteMission(QString missionName,QListWidgetItem *item);
    void reOpen();
    void handleButtonOff();

    private:
    QGridLayout *layout;
    QLabel *welcomeTxt,*logo,*namelbl,*openlbl;
    QPushButton *btnNew, *button_off;
    QLineEdit *newMission;
    QListWidget *projectList;
    MissionWidget *mission;
    ExportManager *exm;
    QString missionsPath;
    void showMessage(QString message);
    bool isOpen;

protected:
      void showEvent(QShowEvent *ev);


};

#endif // INTRO_H
