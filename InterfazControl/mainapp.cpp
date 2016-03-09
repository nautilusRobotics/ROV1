#include "mainapp.h"
#include <QPixmap>
#include <QBitmap>


extern QString createPath(QString path);

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
    helpList=new QStringList();
    helpList->append(QMESAGE_STYLE_HELP_INTRO);
    helpList->append(QMESAGE_STYLE_HELP_XBOX);
    projectListBools=new QBitArray();

    lblListWidget=ui.lblListWidget;

    openMissionBox=ui.openMissionBox;
    openMissionBox->setVisible(false);

    lblTitle=ui.label_title;

    lblShadow=ui.lblShadow;
    lblShadow->setVisible(false);

    lblGamepadError=ui.lblGamepad;
    lblGamepadError->setVisible(false);

    lblRepairMessage=ui.lblRepair;
    lblRepairMessage->setVisible(false);
  


    /********************************  Joystick *****************************************************/
    joystick=new JoystickWidget(this);
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
    openProjectRow=0;

    secretKey=0;
    secretKeyList=new QStringList();
    secretKeyList->append(button_Y); secretKeyList->append(button_X);secretKeyList->append(button_B); secretKeyList->append(button_LB); secretKeyList->append(button_RB); secretKeyList->append(button_RB);  secretKeyList->append(button_LB);  secretKeyList->append(button_B);  secretKeyList->append(button_B);  secretKeyList->append(button_B);
    
     

    keyBoardBox=ui.keyboardGroup;
    keyBoardBox->setVisible(false);


    keyboardMatrix[0][0]=ui.keyQ; keyboardMatrix[0][1]=ui.keyW;  keyboardMatrix[0][2]=ui.keyE; keyboardMatrix[0][3]=ui.keyR; keyboardMatrix[0][4]=ui.keyT; keyboardMatrix[0][5]=ui.keyY; keyboardMatrix[0][6]=ui.keyU; keyboardMatrix[0][7]=ui.keyI; keyboardMatrix[0][8]=ui.keyO; keyboardMatrix[0][9]=ui.keyP;
    keyboardMatrix[1][0]=ui.keyA; keyboardMatrix[1][1]=ui.keyS;  keyboardMatrix[1][2]=ui.keyD; keyboardMatrix[1][3]=ui.keyF; keyboardMatrix[1][4]=ui.keyG; keyboardMatrix[1][5]=ui.keyH; keyboardMatrix[1][6]=ui.keyJ; keyboardMatrix[1][7]=ui.keyK; keyboardMatrix[1][8]=ui.keyL; keyboardMatrix[1][9]=ui.keyL;
    keyboardMatrix[2][0]=ui.keyErase; keyboardMatrix[2][1]=ui.keyZ;  keyboardMatrix[2][2]=ui.keyX; keyboardMatrix[2][3]=ui.keyC; keyboardMatrix[2][4]=ui.keyV; keyboardMatrix[2][5]=ui.keyB; keyboardMatrix[2][6]=ui.keyN; keyboardMatrix[2][7]=ui.keyM; keyboardMatrix[2][8]=ui.keyBackspace; keyboardMatrix[2][9]=ui.keyBackspace;
    keyboardMatrix[3][0]=ui.keyCancel; keyboardMatrix[3][1]=ui.keyCancel;  keyboardMatrix[3][2]=ui.keySpace; keyboardMatrix[3][3]=ui.keySpace; keyboardMatrix[3][4]=ui.keySpace; keyboardMatrix[3][5]=ui.keySpace; keyboardMatrix[3][6]=ui.keySpace; keyboardMatrix[3][7]=ui.keyEnter; keyboardMatrix[3][8]=ui.keyEnter; keyboardMatrix[3][9]=ui.keyEnter;
    keyRow=0;
    keyCol=0;
    resultKeyBoard=ui.keyboardLine;


    sendAction=new SendAction(this);
    isWorkingOffline=false;
    isRobotOnline=false;

      #ifdef Q_PROCESSOR_ARM
     qDebug()<<"Starting pacman";
     QProcess pcmanfm;
     pcmanfm.start("pcmanfm -w /home/olimex/Documents/nautilusOff.png"); //Change WallPaper 
     pcmanfm.waitForFinished();
     QString pacman(pcmanfm.readAllStandardOutput());
     pcmanfm.close();
     qDebug()<<"pacman out" + pacman;
     #endif

     helpIdx=0;


}

