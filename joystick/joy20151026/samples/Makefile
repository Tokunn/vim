SHELL = /bin/sh

TARGET = $(SAMPLES)

INC_DIR = include
LIB_DIR = lib

SRC = sample.c
OBJ = $(SRC:.c=.o)
SAMPLES = $(SRC:.c= )

CC = gcc
CFLAGS = -c -g -Wall -I$(HOME)/include
LIBS = -ljoy -L$(HOME)/lib

.c.o:
	$(CC) $(CFLAGS) $<

all:$(SAMPLES)

clean:
	rm -f $(OBJ) $(TARGET) *~ 

$(SAMPLES): $(OBJ)
	$(CC) -o $@ $@.o $(LIBS)
