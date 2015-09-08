#include "manager.h"

Manager::Manager(QWidget *initw, QMPwidget *qWidget, QPushButton *btnNew) {

   this->qWidget=qWidget;
   this->initw=initw;
   btn=btnNew;

}

void Manager::init(){
    initw->show();
    connect(btn,SIGNAL(released()),this,SLOT (handleButton()));
}

void Manager::handleButton(){
   qDebug("Click");
   initw->hide();
   qWidget->show();
}


Manager::~Manager ()
{

}
