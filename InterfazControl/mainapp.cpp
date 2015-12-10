#include "mainapp.h"
#include <QPixmap>
#include <QBitmap>

extern QString createPath(QString path);
#define DEBUG_INTRO


MainApp::MainApp(QWidget *parent) :
    QWidget(parent)
{

    QIcon icon(createPath("icons/nautilus128x128.svg"));
    setWindowIcon(icon);
    setWindowTitle("Nautilus Commander");
    setWindowState( Qt::WindowFullScreen );

    ui.setupUi(this);
    stackedWidget=ui.stackedWidget;
    stackedWidget->setCurrentIndex(0);
    initWelcomeScreen();
}

void MainApp::initWelcomeScreen(){

    btnNew=ui.btnNew;
    btnNew->setStyleSheet(QPUSH_STYLE_START);

    btnOpen=ui.btnOpen;
    btnOpen->setStyleSheet(QPUSH_STYLE_OPEN);

    btnOff = ui.btnOff;
    btnOff->setStyleSheet(QPUSH_STYLE_OFF);

    lblHelp = ui.lblHelp;
    lblHelp->setStyleSheet(QLABEL_STYLE_HELP);

    projectList=ui.listWidget;
    exm=new ExportManager(this);
    projectListStrings=new QStringList();
    projectListBools=new QBitArray();

    lblListWidget=ui.lblListWidget;

    openMissionBox=ui.openMissionBox;
    openMissionBox->setVisible(false);

    lblTitle=ui.label_title;

    lblShadow=ui.lblShadow;
    lblShadow->setVisible(false);

    /********************************  Joystick *****************************************************/
    joystick=new JoystickWidget();
    connect(joystick,SIGNAL(updateStatus(bool)),this,SLOT(updateControlStatus(bool)));
    connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
    connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));
    joystick->init();
    /***********************************************************************************************/
    missionsPath=createPath("Missions");
    if(!QDir(missionsPath).exists()){
        QDir().mkdir(missionsPath);
    }

    focused=0;
    keysList=new QStringList();
    keyBoardLayout=this->generateKeyboard();
    isKeyboard=false;
    isOpen=false;
    isOpenProjectMenu=false;
    openProjectRow=0;



}

void MainApp::handleNewBtn(QString missionName){

    if(missionName.compare("")){
        QRegExp rx ("[^a-zA-Z0-9]");
        QString fixedName =missionName.replace(rx,"");

        if(fixedName.compare("")){
            disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
            disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));
            runMission(fixedName);
        }
        else
            showToast("Invalid mission name",1000);

    }
    else
        showToast("Invalid mission name",1000);


}

void MainApp::showMessage(QString message, bool okCancelbtns){

    lblShadow->setVisible(true);
    toast=new QMessageBox();
    toast->setText(message);
    toast->setIcon(QMessageBox::Warning);
    toast->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    toast->setStyleSheet(QMESAGE_STYLE);

    QSpacerItem* horizontalSpacer = new QSpacerItem(1000, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout = (QGridLayout*)toast->layout();

    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());


    if(okCancelbtns){

        QLabel *tempLbl=new QLabel(QString("<img src=\"%1\">").arg(createPath("icons/btnFoot.svg")));
        layout->addWidget(tempLbl,layout->rowCount(), 0, 1, layout->columnCount());

        disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
        disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));

        connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMessage(QString,QGameControllerButtonEvent*)));
    }
    toast->show();
    //toast->exec();
}
void MainApp::showToast(QString message, int time){
    QTimer::singleShot(time,Qt::PreciseTimer ,this, SLOT(closeMessage()));
    showMessage(message,false);
}

void MainApp::closeMessage(){
    qDebug()<<"closeMessage";
    lblShadow->setVisible(false);
    toast->close();
}


