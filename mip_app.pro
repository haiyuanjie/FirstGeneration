#-------------------------------------------------
#
# Project created by QtCreator 2019-03-20T11:00:45
#
#-------------------------------------------------

QT       += core gui

#要包含QNetworkInterface，需要加上网络模块
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mip_app
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

# 测试exe加图标
RC_ICONS = ip.ico
