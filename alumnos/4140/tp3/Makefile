# Makefile tp3

CFLAGS=-Wall
LDLIBS=-pthread

tp3: main.c funciones.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)
clean:
	rm tp3 *.o
