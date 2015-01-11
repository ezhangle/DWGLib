TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
QMAKE_CXXFLAGS += -Wall -Wextra
SOURCES += \
    src/main.cpp \
    src/dwgparser.cpp \
    src/dwgentities.cpp \
    src/dwgreader.cpp

HEADERS += \
    src/dwgparser.h \
    src/dwgheader.h \
    src/dwgentities.h \
    src/dwgreader.h

