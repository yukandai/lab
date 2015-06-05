CC = gcc
CFLAGS= -g -Wall
TARGETS = tp2
all: $(TARGETS)

# objetivo: dependencias
#	reglas ( tab )
tp2: main.c padre.c hijo.c rot13.c nieto.c sigusr.c
	$(CC) $(CFLAGS) -o $@ $^

test: tp2
	ls -l | ./tp2

test2: tp2
	ls -l | ./tp2 -p hola,mono,meme

test3: tp2
	cat mensaje.txt | ./tp2 -p hola,mono,meme	

clean:
	rm -fv $(TARGETS) *.o *~
