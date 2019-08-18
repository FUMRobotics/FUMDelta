#-------------------------------------------------
#
# Project created by QtCreator 2019-07-22T14:31:47
#
#-------------------------------------------------

QT       += core gui
QT += testlib
QT += concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


TARGET = DeltaPlotter-01
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    qcustomplot.cpp \
    receiver.cpp \
    plothandler.cpp \
    sendcommand.cpp \
    trajectorysender.cpp \
    dialog_loadpoints.cpp \
    inversekinematicscore.cpp \
    sevensegment.cpp \
    dialog_take_drives_home.cpp \
    kinematicsexception.cpp \
    test/test.cpp

HEADERS += \
        mainwindow.h \
    qcustomplot.h \
    receiver.h \
    plothandler.h \
    sendcommand.h \
    trajectorysender.h \
    dialog_loadpoints.h \
    inversekinematicscore.h \
    sevensegment.h \
    kinematicsexception.h\
    dialog_take_drives_home.h

FORMS += \
        mainwindow.ui \
    dialog_loadpoints.ui \
    dialog_take_drives_home.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES +=

INCLUDEPATH +=/home/fumdelta/Documents/eigen-eigen-323c052e1731/
