QT       += core gui
QT       += serialport
QT       += charts
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ch4_chart.cpp \
    ch4_serial.cpp \
    configuration.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    savethread.cpp

HEADERS += \
    ch4_chart.h \
    ch4_serial.h \
    configuration.h \
    mainwindow.h \
    qcustomplot.h \
    savethread.h

FORMS += \
    configuration.ui \
    mainwindow.ui

TRANSLATIONS += \
    CH4_collecter_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target




#=================================
INCLUDEPATH += D:/matlab2019/extern/include
INCLUDEPATH += D:/matlab2019/extern/include/win64

win32: LIBS += -L'D:/matlab2019/extern/lib/win64/mingw64/' -llibmex
win32: LIBS += -L'D:/matlab2019/extern/lib/win64/mingw64/' -llibmx
win32: LIBS += -L'D:/matlab2019/extern/lib/win64/mingw64/' -llibmat
win32: LIBS += -L'D:/matlab2019/extern/lib/win64/mingw64/' -llibeng
win32: LIBS += -L'D:/matlab2019/extern/lib/win64/mingw64/' -lmclmcr
win32: LIBS += -L'D:/matlab2019/extern/lib/win64/mingw64/' -lmclmcrrt


INCLUDEPATH += D:/matlab2019/extern/lib/win64/mingw64
DEPENDPATH += D:/matlab2019/extern/lib/win64/mingw64

INCLUDEPATH += D:/matlab2019/extern/lib/win64
DEPENDPATH += D:/matlab2019/extern/lib/win64



RESOURCES += \
    image.qrc

DISTFILES += \
    cof/configuration.txt \
    release/configuration.txt

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/include/ -lenvelope
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/include/ -lenveloped

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/include/ -lsmoothdata
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/include/ -lsmoothdatad

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/include/ -lsgolayfilt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/include/ -lsgolayfiltd

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
