QT -= gui
QT += websockets

CONFIG += c++14 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    Models/Abstracts/acounter.cpp \
    Models/Classes/counter.cpp \
    Models/Abstracts/atimer.cpp \
    Models/Classes/timer.cpp \
    Models/Abstracts/areversetimer.cpp \
    Models/Classes/reversetimer.cpp \
    Models/Abstracts/ateam.cpp \
    Models/Classes/team.cpp \
    Exceptions/counterkeyerror.cpp \
    Models/Abstracts/agame.cpp \
    Models/Classes/game.cpp \
    Exceptions/teamkeyerror.cpp \
    Exceptions/clockkeyerror.cpp \
    Server/wsserver.cpp \
    Parser/commandparser.cpp \
    Parser/Commands/Abstract/acommand.cpp \
    Parser/Commands/Classes/clockresetcommand.cpp

HEADERS += \
    Models/Abstracts/acounter.h \
    Models/Classes/counter.h \
    Models/Abstracts/atimer.h \
    Models/Classes/timer.h \
    Models/Abstracts/areversetimer.h \
    Models/Classes/reversetimer.h \
    Models/Abstracts/ateam.h \
    Models/Classes/team.h \
    Exceptions/counterkeyerror.h \
    Models/Abstracts/agame.h \
    Models/Classes/game.h \
    Exceptions/teamkeyerror.h \
    Exceptions/clockkeyerror.h \
    Server/wsserver.h \
    Parser/commandparser.h \
    Parser/Commands/Abstract/acommand.h \
    Parser/Commands/Classes/clockresetcommand.h