void MainApp::handleNewBtn(QString missionName){

    disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
    disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));

    if(missionName.compare(""))
        runMission(missionName);
    else
        showToast("Invalid mission name",100);

}

void MainApp::showMessage(QString message, bool okCancelbtns){

    lblShadow->setVisible(true);
    toast=new QDialog(this);
    int w=507;
    int h=323;
    int x=(width()/2)-(w/2);
    int y=(height()/2)-(h/2);
    toast->setGeometry(x,y,w,h);
    toast->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);

    if(!okCancelbtns)
        toast->setStyleSheet(QMESAGE_STYLE_INFO);
    else
        toast->setStyleSheet(QMESAGE_STYLE_CONFIRM);


    QGridLayout* layout = new QGridLayout(this);


    QSpacerItem* verticalSpacer = new QSpacerItem(0, 30, QSizePolicy::Minimum);
    layout->addItem(verticalSpacer, 0, 0, 1, 1);


    QLabel *msgLbl=new QLabel(message);
    msgLbl->setFocusPolicy(Qt::NoFocus);
    msgLbl->setStyleSheet("color: rgb(153, 153, 153);font: bold 14pt;");
    layout->addWidget(msgLbl,1,0,1,1,Qt::AlignCenter);


    toast->setLayout(layout);
    toast->show();

}

void MainApp::showToast(QString message, int time){    
    showMessage(message,false);
    QTimer::singleShot(time,Qt::PreciseTimer ,this, SLOT(preCloseMessage()));
}

void MainApp::preCloseMessage(){
    sleep(2);
    closeMessage(true);
}

void MainApp::closeMessage(bool reconectMenu){
    qDebug()<<"closeMessage";
    lblShadow->setVisible(false);
    toast->close();

    if(reconectMenu){
        connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
        connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));
    }
    else{
        connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
        connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));
    }
}

void MainApp::createProjectList(){

    QDirIterator it(missionsPath,QDir::NoDotAndDotDot | QDir::AllDirs);
    projectListStrings->clear();
    projectList->clear();
    projectListBools->clear();
    int idx=0;
    bool isConnected=checkRobot();


    while (it.hasNext()) {
        QFileInfo Info(it.next());
        QString missionName = QString(Info.fileName());

        qDebug() <<missionName;

        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(item->sizeHint().width(), 60));

        myItem *myListItem = new myItem(0,missionName,isConnected);
        projectListStrings->append(missionName);
        projectListBools->resize(idx+1);
        projectListBools->setBit(idx,myListItem->isExploreAndExport());
        idx++;

        projectList->addItem(item);
        projectList->setItemWidget(item, myListItem);
    }
}

void MainApp::runMission(QString missionName){
   qDebug() <<"runMission "+missionName;
   disconnect(joystick,SIGNAL(updateStatus(bool)),this,SLOT(updateControlStatus(bool)));
   missionWidget=new MissionWidget(this,missionName,joystick,&ui,sendAction);
   connect(missionWidget,SIGNAL(returnToHome()),this,SLOT(showHome()));
   connect(missionWidget,SIGNAL(controlOut()),this,SLOT(controlOut()));
   stackedWidget->setCurrentIndex(1);
}

void MainApp::exploreMission(QString missionName){

  qDebug() <<"explore "+missionName;
  disconnect(joystick,SIGNAL(updateStatus(bool)),this,SLOT(updateControlStatus(bool)));
  disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
  disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));

  stackedWidget->setCurrentIndex(2);
  missionExplorer=new MissionExplorer(this,missionName,joystick,&ui);
  connect(missionExplorer,SIGNAL(returnToHome()),this,SLOT(showHome()));
  connect(missionExplorer,SIGNAL(controlOut()),this,SLOT(controlOut()));
}

