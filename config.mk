PROJECT = bowser

OBJDIR = obj
SRCDIR = src

MOC_H_FILES   := $(shell ag -l Q_OBJECT src | tr "\n" " ")
MOC_SRC_FILES := $(MOC_H_FILES:.hh=.moc.cc)
MOC_OBJ_FILES := $(patsubst src/browser/%.moc.cc,obj/%.moc.o,${MOC_SRC_FILES})

BROWSER_SRC_FILES := $(wildcard src/browser/*.cc)
BROWSER_OBJ_FILES := $(patsubst src/browser/%.cc,obj/%.o,${BROWSER_SRC_FILES})

BASE_SRC_FILES := $(wildcard src/*.cc)
BASE_OBJ_FILES := $(patsubst src/%.cc,obj/%.o,${BASE_SRC_FILES})

H_FILES := $(shell find $(SRCDIR) -name '*.hh')
SRC_FILES := $(shell find $(SRCDIR) -name '*.cc')
OBJ_FILES := ${BROWSER_OBJ_FILES} ${BASE_OBJ_FILES} ${MOC_OBJ_FILES}
DEPS = $(OBJ_FILES:%.o=%.d)

BIN = bin/$(PROJECT)
INSTALL = /usr/local/bin/
TARGET ?= $(BIN)

DEPS = Qt5{Widgets,WebEngineWidgets,Gui,Core,WebEngine}
CXXFLAGS ?= -std=c++17 -fPIC
CXXFLAGS += `pkg-config --cflags ${DEPS}`

LDFLAGS += `pkg-config --libs ${DEPS}`

DEBUG_FLAGS = -Wall -g -DDEBUG

CC = g++
