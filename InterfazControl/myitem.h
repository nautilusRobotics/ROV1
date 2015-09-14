#ifndef MYITEM_H
#define MYITEM_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QListWidgetItem>

class myItem : public QWidget
{
    Q_OBJECT
public:
    explicit myItem(QWidget *parent = 0, QString name="");

signals:
    void continueSignal(QString);
    void deleteSignal(QString,QListWidgetItem*);
    void exploreSignal(QString);
    void exportSignal();

public slots:
    void handleContinue();
    void handleDelete();
    void handleExplore();

public:
    void setWItem(QListWidgetItem *item);

private:
    QGridLayout *layout;
    QPushButton *btnContinue,*btnDelete,*btnExplore,*btnExport;
    QLabel *nameLabel,*icon;
    QString missionName;
    QListWidgetItem *itemW;

};

#endif // MYITEM_H
