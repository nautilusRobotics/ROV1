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

class intro : public QWidget
{
    Q_OBJECT
public:
    explicit intro(QWidget *parent=0);

signals:

public slots:
    void handleNewBtn();
    void handleOpenBtn();
    private:
    QGridLayout *layout;
    QLabel *welcomeTxt,*logo,*namelbl,*openlbl;
    QPushButton *btnNew,*btnOpen;
    QLineEdit *newMission;
    MissionWidget *mission;
    void showMessage(QString message);

};

#endif // INTRO_H
