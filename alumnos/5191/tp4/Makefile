CC = gcc 
CFLAGS= -g -Wall
TARGETS = tp4
all: $(TARGETS)

# objetivo: dependencias
#	reglas ( tab )

tp4: main.c ruta.c http_worker.c URI.c
	$(CC) $(CFLAGS) -o $@ $^


test: tp4
#	ls *.txt | ./tp2
	#cat salida.txt

clean:
	rm -fv $(TARGETS) *.o  
