CC=gcc
CFLAGS=-g #-Wall
#LDFLAGS=-lpthread -lrt
TARGETS=tp4
FILES=main.c http_worker.c etc.c parse_and_frac.c mensajes.c ext_arch.c
DE= http_worker.h etc.h

all: $(TARGETS)

tp4: $(FILES) $(DEP)
	$(CC) $(CFLAGS) $(FILES) -o $@ 
clean:
	rm -f $(TARGETS) *~ core*

