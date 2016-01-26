#Makefile
#This file is part of countit
#Stelmach Ro <stelmach.ro@gmail.com>

TARGET = countit
CC = g++
CFLAGS = -g -Wall -std=c++11

.PHONY: default all clean

default: $(TARGET)
all:default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS = $(wildcard *.h)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
