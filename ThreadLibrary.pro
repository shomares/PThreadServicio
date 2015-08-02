TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    runnable.cpp \
    funciones.cpp \
    threadpoolexecutor.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    threadpoolexecutor.h \
    runnable.h \
    funciones.h \
    threadexception.h

QMAKE_CXXFLAGS += -std=c++0x -pthread
LIBS += -pthread
