TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS=-O0

SOURCES += main.cpp \
    document_manager.cpp \
    passport.cpp \
    international_passport.cpp \
    studak.cpp

HEADERS += \
    base_document.hpp \
    document_manager.hpp \
    passport.hpp \
    international_passport.hpp \
    studak.hpp