void MainApp::deleteMission(QString missionName,QListWidgetItem *item){

       qDebug() <<"delete "+missionName;
       QString dirName=QString("%1/%2").arg(missionsPath).arg(missionName);

          QDir dir(dirName);

          if(dir.removeRecursively()){
              qDebug()<<"delete OK";
              projectList->takeItem(projectList->row(item));

          }
          else
             qDebug()<<"no delete";

}

void MainApp::showHome(){
   connect(joystick,SIGNAL(updateStatus(bool)),this,SLOT(updateControlStatus(bool)));
   connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
   connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));

   stackedWidget->setCurrentIndex(0);
}

void MainApp::handleButtonOff(){
    disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
    disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));
    connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOffMessage(QString,QGameControllerButtonEvent*)));
    showMessage("\nThe system will shut down\n       Please put the robot safely",true);
}

void MainApp::joystickButtonEventMenu(QString button,QGameControllerButtonEvent* event){
   if(button==button_A && !event->pressed()){            
       rumble.start(createPath("rumbleGamepad.o"));

       switch(focused){        
          case 0:{
            qDebug("option Start");
            if(checkRobot()){             
              launchKeyBoard();
            }
            else{
              disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
              disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));
              showToast("The Robot is not Online",1000);
            }

           break;
           }
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
            handleButtonOff();
            break;

          case maxOptions:
               qDebug("option Help");
               disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
               disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));
               connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventHelp(QString,QGameControllerButtonEvent*)));
               connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventHelp(QString,int)));
               lblShadow->setVisible(true);
               help=new QDialog(this);
               int w=1198;
               int h=732;
               int x=(width()/2)-(w/2);
               int y=(height()/2)-(h/2);
               help->setGeometry(x,y,w,h);
               help->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
               help->setStyleSheet(QMESAGE_STYLE_HELP_INTRO);
               help->show();
           break;
       }        

    }
    else  if(button==button_start && !event->pressed()){
      // sendAction->sendComando("goro1600");
    }
    else if(!event->pressed()){
      secretKey=(button==secretKeyList->at(secretKey))?secretKey+1:0;


      qDebug()<<QString("Secret Key %1").arg(secretKey);


      if(secretKey==secretKeyList->length()){
        #ifdef Q_PROCESSOR_ARM
        QString run=createPath("controlOn.sh"); //Disable Control          
        QProcess initControl;
        initControl.start(run);        
        initControl.waitForFinished();
        initControl.close();
        
        disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
        disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));

        QProcess lxpanel;
        lxpanel.start("lxpanel");
        lxpanel.waitForFinished();
        lxpanel.close();
        #else
            this->close();
        #endif

	}
    }

}

void MainApp::joystickAxisEventMenu(QString axis, int value){
        if((!axis.compare(axis_cross_vertical) || !axis.compare(axis_left_vertical) || !axis.compare(axis_right_vertical)) && value==1000){          
          rumble.start(createPath("rumbleGamepad.o"));
          this->focusNextChild();        
          focused++;
          focused=(focused>maxOptions)?0:focused;

        }
        if((!axis.compare(axis_cross_vertical) || !axis.compare(axis_left_vertical) || !axis.compare(axis_right_vertical)) && value==-1000){           
           rumble.start(createPath("rumbleGamepad.o"));
           this->focusPreviousChild();
           focused--;
           focused=(focused<0)?maxOptions:focused;
        }
}

void MainApp::joystickAxisEventOpen(QString axis, int value){

    if((!axis.compare(axis_cross_vertical) || !axis.compare(axis_left_vertical) || !axis.compare(axis_right_vertical)) && value==1000){
       rumble.start(createPath("rumbleGamepad.o"));
       openProjectRow=(openProjectRow+1>projectList->count()-1)?0:openProjectRow+1;


    }
    if((!axis.compare(axis_cross_vertical) || !axis.compare(axis_left_vertical) || !axis.compare(axis_right_vertical)) && value==-1000){
        rumble.start(createPath("rumbleGamepad.o"));
        openProjectRow=(openProjectRow-1<0)?0:openProjectRow-1;

    }

    projectList->setCurrentRow(openProjectRow);
}

