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
    qcustomplot.cpp \
    histogramwidget.cpp \
    imagewidget.cpp \
    imagecontainer.cpp \
    baseparametr.cpp \
    parametrsquare.cpp \
    parameterexist.cpp \
    parametrmasscenter.cpp \
    parametrperimetr.cpp \
    imageobject.cpp \
    filterbinary.cpp \
    imageprocessing.cpp


HEADERS  += mainwindow.h \
                            imageactionwidget.h \
    qcustomplot.h \
    histogramwidget.h \
    imagewidget.h \
    imagecontainer.h \
    baseparametr.h \
    label.h \
    parametrsquare.h \
    parameterexist.h \
    parametrmasscenter.h \
    parametrperimetr.h \
    imageobject.h \
    filterbase.h \
    filterbinary.h \
    imageprocessing.h

FORMS    += mainwindow.ui \
                     imageactionwidget.ui \
    imagewidget.ui