void MainApp::createProjectList(){

    QDirIterator it(missionsPath,QDir::NoDotAndDotDot | QDir::AllDirs);
    projectListStrings->clear();
    projectList->clear();
    projectListBools->clear();
    int idx=0;
    while (it.hasNext()) {
        QFileInfo Info(it.next());
        QString missionName = QString(Info.fileName());

#ifdef DEBUG_INTRO
        qDebug() <<missionName;
#endif


        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(item->sizeHint().width(), 60));

        myItem *myListItem = new myItem(0,missionName);
        projectListStrings->append(missionName);
        projectListBools->resize(idx+1);
        projectListBools->setBit(idx,myListItem->isExploreAndExport());
        idx++;
        exm->setMissionName(missionName);     

        projectList->addItem(item);
        projectList->setItemWidget(item, myListItem);
    }
}
void MainApp::runMission(QString missionName){

#ifdef DEBUG_INTRO
      qDebug() <<"continue "+missionName;
#endif

   disconnect(joystick,SIGNAL(updateStatus(bool)),this,SLOT(updateControlStatus(bool)));

   missionWidget=new MissionWidget(this,missionName,joystick,&ui);
   connect(missionWidget,SIGNAL(returnToHome()),this,SLOT(showHome()));
   stackedWidget->setCurrentIndex(1);
}
void MainApp::exploreMission(QString missionName){
#ifdef DEBUG_INTRO
      qDebug() <<"explore "+missionName;
#endif

  disconnect(joystick,SIGNAL(updateStatus(bool)),this,SLOT(updateControlStatus(bool)));
  disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
  disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));

  missionExplorer=new MissionExplorer(this,missionName,joystick,&ui);
  connect(missionExplorer,SIGNAL(returnToHome()),this,SLOT(showHome()));
  stackedWidget->setCurrentIndex(2);

}

void MainApp::deleteMission(QString missionName,QListWidgetItem *item){

#ifdef DEBUG_INTRO
       qDebug() <<"delete "+missionName;
#endif

          QString dirName=QString("%1/%2").arg(missionsPath).arg(missionName);

          QDir dir(dirName);

          if(dir.removeRecursively()){
            #ifdef DEBUG_INTRO
                   qDebug()<<"delete OK";
            #endif
              projectList->takeItem(projectList->row(item));

          }
          else{
            #ifdef DEBUG_INTRO
                      qDebug()<<"no delete";
            #endif
          }


}

void MainApp::showHome(){
   connect(joystick,SIGNAL(updateStatus(bool)),this,SLOT(updateControlStatus(bool)));
   connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
   connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));
   stackedWidget->setCurrentIndex(0);
}
void MainApp::handleButtonOff(){
    QString msg=QString("Are you sure? \n The robot is save? \n the system is going to turning off");
    QMessageBox::StandardButton reply;

    reply = QMessageBox::warning(this, "Alert", msg, QMessageBox::Ok|QMessageBox::Cancel);
    if (reply == QMessageBox::Ok)this->close();

}
void MainApp::joystickButtonEventMenu(QString button,QGameControllerButtonEvent* event){
   if(button==button_A && !event->pressed()){
       switch(focused){
          case 0:
            qDebug("option Start");
            lauchKeyBoard();
           break;
          case 1:
               qDebug("option Open");               
               disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
               disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));
               connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
               connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));
               openProjectRow=0;
               createProjectList();
               projectList->setCurrentRow(openProjectRow);
               lblTitle->setText("Open Previous Mission");
               openMissionBox->setVisible(true);
            break;
          case 2:
            qDebug("option Off");
            this->close();
            break;
          case maxOptions:
           qDebug("option Help");
           break;
       }
    }
}
void MainApp::joystickAxisEventMenu(QString axis, int value){
        if((!axis.compare(axis_cross_vertical) || !axis.compare(axis_left_vertical) || !axis.compare(axis_right_vertical)) && value==1000){
          this->focusNextChild();        
          focused++;
          focused=(focused>maxOptions)?0:focused;
        }
        if((!axis.compare(axis_cross_vertical) || !axis.compare(axis_left_vertical) || !axis.compare(axis_right_vertical)) && value==-1000){
           this->focusPreviousChild();
           focused--;
           focused=(focused<0)?maxOptions:focused;
        }    
}
void MainApp::joystickAxisEventOpen(QString axis, int value){

    if((!axis.compare(axis_cross_vertical) || !axis.compare(axis_left_vertical) || !axis.compare(axis_right_vertical)) && value==1000)
       openProjectRow=(openProjectRow+1>projectList->count()-1)?0:openProjectRow+1;
    if((!axis.compare(axis_cross_vertical) || !axis.compare(axis_left_vertical) || !axis.compare(axis_right_vertical)) && value==-1000)
        openProjectRow=(openProjectRow-1<0)?0:openProjectRow-1;

    projectList->setCurrentRow(openProjectRow);
}
void MainApp::joystickButtonEventOpen(QString button,QGameControllerButtonEvent* event){
    if(button==button_A && !event->pressed()){
        int item= projectList->currentRow();
        runMission(projectListStrings->at(item));
        lblTitle->setText("Welcome to Nautilus Commander");
        openMissionBox->setVisible(false);
        disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
        disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));

    }
    else if(button==button_X && !event->pressed()){
        int item= projectList->currentRow();

        if(projectListBools->at(item))
            exploreMission(projectListStrings->at(item));
    }
    else if(button==button_B && !event->pressed()){
        int item= projectList->currentRow();
        QString msg=QString("Are you sure you want to delete the Mission: \"%1\"\n You can't undo this action").arg(projectListStrings->at(item));
        showMessage(msg,true);
    }
    else if(button==button_Y && !event->pressed()){
        int item= projectList->currentRow();

       // if(projectListBools->at(item))
           // exploreMission(projectListStrings->at(item));
    }
    else if(button==button_back && !event->pressed()){
       disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
       disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));
       connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
       connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));
       lblTitle->setText("Welcome to Nautilus Commander");
       openMissionBox->setVisible(false);
    }
}

