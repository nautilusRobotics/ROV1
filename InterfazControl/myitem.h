#ifndef MYITEM_H
#define MYITEM_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QListWidgetItem>
#include <QSettings>
#include <QDebug>
#define LW_STYLE "background-color: rgba(255, 255, 255, 0);"

class myItem : public QWidget
{
    Q_OBJECT
public:
    explicit myItem(QWidget *parent = 0, QString name="", bool isConnected=false);


public:    
    QString getMissionName();
    bool isExploreAndExport();
    bool isOnline();

private:
    QGridLayout *layout;
    QPushButton *btnContinue,*btnDelete,*btnExplore,*btnExport, *btnProject;
    QLabel *nameLabel,*icon;
    QString missionName;
    QListWidgetItem *itemW;
    bool exploreAndExport;
    bool online;

};

#endif // MYITEM_H