void MainApp::joystickButtonEventOpen(QString button,QGameControllerButtonEvent* event){
    if(button==button_A && !event->pressed()){
        rumble.start(createPath("rumbleGamepad.o"));
        int item= projectList->currentRow();

        if(sendAction->isConnected()){
            runMission(projectListStrings->at(item));
            lblTitle->setText("Welcome to Nautilus Commander");
            openMissionBox->setVisible(false);
            disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
            disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));
        }

    }
    else if(button==button_X && !event->pressed()){
        rumble.start(createPath("rumbleGamepad.o"));
        int item= projectList->currentRow();

        if(projectListBools->at(item)){
            disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
            disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));
            exploreMission(projectListStrings->at(item));
            lblTitle->setText("Welcome to Nautilus Commander");
            openMissionBox->setVisible(false);
        }
    }
    else if(button==button_B && !event->pressed()){
        rumble.start(createPath("rumbleGamepad.o"));
        int item= projectList->currentRow();
        QString msg=QString("Are you sure you want to delete the Mission:\n \"%1\"\n You can't undo this action").arg(projectListStrings->at(item));

        disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
        disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));
        connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMessage(QString,QGameControllerButtonEvent*)));

        showMessage(msg,true);
    }
    else if(button==button_Y && !event->pressed()){
        rumble.start(createPath("rumbleGamepad.o"));
        int item= projectList->currentRow();
        if(projectListBools->at(item)){
            lblShadow->setVisible(true);
            exm->setMissionName(projectListStrings->at(item));
            disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
            disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));
            connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),exm,SLOT(joystickButtonUSB(QString,QGameControllerButtonEvent*)));
            connect(exm,SIGNAL(success(bool)),this,SLOT(successExport(bool)));
            exm->launchDialog();
        }

    }
    else if(button==button_back && !event->pressed()){
       rumble.start(createPath("rumbleGamepad.o"));
       disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
       disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));
       connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
       connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));
       lblTitle->setText("Welcome to Nautilus Commander");
       openMissionBox->setVisible(false);
    }
}

void MainApp::updateControlStatus(bool isConnected){
    if(!isConnected){
        lblShadow->setVisible(true);
        lblGamepadError->setVisible(true);
        qDebug()<<"Trying to reconnect";
        QTimer::singleShot(4000,Qt::PreciseTimer ,this, SLOT(reconnectJoystick()));
    }

}


void MainApp::reconnectJoystick(){
    int maxTries=5;
    bool succes=false;
    for(int i=0;i<maxTries;i++){
     if(joystick->reconnect()){
         succes=true;
         break;
     }
    }

    lblGamepadError->setVisible(false);

    if(succes)
        lblShadow->setVisible(false);
    else{
        qDebug()<<"CONTROLLER NOT FOUND";
        lblRepairMessage->setVisible(true);
        QTimer::singleShot(5000,Qt::PreciseTimer ,this, SLOT(controlCrash()));
    }
}

void MainApp::controlCrash(){

#ifdef Q_PROCESSOR_ARM
        sendAction->sendComando(POWEROFF_ROBOT);
        QString run=createPath("controlOn.sh");  //Disable Control
        QProcess initControl;
        initControl.start(run);
        initControl.waitForFinished();
        initControl.close();
       

        QProcess powerOff;
        powerOff.start("sudo /mnt/disk1/NautilusOne/powerOff.sh");
        powerOff.waitForFinished();
        powerOff.close();

#endif

        this->close();
}

void MainApp::handleCloseKeyboardEvent(bool cancelled,QString result){
    disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventKeyBoard(QString,int)));
    disconnect(joystick,SIGNAL(joystickButtonEvent(QString ,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventKeyBoard(QString,QGameControllerButtonEvent*)));
    connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
    connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));

    keyBoardBox->setVisible(false);
    lblShadow->setVisible(false);
    setNormalkey();

    if(!cancelled)
      handleNewBtn(result);
}

void MainApp::launchKeyBoard(){

    keyBoardBox->setVisible(true);
    lblShadow->setVisible(true);
    keyRow=0; keyCol=0;
    keyboardMatrix[keyRow][keyCol]->setStyleSheet(QKEY_SELECT_STYLE);
    resultKeyBoard->setText("");

    disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
    disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));

    connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventKeyBoard(QString,QGameControllerButtonEvent*)));
    connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventKeyBoard(QString,int)));

}