void MainApp::updateControlStatus(bool isConnected){

}
void MainApp::handleCloseKeyboardEvent(bool cancelled,QString result){
    disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),keyboard,SLOT(handleJoystickAxisEvent(QString,int)));
    disconnect(joystick,SIGNAL(joystickButtonEvent(QString ,QGameControllerButtonEvent*)),keyboard,SLOT(handleJoystickButtonEvent(QString ,QGameControllerButtonEvent*)));
    connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
    connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));

    if(!cancelled)
      handleNewBtn(result);
}
void MainApp::lauchKeyBoard(){
    keyboard = new widgetKeyBoard(true);
    keyboard->setZoomFacility(false);
    keyboard->enableSwitchingEcho(false); // enable possibility to change echo through keyboard
    keyboard->initLayout(keysList,keyBoardLayout,resultTextBox);
    keyboard->show(NULL);
    keyboard->move(this->x()+200, this->y()/2 + this->keyboard->height()+200); // to move keyboard

    connect(keyboard,SIGNAL(closeKeyboardEvent(bool,QString)),this,SLOT(handleCloseKeyboardEvent(bool,QString)));

    disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
    disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));
    connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),keyboard,SLOT(handleJoystickAxisEvent(QString,int)));
    connect(joystick,SIGNAL(joystickButtonEvent(QString ,QGameControllerButtonEvent*)),keyboard,SLOT(handleJoystickButtonEvent(QString ,QGameControllerButtonEvent*)));
}

