#-------------------------------------------------
#
# Project created by QtCreator 2019-03-20T11:00:45
#
#-------------------------------------------------

QT       += core gui

#Ҫ����QNetworkInterface����Ҫ��������ģ��
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mip_app
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

# ����exe��ͼ��
RC_ICONS = ip.ico
