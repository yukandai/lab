CC = gcc 
CFLAGS= -g -Wall
TARGETS = tp5
all: $(TARGETS)

# objetivo: dependencias
#	reglas ( tab )

tp5: main.c ruta.c http_worker.c create_socket.c
	$(CC) $(CFLAGS) -o $@ $^ -pthread


test: tp5
#	ls *.txt | ./tp2
	#cat salida.txt

clean:
	rm -fv $(TARGETS) *.o  
