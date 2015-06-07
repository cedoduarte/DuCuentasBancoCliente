TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    Cliente.c

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Cliente.h

