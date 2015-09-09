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
#include "missionexplorer.h"

class intro : public QWidget
{
    Q_OBJECT
public:
    explicit intro(QWidget *parent=0);

signals:

public slots:
    void handleNewBtn();    
    void createProjectList();
    void continueMission(QString missionName);
    void exploreMission(QString missionName);
    void deleteMission(QString missionName,QListWidgetItem *item);

    private:
    QGridLayout *layout;
    QLabel *welcomeTxt,*logo,*namelbl,*openlbl;
    QPushButton *btnNew;
    QLineEdit *newMission;
    QListWidget *projectList;
    MissionWidget *mission;
    void showMessage(QString message);

};

#endif // INTRO_H
