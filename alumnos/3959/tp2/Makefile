CFLAGS= -g -Wall
TARGETS=tp2
CC=gcc

all: clean $(TARGETS)

tp2: main.c hijo.c nieto.c srch.c 
	$(CC) $(CFLAGS) -o $@ $^

.PHONY:test
test: $(TARGETS) 
	ls -l | ./tp2

.PHONY:test2
test2:	$(TARGETS)
	ls -l | ./tp2 -p hola,mono,meme

.PHONY:test3
test3:	$(TARGETS)
	cat mensaje.txt | ./tp2 -p hola,mono,meme

.PHONY: clean
clean:
	rm -f *.o *~ $(TARGETS) 
