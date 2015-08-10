#CC		= gcc
CC		= clang
CCFLAGS	= -Wall -Wextra -O2 -g
SOURCES:= $(wildcard *.c)
TARGET	= $(SOURCES:.c=.bin)

all: $(TARGET)

%.bin:%.c
	$(CC) -I./ $(CCFLAGS) $< -o $@

clean:
	$(RM) -r *.bin
