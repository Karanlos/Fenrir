#-------------------------------------------------
#
# Project created by QtCreator 2011-04-16T15:59:46
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

TARGET = FenrirNodeEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    oglwidget.cpp \
    pngloader.cpp

HEADERS  += mainwindow.h \
    oglwidget.h \
    pngloader.h

FORMS += \
    mainwindow.ui

LIBS += "/usr/local/lib/libpng15.a"

