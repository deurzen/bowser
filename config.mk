PROJECT = bowser

OBJDIR = obj
SRCDIR = src

BASE_SRC_FILES := $(wildcard src/*.cc)
BASE_OBJ_FILES := $(patsubst src/%.cc,obj/%.o,${BASE_SRC_FILES})

H_FILES := $(shell find $(SRCDIR) -name '*.hh')
SRC_FILES := $(shell find $(SRCDIR) -name '*.cc')
OBJ_FILES := ${BASE_OBJ_FILES}
DEPS = $(OBJ_FILES:%.o=%.d)

BIN = bin/$(PROJECT)
INSTALL = /usr/local/bin/
TARGET ?= $(BIN)

CXXFLAGS ?= -std=c++17 -fPIC
CXXFLAGS += `pkg-config --cflags Qt5Widgets`

LDFLAGS += `pkg-config --libs Qt5Widgets`

DEBUG_FLAGS = -Wall -g -DDEBUG

CC = g++
