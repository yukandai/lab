#!/bin/bash

#----------------------------------------------------------
#inicio zona de edicion para un proyecto en particular

#aprende a trabajar en esta pagina: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
#el flag -g en gcc para linkeo estatico, si no lo hago valgrind no me muestra la linea en la que se produjo un error

MAIN=tp3#nombre del archivo donde se encuentra el main sin el .c
OBJ =   src/hijo.o	src/padre.o     src/tp3.o src/manejoDeErrores.o  #al ponerle .o el compilador crea los .o por separado antes de armar el compilable, no se que ventaja tiene
DEPS = tp3.h   #dependencia..no entiendo que quiere decir, creo que algo sobre una edicion sincronizada o algo asi
SRC = src
HEADIR = headers
#ajustar los parametros de testing
P1 = uno
P2 = dos
P3 = tres
P4 = cuatro
P5 = cinco
P6 = seis
P7 = 
P8 = 
P9 = 
#fin zona de edicion para un proyecto en particular
#----------------------------------------------------------


#----------------------------------------------------------
#inicio zona de edicion para los proyectos en general

CC=gcc#compilador
CEJ = build#Carpeta en donde era el ejecutable
EN = proyecto#Nombre del archivo ejecutable que va a generar este script
CFLAGS = -I$(HEADIR) -W -Wall -Werror -g -pthread#flags: Se copia como un texto plano sobre el comando
LIBS=-lm #tiene que ver con linqueo de librerias, pero no lo entiendo muy bien
makedirectory = mkdir -p -v
rem = rm -f

#inicio zona de edicion para los proyectos en general
#----------------------------------------------------------

#no se que hace esto, pat subst quiere decir patern substitution

#codigo para la ejecucion de los comandos de gcc
#compilador
$%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 
#"$@" es la parte a la izquierda de los ":" en la linea justo arriba

#linker
$(MAIN): $(OBJ)
	@mkdir -p $(CEJ)
	$(CC) -o ./$(CEJ)/$(EN) $^ $(CFLAGS) $(LIBS) 

#"$^" es la parte a la derecha de los ":" en la linea justo arriba


#borra los .o que son muy molestos solo en el caso que ingrese el comando "make" con el parametro "clean". Si no, no se ejecuta la sentencia de borrado
	@$(rem) $(SRC)/*.o 
#compila con los parametros de dados despues de echo
	@echo ----------------------------------------
	#./$(CEJ)/$(EN) $(P1) $(P2) $(P3) $(P4) $(P5) $(P6) $(P7) $(P8) $(P9)
	cat resources/elquijote | valgrind --track-origins=yes --leak-check=full ./$(CEJ)/$(EN) $(P1) $(P2) $(P3) $(P4) $(P5) $(P6) $(P7) $(P8) $(P9)
#Tareas
#buscar la opcion para compilar el archivo de forma dinamica o estatica y asi poder trabajar mejor en valgrind
#seguir estudiande este link para hacer el makefile 5: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
