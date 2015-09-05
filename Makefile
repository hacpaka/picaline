.PHONY: all clean

CC = gcc
CFLAGS = -g
CFLAGS += -Wall
EXECUTABLE = picaline

SOURCES=$(wildcard src/*.c)

all: $(SOURCES)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(SOURCES)

clean:
	rm -rf *.o picaline

