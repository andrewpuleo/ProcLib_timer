CFLAGS=-Wall -Werror -pedantic -std=gnu99
LDFLAGS=-rdynamic -lproc -lsatpkt -ldl -lm -lrt

SRC=Hello_World.c
OBJS=$(SRC:.c=.o)

EXECUTABLE=hello_world

all: $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS) $(LDFLAGS)
