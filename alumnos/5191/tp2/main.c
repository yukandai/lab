#include "hijo.h"
#include "padre.h"
#include "palabras.h"
int main (int argc, char **argv){

	int tuberia_padre_hijo[2]; // pipe1 -- [0] --> read   [1] --> write
	int tuberia_hijo_padre[2]; // pipe2

	int opcion;
	char *palabras = NULL;

	while ((opcion = getopt (argc,argv, "p:")) != -1){
		switch (opcion){
			case 'p':
				obtenerPalabras(&palabras);
				break;

		}


	}


	if (pipe(tuberia_padre_hijo) != 0){
		perror ("Error en el pipe padre - hijo");
		return -1;
	}

	if (pipe(tuberia_hijo_padre) != 0){
		perror ("Error en el pipe hijo - padre");
		return -1;
	}
/*	if (pipe(tuberia_nieto_hijo) != 0){
		perror ("Error en el pipe nieto - hijo");
		return -1;
	}*/
	
	switch(fork()){
		case -1: // error fork
			perror("Error en la creacion de fork(hijo)");
			return -1;

		case 0: // proceso hijo
						
			close(tuberia_padre_hijo[1]); // cierro escritura
			close(tuberia_hijo_padre[0]); // cierro lectura		
//			printf("hijoo\n");
			funcionHijo(tuberia_padre_hijo[0],tuberia_hijo_padre[1],palabras);
			return 2;
	

	//*************************PADRE*********************************//		
		default:	// proceso padre

			close(tuberia_padre_hijo[0]); // cierro lectura
            close(tuberia_hijo_padre[1]); // cierro escritura
			funcionPadre(tuberia_padre_hijo[1],tuberia_hijo_padre[0]);
//			printf ("hola soy el padre\n");
     

		

	} // fin switch		

return 0;
} // fin main