QVBoxLayout * MainApp::generateKeyboard(void){
    QPushButton 	*tmp = NULL;
    QVBoxLayout     *tmpVLayout = new QVBoxLayout;
    QHBoxLayout     *tmpLayout = new QHBoxLayout;
    QString         tmpStyle = QString::null;



    tmpLayout->addWidget(createNewKey(""));
    for (short i = 49; i <= 57; i++) {
        tmpLayout->addWidget(createNewKey(QChar(i)));
    }
    tmpLayout->addWidget(createNewKey(tr("0")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));

    tmpStyle = QString(KEY_BACKSPACE_EMBEDDED);



    tmp = createNewKey(tmpStyle);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    tmpStyle = QString(KEY_CANC);


     tmpStyle = tmpStyle.toLower();

    tmp = createNewKey(tmpStyle);
    tmp->setMaximumWidth(tmp->maximumWidth());
    tmp->setMinimumWidth(tmp->minimumWidth());
    tmpLayout->addWidget(tmp);

    tmpVLayout->insertLayout(0, tmpLayout);
    //
    // Stampa linea della "Q":
    tmpLayout = new QHBoxLayout;
    QVBoxLayout *layoutReturn = new QVBoxLayout;
    tmp = createNewKey(KEY_TAB);
    tmp->setMaximumWidth(tmp->maximumWidth() *1.5);
    tmp->setMinimumWidth(tmp->minimumWidth() *1.5);
    tmpLayout->addWidget(tmp);
    tmpLayout->addWidget(createNewKey(tr("Q")));
    tmpLayout->addWidget(createNewKey(tr("W")));
    tmpLayout->addWidget(createNewKey(tr("E")));
    tmpLayout->addWidget(createNewKey(tr("R")));
    tmpLayout->addWidget(createNewKey(tr("T")));
    tmpLayout->addWidget(createNewKey(tr("Y")));
    tmpLayout->addWidget(createNewKey(tr("U")));
    tmpLayout->addWidget(createNewKey(tr("I")));
    tmpLayout->addWidget(createNewKey(tr("O")));
    tmpLayout->addWidget(createNewKey(tr("P")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));

    layoutReturn->insertLayout(0, tmpLayout, 1); // inserisce la riga della "Q"
    //
    // Stampa linea della "A":
    tmpLayout = new QHBoxLayout;
    tmp = createNewKey(KEY_CAPS);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2 + 5);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2 + 5);

     tmpStyle = QString(EMBEDDED_KEYBOARD);

    tmp->setStyleSheet(QString(DEFAULT_STYLE_BUTTON) + QString(CHANGED_BACKGROUND_BUTTON) + tmpStyle); // segnalato come attivo
    tmpLayout->addWidget(tmp);
    tmpLayout->addWidget(createNewKey(tr("A")));
    tmpLayout->addWidget(createNewKey(tr("S")));
    tmpLayout->addWidget(createNewKey(tr("D")));
    tmpLayout->addWidget(createNewKey(tr("F")));
    tmpLayout->addWidget(createNewKey(tr("G")));
    tmpLayout->addWidget(createNewKey(tr("H")));
    tmpLayout->addWidget(createNewKey(tr("J")));
    tmpLayout->addWidget(createNewKey(tr("K")));
    tmpLayout->addWidget(createNewKey(tr("L")));
    tmpLayout->addWidget(createNewKey(tr(QString::fromLocal8Bit("").toUtf8())));
    tmpLayout->addWidget(createNewKey(tr(QString::fromLocal8Bit("").toUtf8())));
    tmpLayout->addWidget(createNewKey(tr(QString::fromLocal8Bit("").toUtf8())));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->insertStretch(-1, 1);

    layoutReturn->insertLayout(1, tmpLayout, 1); // inserisce la riga della "A"
    //
    // inserisce il vertical layout all'interno di un horizontal:
    tmpLayout = new QHBoxLayout;
    tmpLayout->insertLayout(0, layoutReturn, 1);
    //
    // inserisce anche il tasto invio:
    tmp = createNewKey(KEY_RETURN);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmp->setMinimumHeight(tmp->minimumHeight() * 2);
    tmp->setMaximumHeight(tmp->maximumHeight() * 2);
    tmpLayout->addWidget(tmp);
    //
    // inserisce l'horizontal all'interno del layout verticale principale:
    tmpVLayout->insertLayout(1, tmpLayout);
    //
    // Stampa linea della "Z":
    tmpLayout = new QHBoxLayout;
    tmp = createNewKey(KEY_CUT_LEFT);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    tmpLayout->addWidget(createNewKey(tr("_")));
    tmpLayout->addWidget(createNewKey(tr("Z")));
    tmpLayout->addWidget(createNewKey(tr("X")));
    tmpLayout->addWidget(createNewKey(tr("C")));
    tmpLayout->addWidget(createNewKey(tr("V")));
    tmpLayout->addWidget(createNewKey(tr("B")));
    tmpLayout->addWidget(createNewKey(tr("N")));
    tmpLayout->addWidget(createNewKey(tr("M")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmpLayout->addWidget(createNewKey(tr("")));
    tmp = createNewKey(KEY_CLEAR_ALL);
    tmp->setMaximumWidth(tmp->maximumWidth() * 3 + 5);
    tmp->setMinimumWidth(tmp->minimumWidth() * 3 + 5);
    tmpLayout->addWidget(tmp);
    tmpVLayout->insertLayout(2, tmpLayout);
    //
    // Stampa linea dello SPACE:
    tmpLayout = new QHBoxLayout;
    tmp = createNewKey(KEY_COPY);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    tmp = createNewKey(KEY_ALT);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    tmp = createNewKey(KEY_SPACE);
    tmp->setMaximumWidth(tmp->maximumWidth() * 10);
    tmp->setMinimumWidth(tmp->minimumWidth() * 10);
    tmpLayout->addWidget(tmp);
    // password echo button:
    tmpStyle = QString(KEY_HIDECHAR_EMBEDDED);

    tmp = createNewKey(tmpStyle);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    //
    tmp = createNewKey(KEY_PASTE);
    tmp->setMaximumWidth(tmp->maximumWidth() * 2);
    tmp->setMinimumWidth(tmp->minimumWidth() * 2);
    tmpLayout->addWidget(tmp);
    tmpVLayout->insertLayout(3, tmpLayout);

    tmpLayout = new QHBoxLayout;
    resultTextBox=new QLineEdit();
    tmpLayout->addWidget(resultTextBox);
    tmpVLayout->insertLayout(0, tmpLayout);

    tmpLayout = new QHBoxLayout;
    tmpLayout->addWidget(new QLabel("Enter the name of the new mission:"));
    tmpVLayout->insertLayout(0, tmpLayout);
    //
    return tmpVLayout;


}

QPushButton * MainApp::createNewKey(QString keyValue){
    QPushButton *tmp = new QPushButton();
    QString        style = QString(DEFAULT_STYLE_BUTTON) + QString(DEFAULT_BACKGROUND_BUTTON);
    QSize          imageDim;
    int            width = 0, height = 0;


    imageDim.setWidth(128);
    imageDim.setHeight(128);

    tmp->setText(keyValue);
    width = KEY_WIDTH_EMBEDDED;
    height = KEY_HEIGHT_EMBEDDED;
    style += QString(EMBEDDED_KEYBOARD);
    /*if (this->isEmbeddedKeyboard() == true) {
        width = KEY_WIDTH_EMBEDDED;
        height = KEY_HEIGHT_EMBEDDED;
        style += QString(EMBEDDED_KEYBOARD);
    }
    else {
        width = 54;
        height = 40;
    }*/
    tmp->setObjectName(keyValue);
    tmp->setMinimumSize(width, height);
    tmp->setMaximumSize(width, height);
    tmp->setStyleSheet(style);
    //tmp->setVisible(true);


    if(!keyValue.compare("")){
        tmp->setEnabled(false);
    }
    else{
        tmp->setEnabled(true);
        keysList->append(tmp->text());
    }

    return (tmp);
}




void MainApp::joystickButtonEventMessage(QString button,QGameControllerButtonEvent* event){

    if(button==button_A && !event->pressed()){
        qDebug()<<"BUTTON A message";
        int item= projectList->currentRow();

        deleteMission(projectListStrings->at(item),projectList->currentItem());
        disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMessage(QString,QGameControllerButtonEvent*)));
        connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
        connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));
        closeMessage();
    }
    else if(button==button_B && !event->pressed()){
        qDebug()<<"BUTTON B message";
        disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMessage(QString,QGameControllerButtonEvent*)));
        connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
        connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));
        closeMessage();
    }
}



