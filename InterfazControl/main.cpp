#include <QApplication>
#include <missionwidget.h>
#include <intro.h>

int main(int argc, char *argv[])
{
    //------------------------------Init------------------------------------------
    QApplication app(argc, argv);


    intro welcomeScreen;
    welcomeScreen.show();


   return app.exec();
}




