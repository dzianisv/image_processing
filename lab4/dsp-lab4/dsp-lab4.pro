#-------------------------------------------------
#
# Project created by QtCreator 2013-11-19T20:48:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dsp-lab4
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        imageactionwidget.cpp \
    imagecontainer.cpp \
    qcustomplot.cpp \
    logarithmcorrection.cpp \
    robertsfilter.cpp \
    histogramwidget.cpp


HEADERS  += mainwindow.h \
                            imageactionwidget.h \
    imagecontainer.h \
    qcustomplot.h \
    logarithmcorrection.h \
    robertsfilter.h \
    histogramwidget.h

FORMS    += mainwindow.ui \
                     imageactionwidget.ui
