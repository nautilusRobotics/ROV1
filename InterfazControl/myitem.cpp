#include "myitem.h"

extern QString createPath(QString path);

myItem::myItem(QWidget *parent, QString name, bool isConnected) :
    QWidget(parent)
{
    layout=new QGridLayout();
    missionName=name;
    online=isConnected;
    QString missionPath=createPath("Missions");
    QString missionsPath=QString("%1/%2/").arg(missionPath).arg(missionName);
    QString m_sSettingsFile = QString("%1settings.ini").arg(missionsPath);
    QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
    int pics = settings.value("pics", "").toInt();
    int videos = settings.value("videos", "").toInt();
    exploreAndExport=!(pics==0 && videos ==0);

    btnProject=new QPushButton(name);
    btnProject->setIcon(QIcon( createPath("icons/projectBox.png")));
    btnProject->setIconSize(QSize(25,25));
    btnProject->setFocusPolicy(Qt::NoFocus);
    btnProject->setStyleSheet(LW_STYLE);

    btnContinue=new QPushButton("Continue");
    btnContinue->setIcon(QIcon( createPath("icons/xboxA.png")));
    btnContinue->setIconSize(QSize(25,25));
    btnContinue->setFocusPolicy(Qt::NoFocus);
    btnContinue->setStyleSheet(LW_STYLE);
    btnContinue->setEnabled(isConnected);

    btnDelete=new QPushButton("Delete");
    btnDelete->setIcon(QIcon( createPath("icons/xboxB.png")));
    btnDelete->setIconSize(QSize(25,25));
    btnDelete->setFocusPolicy(Qt::NoFocus);
    btnDelete->setStyleSheet(LW_STYLE);


    btnExplore=new QPushButton("Explore");
    btnExplore->setIcon(QIcon( createPath("icons/xboxX.png")));
    btnExplore->setIconSize(QSize(25,25));
    btnExplore->setFocusPolicy(Qt::NoFocus);
    btnExplore->setEnabled(exploreAndExport);
    btnExplore->setStyleSheet(LW_STYLE);

    btnExport=new QPushButton("Export");
    btnExport->setIcon(QIcon( createPath("icons/xboxY.png")));
    btnExport->setIconSize(QSize(25,25));
    btnExport->setFocusPolicy(Qt::NoFocus);
    btnExport->setEnabled(exploreAndExport);
    btnExport->setStyleSheet(LW_STYLE);


    layout->addWidget(btnProject,0,0,1,4,Qt::AlignLeft);
    layout->addWidget(btnContinue,0,5,1,2);
    layout->addWidget(btnExplore,0,7,1,2);
    layout->addWidget(btnExport,0,9,1,2);
    layout->addWidget(btnDelete,0,11,1,2);


    this->setLayout(layout);

}


bool myItem::isExploreAndExport(){
    return exploreAndExport;
}


bool myItem::isOnline(){
    return online;
}

