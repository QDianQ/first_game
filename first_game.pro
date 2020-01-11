TEMPLATE = app
CONFIG +=  c++11
#CONFIG -= app_bundle

QT += core gui widgets

SOURCES += \
        additional_function.cpp \
        ccell.cpp \
        cgamefield.cpp \
        main.cpp \
        mainwindow.cpp

HEADERS += \
    additional_function.h \
    ccell.h \
    cgamefield.h \
    mainwindow.h

FORMS += \
    mainwindow.ui
