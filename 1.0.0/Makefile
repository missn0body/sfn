# Simply replace CC with your own compiler
# if it doesn't match the one listed below.
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Os -g

sfn.o: sfn.c
        $(CC) -c $^ -o $@ $(CFLAGS)

sfn: sfn.o
        $(CC) $^ -o $@ $(CFLAGS)

.PHONY: all clean

all: sfn

clean:
        rm -f *.o sfn
