#include "thumbviewer.h"

ThumbViewer::ThumbViewer(QWidget *parent, QString fp) :
    QWidget(parent)
{

  this->filePath=fp;


  layout=new QGridLayout();
  btn_action=new QPushButton();


  if(!filePath.mid(filePath.length()-4,filePath.length()).compare("jpeg")){
      isVideo=false;
      QImage img(filePath);
      thumb =new QImage( img.scaled(50, 25, Qt::IgnoreAspectRatio, Qt::FastTransformation));

      QLabel *imgDisplayLabel = new QLabel("");
      imgDisplayLabel->setPixmap(QPixmap::fromImage(*thumb));
      layout->addWidget(imgDisplayLabel,0,0);
      btn_action->setText("Show");
      /*QString str=QString("background-image: url(%1)").arg(filePath);
      btn_action->setStyleSheet(str);*/
      layout->addWidget(btn_action,0,1,1,4);
  }
  else{
      isVideo=true;
      icon_video=new QLabel("<img src=\"./icons/movie.png\">");

      layout->addWidget(icon_video,0,0);
      /*btn_action->setIcon(QIcon("./icons/movie.png"));
      btn_action->setIconSize(QSize(32,32));*/

      btn_action->setText("Play");
      layout->addWidget(btn_action,0,1,1,4);
  }

  this->setLayout(layout);

}
