#include "myitem.h"

myItem::myItem(QWidget *parent, QString name) :
    QWidget(parent)
{
    layout=new QGridLayout();
    nameLabel=new QLabel(name);
    missionName=name;

    btnContinue=new QPushButton("Continue");
    btnContinue->setIcon(QIcon( "./icons/continue.png"));
    btnContinue->setIconSize(QSize(32,32));
    btnContinue->setFocusPolicy(Qt::NoFocus);
    connect(btnContinue,SIGNAL(released()),this,SLOT(handleContinue()));

    btnDelete=new QPushButton("Delete");
    btnDelete->setIcon(QIcon( "./icons/trash.png"));
    btnDelete->setIconSize(QSize(32,32));
    btnDelete->setFocusPolicy(Qt::NoFocus);
    connect(btnDelete,SIGNAL(released()),this,SLOT(handleDelete()));

    btnExplore=new QPushButton("Explore");
    btnExplore->setIcon(QIcon( "./icons/explore.png"));
    btnExplore->setIconSize(QSize(32,32));
    btnExplore->setFocusPolicy(Qt::NoFocus);
    connect(btnExplore,SIGNAL(released()),this,SLOT(handleExplore()));

    icon=new QLabel("<img src=\"./icons/missionLogo32x32\">");

    layout->addWidget(icon,0,0,1,1);
    layout->addWidget(nameLabel,0,1,1,4);
    layout->addWidget(btnContinue,0,6,1,2);
    layout->addWidget(btnDelete,0,8,1,2);
    layout->addWidget(btnExplore,0,10,1,2);

    this->setLayout(layout);

}

void myItem::setWItem(QListWidgetItem *item){
    this->itemW=item;
}

void myItem::handleContinue(){
    continueSignal(missionName);
}
void myItem::handleDelete(){
     deleteSignal(missionName,itemW);
}
void myItem::handleExplore(){
    exploreSignal(missionName);
}
