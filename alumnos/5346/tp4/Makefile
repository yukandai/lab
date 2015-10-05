CC = gcc
CFLAGS = -g -Wall 
TARGETS = tp4
LDLIBS=-pthread

# el $@ reemplaza todos los objetivos y el $^ reemplaza todas las dependencias
#objetivo: dependencias
#       reglas

all: $(TARGETS)

#tp4: server.c respuesta.h respuesta.c lector.h lector.c ContentT.c
tp4: main.c http_worker.c hijo.c extencion.c 
	$(CC) $(CFLAGS) -o $@ $^
