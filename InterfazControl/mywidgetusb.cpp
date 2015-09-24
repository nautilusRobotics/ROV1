#include "mywidgetusb.h"

extern QString createPath(QString path);

myWidgetUsb::myWidgetUsb(QWidget *parent,int index,bool isSave,QString usbName) :
    QWidget(parent)
{


    this->index=index;
    btn=new QPushButton();
    btn->setIcon(QIcon(createPath("icons/usb.png")));
    btn->setIconSize(QSize(32,32));
    btn->setFocusPolicy(Qt::NoFocus);

    QString btnName;
    if(isSave){
        btnName=QString("%1").arg(usbName);
        btn->setStyleSheet("QPushButton{font-size:20px;font-weight:bold;color:white;background:#65A15D}");
        connect(btn,SIGNAL(released()),this,SLOT(handleItem()));
    }
    else{
        btnName=QString("%1 has not enough space").arg(usbName);
        btn->setStyleSheet("QPushButton{font-size:15px;font-weight:bold;color:black;background:#EE4545}");
        //btn->setEnabled(false);

    }
    btn->setText(btnName);


    QGridLayout *layout=new QGridLayout();
    layout->addWidget(btn);

    setLayout(layout);
}


void myWidgetUsb::handleItem(){
    emit usbSelected(index);
}
