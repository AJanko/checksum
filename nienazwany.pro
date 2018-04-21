#-------------------------------------------------
#
# Project created by QtCreator 2018-04-16T14:05:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nienazwany
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    CRC32.cpp \
    md5.cpp \
    sha-1.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

CONFIG += static
