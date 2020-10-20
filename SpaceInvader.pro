#-------------------------------------------------
#
# Project created by QtCreator 2020-01-22T15:33:31
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpaceInvader
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
CONFIG += resources_big

SOURCES += \
        bullet.cpp \
        cruiser.cpp \
        enemy.cpp \
        enemybullet.cpp \
        explosion.cpp \
        fighter.cpp \
        game.cpp \
        gamegui.cpp \
        graphicobject.cpp \
        health.cpp \
        main.cpp \
        myeventfilter.cpp \
        object.cpp \
        score.cpp \
        ship.cpp

HEADERS += \
        bullet.h \
        cruiser.h \
        enemy.h \
        enemybullet.h \
        explosion.h \
        fighter.h \
        game.h \
        gamegui.h \
        graphicobject.h \
        health.h \
        myeventfilter.h \
        object.h \
        score.h \
        ship.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
