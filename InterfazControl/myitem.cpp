#include "myitem.h"

extern QString createPath(QString path);

myItem::myItem(QWidget *parent, QString name) :
    QWidget(parent)
{
    layout=new QGridLayout();
    nameLabel=new QLabel(name);
    missionName=name;

    QString missionsPath=createPath("Missions");
    QString missionPath=QString("%1/%2/").arg(missionsPath).arg(missionName);
    QString m_sSettingsFile = QString("%1/%2/settings.ini").arg(missionsPath).arg(missionName);
    QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
    int pics = settings.value("pics", "").toInt();
    int videos = settings.value("videos", "").toInt();
    bool exploreAndExport=!(pics==0 && videos ==0);


    btnContinue=new QPushButton("Continue");
    btnContinue->setIcon(QIcon( createPath("icons/continue.png")));
    btnContinue->setIconSize(QSize(25,25));
    btnContinue->setFocusPolicy(Qt::NoFocus);
    connect(btnContinue,SIGNAL(released()),this,SLOT(handleContinue()));

    btnDelete=new QPushButton("Delete");
    btnDelete->setIcon(QIcon( createPath("icons/trash.png")));
    btnDelete->setIconSize(QSize(25,25));
    btnDelete->setFocusPolicy(Qt::NoFocus);
    connect(btnDelete,SIGNAL(released()),this,SLOT(handleDelete()));

    btnExplore=new QPushButton("Explore");
    btnExplore->setIcon(QIcon( createPath("icons/explore.png")));
    btnExplore->setIconSize(QSize(25,25));
    btnExplore->setFocusPolicy(Qt::NoFocus);
    btnExplore->setEnabled(exploreAndExport);
    connect(btnExplore,SIGNAL(released()),this,SLOT(handleExplore()));

    btnExport=new QPushButton("Export");
    btnExport->setIcon(QIcon( createPath("icons/export.png")));
    btnExport->setIconSize(QSize(25,25));
    btnExport->setFocusPolicy(Qt::NoFocus);
    btnExport->setEnabled(exploreAndExport);
    connect(btnExport,SIGNAL(released()),this,SIGNAL(exportSignal()));


    icon=new QLabel(QString("<img src=\"%1\">").arg(createPath("icons/missionLogo32x32")));

    layout->addWidget(icon,0,0,1,1);
    layout->addWidget(nameLabel,0,1,1,4);
    layout->addWidget(btnContinue,0,6,1,2);
    layout->addWidget(btnExplore,0,8,1,2);
    layout->addWidget(btnExport,0,10,1,2);
    layout->addWidget(btnDelete,0,12,1,2);


    this->setLayout(layout);

}

void myItem::setWItem(QListWidgetItem *item){
    this->itemW=item;
}

void myItem::handleContinue(){
    emit continueSignal(missionName);
}
void myItem::handleDelete(){
    emit deleteSignal(missionName,itemW);
}
void myItem::handleExplore(){
    emit exploreSignal(missionName);
}


