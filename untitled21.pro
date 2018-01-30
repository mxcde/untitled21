#-------------------------------------------------
#
# Project created by QtCreator 2018-01-24T10:31:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled21
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
INCLUDEPATH += D:\opencv\opencv\build\include\opencv  \
               D:\opencv\opencv\build\include  \
               D:\opencv\opencv\build\include\opencv2

LIBS += -LD:\opencv\opencv\build\x64\vc14\lib \
         -lopencv_world330 \
         -lopencv_world330d
