CFLAGS= -g -Wall
TARGETS=tp1
CC=gcc

all: clean $(TARGETS)

$(TARGETS): $(TARGETS).o srch.o
	$(CC) $(CFLAGS) -o $@ $^
.PHONY:test
test: $(TARGETS) 
	cat mensaje.txt |./tp1

.PHONY:test2
test2:	$(TARGETS)
	cat mensaje.txt |./tp1 -o msj-filtrado.txt

.PHONY: clean
clean:
	rm -f bin *.o *~ $(TARGETS) msj-filtrado.txt
