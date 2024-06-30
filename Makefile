CPP=g++
SRC=$(shell find -name "*.cpp")
CPPFLAGS=-lX11 -lGL -lglfw -lGLEW
BIN=maroi

all: compile run

compile:
	${CPP} -o ${BIN} ${SRC} ${CPPFLAGS}

run:
	./${BIN}
