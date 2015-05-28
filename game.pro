#-------------------------------------------------
#
# Project created by QtCreator 2015-05-13T00:36:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    win.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    win.h

FORMS    += mainwindow.ui \
    dialog.ui \
    win.ui

RESOURCES += \
    image.qrc
