CFLAGS= -pthread -g -Wall
CC:=gcc
TARGETS= tp3

all: clean $(TARGETS)
tp3: main.c hijo.c srch.c
	$(CC) $(CFLAGS) -o $@ $^

.PHONY:test
test:	
	cat mensaje.txt | ./tp3 -p hola,como,con

.PHONY: clean
clean:
	rm -f *.o *~ $(TARGETS)
