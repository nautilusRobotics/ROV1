#ifndef MANAGER_H
#define MANAGER_H

#include <QPushButton>
#include "qmpwidget.h"
#include <QObject>
#include <QWidget>


class Manager: public QWidget
{
    Q_OBJECT

public:
    explicit Manager(QWidget *initw, QMPwidget *qWidget, QPushButton *btnNew);
    ~Manager();
    void init();
private:
    QWidget *initw;
    QMPwidget *qWidget;
    QPushButton *btn;

private slots:
 void handleButton();
};

#endif // MANAGER_H
