#-------------------------------------------------
#
# Project created by QtCreator 2015-07-30T15:13:14
#
#-------------------------------------------------

QT += core gui network opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = InterfazControl
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    joystickwidget.cpp \
    player.cpp \
    qgamecontroller.cpp \
    qgamecontroller_linux.cpp \
    qmpwidget.cpp \
    sendaction.cpp

HEADERS  += mainwindow.h \
    joystickwidget.h \
    player.h \
    qgamecontroller.h \
    qgamecontroller-global.h \
    qgamecontroller_linux_p.h \
    qgamecontroller_p.h \
    qmpwidget.h \
    sendaction.h \
    com.h

FORMS    += mainwindow.ui




