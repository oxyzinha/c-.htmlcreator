QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = layoutmaker
TEMPLATE = app

SOURCES += \
    main.cpp \
    layoutmaker.cpp \
    mainmenu.cpp

HEADERS += \
    layoutmaker.h \
    mainmenu.h

FORMS += \
    mainmenu.ui
