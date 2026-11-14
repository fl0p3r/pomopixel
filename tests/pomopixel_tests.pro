QT += core gui qml quick testlib

CONFIG += c++17 testcase
TARGET = pomopixel_tests
TEMPLATE = app

INCLUDEPATH += ../src

HEADERS += \
    ../src/backend.h \
    ../src/configmanager.h \
    ../src/theme.h

SOURCES += \
    pomopixel_tests.cpp \
    ../src/backend.cpp \
    ../src/configmanager.cpp \
    ../src/theme.cpp

RESOURCES += ../src/resources.qrc
