QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    coderdynamichuffman.cpp \
    coderstatichaffman.cpp \
    coderwindow.cpp \
    decoderdynamichuffman.cpp \
    decoderstatichuffman.cpp \
    decoderwindow.cpp \
    generator.cpp \
    main.cpp \
    mainwindow.cpp \
    printer.cpp \
    qcustomplot.cpp \
    statistics.cpp \
    stringgeneratorwindow.cpp \
    tester.cpp

HEADERS += \
    BinaryTree.h \
    File.h \
    ICoder.h \
    IDecoder.h \
    coderdynamichuffman.h \
    coderstatichaffman.h \
    coderwindow.h \
    decoderdynamichuffman.h \
    decoderstatichuffman.h \
    decoderwindow.h \
    generator.h \
    mainwindow.h \
    printer.h \
    qcustomplot.h \
    statistics.h \
    stringgeneratorwindow.h \
    tester.h

FORMS += \
    coderwindow.ui \
    decoderwindow.ui \
    mainwindow.ui \
    statistics.ui \
    stringgeneratorwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    coderdh \
    codersh \
    decoderch \
    decodersh
