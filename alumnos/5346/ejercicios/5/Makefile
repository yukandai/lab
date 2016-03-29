CC=gcc
CFLAGS=-Wall
TARGETS=clases
LDLIBS=-pthread

# el $@ reemplaza todos los objetivos y el $^ reemplaza todas las dependencias
#objetivo: dependencias
#       reglas

all: $(TARGETS)

clases: main.c
	 $(CC) $(CFLAGS) $(LDLIBS) -o  $@ $^

test: clases
	./clases -o salida.txt
#	cat news-* |./clases -o salida.txt
clean:
	 rm -fv $(TARGETS) *.txt *~ 