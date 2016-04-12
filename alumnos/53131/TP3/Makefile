CC=gcc
CFLAGS=-g #-Wall
LDFLAGS=-lpthread -lrt
TARGETS=tp3
FILES=main.c hijo.c parser.c crear_arch.c 
DEP= hijo.h parser.h otras.h

all: $(TARGETS)

tp3: $(FILES) $(DEP)
	$(CC) $(CFLAGS) $(FILES) -o $@ $(LDFLAGS)
clean:
	rm -f $(TARGETS) *~ core*

