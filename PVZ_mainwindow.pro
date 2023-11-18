QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    basiczombie.cpp \
    card.cpp \
    cherrybomb.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    mower.cpp \
    mypushbutton.cpp \
    other.cpp \
    pea.cpp \
    plant.cpp \
    peashooter.cpp \
    playscene.cpp \
    potatomine.cpp \
    repeater.cpp \
    shop.cpp \
    shovel.cpp \
    snowpea.cpp \
    sun.cpp \
    sunflower.cpp \
    wallnut.cpp \
    zombie.cpp

HEADERS += \
    Init.h \
    basiczombie.h \
    card.h \
    cherrybomb.h \
    mainwindow.h \
    map.h \
    mower.h \
    mypushbutton.h \
    other.h \
    pea.h \
    plant.h \
    peashooter.h \
    playscene.h \
    potatomine.h \
    repeater.h \
    shop.h \
    shovel.h \
    snowpea.h \
    sun.h \
    sunflower.h \
    wallnut.h \
    zombie.h

FORMS += \
    mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resphoto.qrc
