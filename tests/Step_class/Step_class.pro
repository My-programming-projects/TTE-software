QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_step_class.cpp \
    ../../scenario.cpp \
    ../../technique.cpp \
    ../../usecase.cpp

HEADERS += \
    ../../scenario.h \
    ../../technique.hpp \
    ../../usecase.hpp

#install
target.
