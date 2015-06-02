#include "hijo.h"
#include "padre.h"

int main (int argc, char **argv){

	int tuberia_padre_escribe_hijo_lee[2]; // [0] --> read   [1] --> write
	int tuberia_padre_lee_hijo_escribe[2];

	if (pipe(tuberia_padre_escribe_hijo_lee) != 0){
		perror ("Error en el pipe padre escribe - hijo lee");
		return -1;
	}

	if (pipe(tuberia_padre_lee_hijo_escribe) != 0){
		perror ("Error en el pipe padre lee - hijo escribe");
	}
	
	switch(fork()){
		case -1: // error fork
			perror("Error en la creacion de fork(hijo)");
			return -1;

		case 0: // proceso hijo
						
			close(tuberia_padre_escribe_hijo_lee[1]); // cierro la tuberia para escribir
			close(tuberia_padre_lee_hijo_escribe[0]); // cierro la tuberia para leer		
//			printf("hijoo\n");
			funcionHijo(tuberia_padre_escribe_hijo_lee[0],tuberia_padre_lee_hijo_escribe[1]);
			return 2;
	

	//*************************PADRE*********************************//		
		default:	// proceso padre

			close(tuberia_padre_escribe_hijo_lee[0]); // cierro lectura
            close(tuberia_padre_lee_hijo_escribe[1]); // cierro escritura
			funcionPadre(tuberia_padre_escribe_hijo_lee[1],tuberia_padre_lee_hijo_escribe[0]);
//			printf ("hola soy el padre\n");
     

		

	} // fin switch		

return 0;
} // fin main