void MainApp::joystickButtonEventMessage(QString button,QGameControllerButtonEvent* event){

    if(button==button_A && !event->pressed()){
        rumble.start(createPath("rumbleGamepad.o"));
        qDebug()<<"BUTTON A message";
        int item= projectList->currentRow();

        deleteMission(projectListStrings->at(item),projectList->currentItem());
        disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMessage(QString,QGameControllerButtonEvent*)));
        closeMessage(false);
    }
    else if(button==button_B && !event->pressed()){
        rumble.start(createPath("rumbleGamepad.o"));
        qDebug()<<"BUTTON B message";
        disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMessage(QString,QGameControllerButtonEvent*)));        
        closeMessage(false);
    }
}

void MainApp::joystickButtonEventOffMessage(QString button,QGameControllerButtonEvent* event){

    if(button==button_A && !event->pressed()){
      //rumble.start(createPath("rumbleGamepad.o"));
      if(checkRobot())
        sendAction->sendComando(POWEROFF_ROBOT);

#ifdef Q_PROCESSOR_ARM
        QString run=createPath("controlOn.sh");  //Disable Control          
        QProcess initControl;
        initControl.start(run);        
        initControl.waitForFinished();
        initControl.close();
     
        QProcess powerOff;
        powerOff.start("sudo /mnt/disk1/NautilusOne/powerOff.sh");
        powerOff.waitForFinished();
        powerOff.close();  
 
#endif
        this->close();
        closeMessage(true);
    }
    else if(button==button_B && !event->pressed()){
        rumble.start(createPath("rumbleGamepad.o"));
        disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOffMessage(QString,QGameControllerButtonEvent*)));        
        closeMessage(true);
    }
}

void MainApp::joystickAxisEventKeyBoard(QString axis, int value){
        if((!axis.compare(axis_cross_vertical) || !axis.compare(axis_left_vertical) || !axis.compare(axis_right_vertical)) && value==1000){
            rumble.start(createPath("rumbleGamepad.o"));
            setNormalkey();
            keyRow=(keyRow+1>3)?3:keyRow+1;
            setSelectkey();
        }
        if((!axis.compare(axis_cross_vertical) || !axis.compare(axis_left_vertical) || !axis.compare(axis_right_vertical)) && value==-1000){
            rumble.start(createPath("rumbleGamepad.o"));
            setNormalkey();
            keyRow=(keyRow-1<0)?0:keyRow-1;
            setSelectkey();
        }
        if((!axis.compare(axis_cross_horizontal) || !axis.compare(axis_left_horizontal) || !axis.compare(axis_right_horizontal)) && value==1000){
            rumble.start(createPath("rumbleGamepad.o"));
            setNormalkey();

            if(keyRow==3 && (keyCol>=2 && keyCol <=6))
             keyCol=9;
            else if(keyRow==3 && keyCol==0)
              keyCol=2;
            else
            keyCol=(keyCol+1>9)?9:keyCol+1;

            setSelectkey();
        }
        if((!axis.compare(axis_cross_horizontal) || !axis.compare(axis_left_horizontal) || !axis.compare(axis_right_horizontal)) && value==-1000){
            rumble.start(createPath("rumbleGamepad.o"));
            setNormalkey();

            if(keyRow==3 && (keyCol>=2 && keyCol <=6))
             keyCol=0;
            else if((keyRow==3  || keyRow==2 ) && keyCol==9)
              keyCol=7;
            else
            keyCol=(keyCol-1<0)?0:keyCol-1;

            setSelectkey();
        }
}

void MainApp::setNormalkey(){
    QString style;
    if( keyRow==2 && keyCol==0 )
       style=QKEY_NORMAL_ERASE_STYLE;
    else if( keyRow==2 && (keyCol==8 || keyCol==9))
       style=QKEY_NORMAL_BACKSPACE_STYLE;
    else
       style=QKEY_NORMAL_STYLE;

    keyboardMatrix[keyRow][keyCol]->setStyleSheet(style);
}

