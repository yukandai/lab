C = gcc
CFLAGS= -g -Wall
TARGETS= tp1
all: $(TARGETS)

# objetivo: dependencias
#	reglas ( tab )
tp1: main.c filtrarPalabra.c salida.c ayuda.c mensajeFiltrado.c
	$(CC) $(CFLAGS) -o $@ $^

test: tp1
	#ls *.txt | ./tp1
	#cat salida.txt

clean:
	rm -fv $(TARGETS) *.o *.*~ mensaje-filtrado.txt 
