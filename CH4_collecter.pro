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
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    savethread.cpp

HEADERS += \
    ch4_chart.h \
    ch4_serial.h \
    mainwindow.h \
    qcustomplot.h \
    savethread.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    CH4_collecter_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/include/ -lsmoothdata
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/include/ -lsmoothdatad

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
#=================================
INCLUDEPATH += D:/matlab2019/extern/include
INCLUDEPATH += D:/matlab2019/extern/include/win64

win32: LIBS += -L'D:/matlab2019/extern/lib/win64/mingw64/' -llibmex
win32: LIBS += -L'D:/matlab2019/extern/lib/win64/mingw64/' -llibmx
win32: LIBS += -L'D:/matlab2019/extern/lib/win64/mingw64/' -llibmat
win32: LIBS += -L'D:/matlab2019/extern/lib/win64/mingw64/' -llibeng
win32: LIBS += -L'D:/matlab2019/extern/lib/win64/mingw64/' -lmclmcr
win32: LIBS += -L'D:/matlab2019/extern/lib/win64/mingw64/' -lmclmcrrt

#INCLUDEPATH += 'D:/Program Files/MATLAB/R2018b/extern/lib/win64/microsoft'
#DEPENDPATH += 'D:/Program Files/MATLAB/R2018b/extern/lib/win64/microsoft'
#INCLUDEPATH += 'D:/Program Files/MATLAB/R2018b/extern/lib/win64'
#DEPENDPATH += 'D:/Program Files/MATLAB/R2018b/extern/lib/win64'

#win32:CONFIG(release, debug|release): LIBS += -LD:/matlab2019/extern/lib/win64/mingw64/ -llibmex
#else:win32:CONFIG(debug, debug|release): LIBS += -LD:/matlab2019/extern/lib/win64/mingw64/ -llibmexd



#win32:CONFIG(release, debug|release): LIBS += -LD:/matlab2019/extern/lib/win64/mingw64/ -llibmx
#else:win32:CONFIG(debug, debug|release): LIBS += -LD:/matlab2019/extern/lib/win64/mingw64/ -llibmxd



#win32:CONFIG(release, debug|release): LIBS += -LD:/matlab2019/extern/lib/win64/mingw64/ -llibmat
#else:win32:CONFIG(debug, debug|release): LIBS += -LD:/matlab2019/extern/lib/win64/mingw64/ -llibmatd


#win32:CONFIG(release, debug|release): LIBS += -LD:/matlab2019/extern/lib/win64/mingw64/ -llibeng
#else:win32:CONFIG(debug, debug|release): LIBS += -LD:/matlab2019/extern/lib/win64/mingw64/ -llibengd


#win32:CONFIG(release, debug|release): LIBS += -LD:/matlab2019/extern/lib/win64/mingw64/ -lmclmcr
#else:win32:CONFIG(debug, debug|release): LIBS += -LD:/matlab2019/extern/lib/win64/mingw64/ -lmclmcrd


#win32:CONFIG(release, debug|release): LIBS += -LD:/matlab2019/extern/lib/win64/mingw64/ -lmclmcrrt
#else:win32:CONFIG(debug, debug|release): LIBS += -LD:/matlab2019/extern/lib/win64/mingw64/ -lmclmcrrtd

INCLUDEPATH += D:/matlab2019/extern/lib/win64/mingw64
DEPENDPATH += D:/matlab2019/extern/lib/win64/mingw64

INCLUDEPATH += D:/matlab2019/extern/lib/win64
DEPENDPATH += D:/matlab2019/extern/lib/win64
