#ifndef MYWIDGETUSB_H
#define MYWIDGETUSB_H

#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QGridLayout>

class myWidgetUsb : public QWidget
{
    Q_OBJECT
public:
    explicit myWidgetUsb(QWidget *parent = 0, int index=0, bool isSave=true, QString usbName="");
private:
    QPushButton *btn;
    QString missionName;
    int index;
signals:
    void usbSelected(int);
public slots:
   void handleItem();

};

#endif // MYWIDGETUSB_H
