QT += core gui qml quick quickcontrols2

CONFIG += c++17 release
TARGET = pomopixel
TEMPLATE = app

HEADERS += \
    src/backend.h \
    src/configmanager.h \
    src/theme.h

SOURCES += \
    src/backend.cpp \
    src/configmanager.cpp \
    src/main.cpp \
    src/theme.cpp

RESOURCES += src/resources.qrc
