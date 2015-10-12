MAIN=tp3
OBJ =   src/hijo.o	src/padre.o     src/tp3.o src/manejoDeErrores.o  
DEPS = tp3.h   
SRC = src
HEADIR = headers
CC=gcc
CEJ = build#Carpeta en donde era el ejecutable
EN = proyecto
CFLAGS = -I$(HEADIR) -W -Wall -Werror -g -pthread
LIBS=-lm
makedirectory = mkdir -p -v
rem = rm -f


$%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

$(MAIN): $(OBJ)
	@mkdir -p $(CEJ)
	$(CC) -o ./$(CEJ)/$(EN) $^ $(CFLAGS) $(LIBS) 

	@$(rem) $(SRC)/*.o 

	@echo ----------------------------------------
	cat resources/elquijote | ./$(CEJ)/$(EN)
