PROJECT = bowser

OBJDIR = obj
SRCDIR = src

MOC_H_FILES   := $(shell ag -l Q_OBJECT src | tr "\n" " ")
MOC_BASENAMES := $(shell echo ${MOC_H_FILES} | xargs -n 1 basename)
MOC_SRC_FILES := $(MOC_BASENAMES:.hh=.moc.cc)
MOC_OBJ_FILES := $(patsubst %.moc.cc,obj/%.moc.o,${MOC_SRC_FILES})

BROWSER_SRC_FILES := $(wildcard src/browser/*.cc)
BROWSER_OBJ_FILES := $(patsubst src/browser/%.cc,obj/%.o,${BROWSER_SRC_FILES})

STATUSBAR_SRC_FILES := $(shell find src/browser/statusbar -name "*.cc")
STATUSBAR_OBJ_FILES := $(patsubst src/browser/statusbar/%.cc,obj/%.o,${STATUSBAR_SRC_FILES})

TABBAR_SRC_FILES := $(shell find src/browser/tabbar -name "*.cc")
TABBAR_OBJ_FILES := $(patsubst src/browser/tabbar/%.cc,obj/%.o,${TABBAR_SRC_FILES})

BASE_SRC_FILES := $(wildcard src/*.cc)
BASE_OBJ_FILES := $(patsubst src/%.cc,obj/%.o,${BASE_SRC_FILES})

H_FILES := $(shell find $(SRCDIR) -name '*.hh')
SRC_FILES := $(shell find $(SRCDIR) -name '*.cc')
OBJ_FILES := ${STATUSBAR_OBJ_FILES} ${TABBAR_OBJ_FILES} ${BROWSER_OBJ_FILES} ${BASE_OBJ_FILES} ${MOC_OBJ_FILES}
DEPS = $(OBJ_FILES:%.o=%.d)

BIN = bin/$(PROJECT)
INSTALL = /usr/local/bin/
TARGET ?= $(BIN)

PKGDEPS = Qt5{Widgets,WebEngineWidgets,Core,WebEngine}
CXXFLAGS ?= -std=c++17 -fPIC
CXXFLAGS += `pkg-config --cflags ${PKGDEPS}`

LDFLAGS += `pkg-config --libs ${PKGDEPS}`

DEBUG_FLAGS = -Wall -g -DDEBUG

CC = g++
