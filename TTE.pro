QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    editor.cpp \
    main.cpp \
    precondition.cpp \
    preconditionseditor.cpp \
    scenario.cpp \
    scenarioeditor.cpp \
    step.cpp \
    technique.cpp \
    tte_app.cpp \
    usecase.cpp \
    usecaseeditor.cpp

HEADERS += \
    editor.h \
    precondition.hpp \
    preconditionseditor.hpp \
    scenario.h \
    scenarioeditor.h \
    step.hpp \
    technique.hpp \
    tte_app.h \
    usecase.hpp \
    usecaseeditor.h

FORMS += \
    editor.ui \
    precondition.ui \
    preconditionseditor.ui \
    scenarioeditor.ui \
    step.ui \
    tte_app.ui \
    usecaseeditor.ui

TRANSLATIONS += \
    TTE_en_150.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
