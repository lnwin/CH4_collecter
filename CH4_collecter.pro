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
    include/blas.h \
    include/blascompat32.h \
    include/covrt.h \
    include/cvstCG_ComputeMetric.h \
    include/cvstCG_acfObjectDetector.h \
    include/cvstCG_disparitySGM.h \
    include/cvstCG_foregroundDetector.h \
    include/cvstCG_kdtree.h \
    include/cvstCG_ocrutils.h \
    include/cvstCG_searchOrganizedPointCloud.h \
    include/cvstCG_voxelGridFilter.h \
    include/emlrt.h \
    include/engine.h \
    include/fintrf.h \
    include/io64.h \
    include/lapack.h \
    include/lapacke.h \
    include/lapacke_config.h \
    include/libmwboxfilter.h \
    include/libmwboxfilter3.h \
    include/libmwbwdistEDT.h \
    include/libmwbwdistEDTFT.h \
    include/libmwbwdistEDTFT_tbb.h \
    include/libmwbwdistEDT_tbb.h \
    include/libmwbwlookup.h \
    include/libmwbwlookup_tbb.h \
    include/libmwbwpackc.h \
    include/libmwbwpackctbb.h \
    include/libmwbwunpackc.h \
    include/libmwbwunpackctbb.h \
    include/libmwcannythresholding_tbb.h \
    include/libmwddist.h \
    include/libmwedgesobelprewitt_tbb.h \
    include/libmwedgethinning_tbb.h \
    include/libmwgetnumcores.h \
    include/libmwgrayto16.h \
    include/libmwgrayto8.h \
    include/libmwgrayxform.h \
    include/libmwgrayxform_tbb.h \
    include/libmwimfilter.h \
    include/libmwimlincomb.h \
    include/libmwimlincomb_tbb.h \
    include/libmwimreconstruct.h \
    include/libmwimregionalmax.h \
    include/libmwimterp2d.h \
    include/libmwint16touint16.h \
    include/libmwint32touint32.h \
    include/libmwint8touint8.h \
    include/libmwintlut.h \
    include/libmwintluttbb.h \
    include/libmwippfilter.h \
    include/libmwippgeotrans.h \
    include/libmwippmedianfilter.h \
    include/libmwippreconstruct.h \
    include/libmwjpegreader.h \
    include/libmwmorphop_binary.h \
    include/libmwmorphop_binary_tbb.h \
    include/libmwmorphop_flat.h \
    include/libmwmorphop_flat_tbb.h \
    include/libmwmorphop_ipp.h \
    include/libmwmorphop_nonflat.h \
    include/libmwmorphop_nonflat_tbb.h \
    include/libmwmorphop_packed.h \
    include/libmwordfilt2.h \
    include/libmwremap.h \
    include/libmwremaptbb.h \
    include/libmwrgb2gray_tbb.h \
    include/libmwrgb2hsv_tbb.h \
    include/libmwtbbhist.h \
    include/libmwuint16toint16.h \
    include/mat.h \
    include/matrix.h \
    include/mclbase.h \
    include/mclcom.h \
    include/mclcomclass.h \
    include/mclcommain.h \
    include/mclcppclass.h \
    include/mclmcr.h \
    include/mclmcrrt.h \
    include/mclxlmain.h \
    include/mcr.h \
    include/mex.h \
    include/mwmathutil.h \
    include/mwservices.h \
    include/mwstringutil.h \
    include/polygonBoolean.h \
    include/smoothdata.h \
    include/tmwtypes.h \
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
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/include/ -lsmoothdata

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

DISTFILES += \
    include/smoothdata.dll \
    include/smoothdata.lib
