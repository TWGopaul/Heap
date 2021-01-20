# Programmer: Travis Gopaul
# Date: 11/23/20
# makefile for Heap lab 8
# CC is variable for compiler name
# CFlags will be the option to pass

CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=lab8.cpp Heap.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab8
all:$(SOURCES) $(EXECUTABLE)
$(EXECUTABLE):$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
