INCLUDE_PATH=./include
CC=gcc
CFLAGS=-I$(INCLUDE_PATH)  -c
TARGET=THREADCOPY
SFILE=$(wildcard *.c)
DFILE=$(patsubst %.c,%.o,$(SFILE))

$(TARGET):$(DFILE)
	$(CC) $^ -lpthread -o $@
%.o:%.c
	$(CC) $(CFLAGS) $<

clean:
	rm *.o
