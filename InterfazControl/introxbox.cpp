#include "introxbox.h"

extern QString createPath(QString path);

IntroXbox::IntroXbox(QWidget *parent) :
    QWidget(parent)
{

    QIcon icon(createPath("icons/nautilus128x128.svg"));
    setWindowIcon(icon);
    setWindowTitle("Nautilus Commander");
    ui.setupUi(this);

    btnNew=ui.btnNew;
    btnNew->setStyleSheet(QPUSH_STYLE_START);

    btnOpen=ui.btnOpen;
    btnOpen->setStyleSheet(QPUSH_STYLE_OPEN);

    btnOff = ui.btnOff;
    btnOff->setStyleSheet(QPUSH_STYLE_OFF);

    lblHelp = ui.lblHelp;
    lblHelp->setStyleSheet(QLABEL_STYLE_HELP);


    /********************************  Joystick *****************************************************/
    joystick=new JoystickWidget();
    connect(joystick,SIGNAL(updateStatus(bool)),this,SLOT(updateControlStatus(bool)));
    connect(joystick,SIGNAL(joystickButtonEvent(QString,QGameControllerButtonEvent*)),this,SLOT(handleJoystickButtonEvent(QString,QGameControllerButtonEvent*)));
    connect(joystick,SIGNAL(joystickAxisEvent(QString,int)),this,SLOT(handleJoystickAxisEvent(QString,int)));
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

}

void IntroXbox::handleNewBtn(QString missionName){

  if(missionName.compare("")){
      QRegExp rx ("[^a-zA-Z0-9]");
      QString fixedName =missionName.replace(rx,"");

      if(fixedName.compare(""))
          runMission(fixedName);      
      else
          showToast("Invalid mission name",1000);

  }
  else
      showToast("Invalid mission name",1000);


}

void IntroXbox::showMessage(QString message){
    toast=new QMessageBox();
    toast->setText(message);
    toast->setIcon(QMessageBox::Warning);
    toast->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    toast->setStyleSheet(QMESAGE_STYLE);

    QSpacerItem* horizontalSpacer = new QSpacerItem(1000, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QGridLayout* layout = (QGridLayout*)toast->layout();
    layout->addItem(horizontalSpacer, layout->rowCount(), 0, 1, layout->columnCount());

    toast->exec();
}

void IntroXbox::showToast(QString message, int time){
    QTimer::singleShot(time,Qt::PreciseTimer ,this, SLOT(closeToast()));
    showMessage(message);
}

void IntroXbox::closeToast(){
    qDebug()<<"Timer Off";
    toast->close();

}

void IntroXbox::createProjectList(){

    QDirIterator it(missionsPath,QDir::NoDotAndDotDot | QDir::AllDirs);

    while (it.hasNext()) {
        QFileInfo Info(it.next());
        QString missionName = QString(Info.fileName());

#ifdef DEBUG_INTRO
        qDebug() <<missionName;
#endif


        QListWidgetItem *item = new QListWidgetItem();
        item->setSizeHint(QSize(item->sizeHint().width(), 60));

        myItem *myListItem = new myItem(0,missionName);
        connect(myListItem,SIGNAL(continueSignal(QString)),this,SLOT(runMission(QString)));
        connect(myListItem,SIGNAL(deleteSignal(QString,QListWidgetItem*)),this,SLOT(deleteMission(QString,QListWidgetItem*)));
        connect(myListItem,SIGNAL(exploreSignal(QString)),this,SLOT(exploreMission(QString)));
        exm->setMissionName(missionName);
        connect(myListItem,SIGNAL(exportSignal()),exm,SLOT(launchDialog()));
        myListItem->setWItem(item);


        projectList->addItem(item);
        projectList->setItemWidget(item, myListItem );
    }
}

void IntroXbox::runMission(QString missionName){
#ifdef DEBUG_INTRO
      qDebug() <<"continue "+missionName;
#endif

   this->mission=new MissionWidget(0,missionName,this);
   this->close();
   mission->show();

}

void IntroXbox::exploreMission(QString missionName){

#ifdef DEBUG_INTRO
      qDebug() <<"explore "+missionName;
#endif
  MissionExplorer *missionExplorer=new MissionExplorer(0,missionName,this);
  this->close();
  missionExplorer->show();
}

void IntroXbox::deleteMission(QString missionName,QListWidgetItem *item){

    QString msg=QString("Are you sure?\nThe Mission %1 including all files are going to be deleted").arg(missionName);
    QMessageBox::StandardButton reply;

      reply = QMessageBox::warning(this, "Alert", msg, QMessageBox::Ok|QMessageBox::Cancel);
      if (reply == QMessageBox::Ok) {

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

}

void IntroXbox::reOpen(){

    qDebug("RE OPEN");
    delete(projectList);
    projectList= new QListWidget();
    projectList->setSelectionMode (QAbstractItemView::NoSelection);
    projectList->setFixedHeight(150);
    createProjectList();
}

void IntroXbox::showEvent(QShowEvent *ev){
    qDebug("Show Event");

    if(isOpen)
       reOpen();

    isOpen=true;
}

void IntroXbox::handleButtonOff(){
    QString msg=QString("Are you sure? \n The robot is save? \n the system is going to turning off");
    QMessageBox::StandardButton reply;

    reply = QMessageBox::warning(this, "Alert", msg, QMessageBox::Ok|QMessageBox::Cancel);
    if (reply == QMessageBox::Ok)this->close();

}

void IntroXbox::handleJoystickButtonEvent(QString button,QGameControllerButtonEvent* event){
   if(!isKeyboard){
    if(button==button_A && !event->pressed()){
       switch(focused){
          case 0:
            qDebug("option0");
            lauchKeyBoard();
           break;
          case 1:
           qDebug("option1");
            break;
          case 2:
           qDebug("option2");
            break;
          case maxOptions:
           qDebug("option3");
           break;
       }
    }
   }
}

void IntroXbox::handleJoystickAxisEvent(QString axis, int value){   
    if(!isKeyboard){
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



}

void IntroXbox::updateControlStatus(bool isConnected){}

void IntroXbox::handleCloseKeyboardEvent(bool cancelled,QString result){
    if(!cancelled)
      handleNewBtn(result);

      isKeyboard=false;
}

void IntroXbox::lauchKeyBoard(){
    keyboard = new widgetKeyBoard(true);
    keyboard->setZoomFacility(false);
    keyboard->enableSwitchingEcho(false); // enable possibility to change echo through keyboard
    keyboard->initLayout(keysList,keyBoardLayout,resultTextBox);
    connect(keyboard,SIGNAL(closeKeyboardEvent(bool,QString)),this,SLOT(handleCloseKeyboardEvent(bool,QString)));

    keyboard->show(NULL);
    keyboard->move(this->x()+200, this->y()/2 + this->keyboard->height()+200); // to move keyboard
    keyboard->setJoystick(joystick);
    isKeyboard=true;
}

QVBoxLayout * IntroXbox::generateKeyboard(void)
{
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

QPushButton * IntroXbox::createNewKey(QString keyValue)
{
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