void MainApp::setSelectkey(){

    QString style;
    if( keyRow==2 && keyCol==0 )
       style=QKEY_SELECT_ERASE_STYLE;
    else if( keyRow==2 && (keyCol==8 || keyCol==9))
       style=QKEY_SELECT_BACKSPACE_STYLE;
    else
       style=QKEY_SELECT_STYLE;

    keyboardMatrix[keyRow][keyCol]->setStyleSheet(style);
}

void MainApp::joystickButtonEventKeyBoard(QString button,QGameControllerButtonEvent* event){

    if(button==button_A && !event->pressed()){
        rumble.start(createPath("rumbleGamepad.o"));
         QString newKey = keyboardMatrix[keyRow][keyCol]->text();
         QString tmpReceiptString = resultKeyBoard->text();

         int tmpPos = resultKeyBoard->cursorPosition();


        if(!newKey.compare("Cancel")){
            handleCloseKeyboardEvent(true,resultKeyBoard->text());
        }
        else if(!newKey.compare("Enter")){
            handleCloseKeyboardEvent(false,resultKeyBoard->text());
        }
        else if(keyRow==2 && keyCol==0){
            resultKeyBoard->setText("");
        }
        else if(keyRow==2 && (keyCol==8 || keyCol==9)){
            if (tmpPos-1 >= 0) {
                     tmpReceiptString = tmpReceiptString.remove(tmpPos-1, 1);
                     resultKeyBoard->setText(tmpReceiptString);
                     resultKeyBoard->setCursorPosition(tmpPos-1);
                     resultKeyBoard->setSelection(tmpPos-2, 1);
            }
        }
        else{
            newKey=(!newKey.compare("space"))?" ":newKey;
            if(tmpPos!=0)newKey=newKey.toLower();
            tmpReceiptString = tmpReceiptString.insert(tmpPos, newKey);
            resultKeyBoard->setText(tmpReceiptString);
            resultKeyBoard->setCursorPosition(tmpPos+1);
            resultKeyBoard->setSelection(tmpPos, 1);
        }
    }
}

bool MainApp::checkRobot(){
  if(sendAction->isConnected())
      return true;


  sendAction->conectClient();
  return sendAction->isConnected();
}

void MainApp::successExport(bool /*unused success*/){
    qDebug()<<"succes Export";
    lblShadow->setVisible(false);
    disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),exm,SLOT(joystickButtonUSB(QString,QGameControllerButtonEvent*)));
    connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventOpen(QString,QGameControllerButtonEvent*)));
    connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventOpen(QString,int)));
     //exm->acceptDialogs();
}

void MainApp::joystickButtonEventHelp(QString button,QGameControllerButtonEvent* event){

    if(button==button_B && !event->pressed()){
      rumble.start(createPath("rumbleGamepad.o"));
      lblShadow->setVisible(false);

      disconnect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventHelp(QString,QGameControllerButtonEvent*)));
      disconnect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventHelp(QString,int)));

      connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(joystickButtonEventMenu(QString,QGameControllerButtonEvent*)));
      connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(joystickAxisEventMenu(QString,int)));
      help->accept();
    }
}

void MainApp::joystickAxisEventHelp(QString axis, int value){
    if((!axis.compare(axis_cross_horizontal) || !axis.compare(axis_left_horizontal) || !axis.compare(axis_right_horizontal)) &&  value==1000  ){
      rumble.start(createPath("rumbleGamepad.o"));
      helpIdx=(helpIdx<(helpList->size()-1))?helpIdx+1:helpIdx;
      help->setStyleSheet(helpList->at(helpIdx));
    }
    else if((!axis.compare(axis_cross_horizontal) || !axis.compare(axis_left_horizontal) || !axis.compare(axis_right_horizontal)) &&   value==-1000){
      rumble.start(createPath("rumbleGamepad.o"));
      helpIdx=(helpIdx>0)?helpIdx-1:helpIdx;
      help->setStyleSheet(helpList->at(helpIdx));
    }

}

void MainApp::controlOut(){
    showHome();
    updateControlStatus(false);
}
