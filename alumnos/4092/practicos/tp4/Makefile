CC=gcc
CFLAGS=-g -Wall
TARGETS=tp4
LDLIBS=-pthread

all: $(TARGETS)

tp4: main.c http_worker.c datosDireccion.c
	$(CC) $(CFLAGS) $(LDLIBS) -o $@ $^

