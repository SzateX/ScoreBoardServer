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
    Parser/Commands/Classes/clockresetcommand.cpp \
    Parser/Commands/Classes/clocksetsecondscommand.cpp \
    Parser/Commands/Classes/clockstartcommand.cpp \
    Parser/Commands/Classes/clockstopcommand.cpp \
    Parser/Commands/Classes/periodsetcommand.cpp \
    Parser/Commands/Classes/pointsaddcommand.cpp \
    Parser/Commands/Classes/pointsresetcommand.cpp \
    Parser/Commands/Classes/pointssetcommand.cpp \
    Parser/Commands/Classes/pointssubtractcommand.cpp \
    Parser/Commands/Classes/setnamecommand.cpp \
    Parser/Commands/Classes/setpenaltyflagcommand.cpp \
    Parser/Commands/Classes/settimeoutflagcommand.cpp \
    Parser/Commands/Classes/switchpenaltyflagcommand.cpp \
    Parser/Commands/Classes/switchtimeoutflagcommand.cpp \
    Parser/acommandfactory.cpp \
    Parser/commandfactory.cpp \

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
    Parser/Commands/Classes/clockresetcommand.h \
    Parser/Commands/Classes/clocksetsecondscommand.h \
    Parser/Commands/Classes/clockstartcommand.h \
    Parser/Commands/Classes/clockstopcommand.h \
    Parser/Commands/Classes/periodsetcommand.h \
    Parser/Commands/Classes/pointsaddcommand.h \
    Parser/Commands/Classes/pointsresetcommand.h \
    Parser/Commands/Classes/pointssetcommand.h \
    Parser/Commands/Classes/pointssubtractcommand.h \
    Parser/Commands/Classes/setnamecommand.h \
    Parser/Commands/Classes/setpenaltyflagcommand.h \
    Parser/Commands/Classes/settimeoutflagcommand.h \
    Parser/Commands/Classes/switchpenaltyflagcommand.h \
    Parser/Commands/Classes/switchtimeoutflagcommand.h \
    Parser/acommandfactory.h \
    Parser/commandfactory.h \
    rapidjson/error/en.h \
    rapidjson/error/error.h \
    rapidjson/internal/biginteger.h \
    rapidjson/internal/diyfp.h \
    rapidjson/internal/dtoa.h \
    rapidjson/internal/ieee754.h \
    rapidjson/internal/itoa.h \
    rapidjson/internal/meta.h \
    rapidjson/internal/pow10.h \
    rapidjson/internal/regex.h \
    rapidjson/internal/stack.h \
    rapidjson/internal/strfunc.h \
    rapidjson/internal/strtod.h \
    rapidjson/internal/swap.h \
    rapidjson/msinttypes/inttypes.h \
    rapidjson/msinttypes/stdint.h \
    rapidjson/allocators.h \
    rapidjson/cursorstreamwrapper.h \
    rapidjson/document.h \
    rapidjson/encodedstream.h \
    rapidjson/encodings.h \
    rapidjson/filereadstream.h \
    rapidjson/filewritestream.h \
    rapidjson/fwd.h \
    rapidjson/istreamwrapper.h \
    rapidjson/memorybuffer.h \
    rapidjson/memorystream.h \
    rapidjson/ostreamwrapper.h \
    rapidjson/pointer.h \
    rapidjson/prettywriter.h \
    rapidjson/rapidjson.h \
    rapidjson/reader.h \
    rapidjson/schema.h \
    rapidjson/stream.h \
    rapidjson/stringbuffer.h \
    rapidjson/writer.h \

RESOURCES += \
    schemaresources.qrc
