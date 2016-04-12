CC=gcc
CFLAGS=-g #-Wall
#LDFLAGS=-lpthread -lrt
TARGETS=tp4
FILES=main.c http_worker.c  
DEP= http_worker.h

all: $(TARGETS)

tp4: $(FILES) $(DEP)
	$(CC) $(CFLAGS) $(FILES) -o $@ 
clean:
	rm -f $(TARGETS) *~ core*

