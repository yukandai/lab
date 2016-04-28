# Computación II:
# TP1:
# Realizar un aplicación que sirva para unir partes de archivos en un solo archivo,
# y otra para dividir un archivo en una cantidad de partes iguales excepto la última.
# MODO DE USO:
# ls part-* | ./pegar [archivo_salida]
# ./hachar [archivo_entrada]

CC=gcc
CFLAGS=-g -Wall

pegar: pegar.c funciones.c
	$(CC) $(CFLAGS) -o $@ $^

hachar: hachar.c funciones.c
	$(CC) $(CFLAGS) -o $@ $^
