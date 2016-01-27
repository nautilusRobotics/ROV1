#-------------------------------------------------
#
# Project created by QtCreator 2015-07-30T15:13:14
#
#-------------------------------------------------

QT += core gui network opengl multimedia  multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InterfazControl
TEMPLATE = app

SOURCES += main.cpp\
    joystickwidget.cpp \
    qgamecontroller.cpp \
    qgamecontroller_linux.cpp \
    qmpwidget.cpp \
    sendaction.cpp \
    missionwidget.cpp \
    openrtsp.cpp \
    myitem.cpp \
    missionexplorer.cpp \
    thumbviewer.cpp \
    exportmanager.cpp \
    mywidgetusb.cpp \
    mainapp.cpp \
    datathread.cpp

HEADERS  += \
    joystickwidget.h \
    qgamecontroller.h \
    qgamecontroller-global.h \
    qgamecontroller_linux_p.h \
    qgamecontroller_p.h \
    qmpwidget.h \
    sendaction.h \
    com.h \
    missionwidget.h \
    openrtsp.h \
    myitem.h \
    missionexplorer.h \
    thumbviewer.h \
    exportmanager.h \
    mywidgetusb.h \
    main.h \
    mainapp.h \ 
    datathread.h


FORMS += \
    Intro.ui

RESOURCES += \
    icons/icons.qrc




