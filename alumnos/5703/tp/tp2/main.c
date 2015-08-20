#include "main.h"

int main (int argc, char *argv[]) {
	int pah[2], hap[2];

	if( (pipe(pah) < 0) | (pipe(hap) < 0) ){
		perror("pipe(): ");
		return 1;
	} 

    switch (fork()) {
	    case 0: //el hijo lee y espera señal a ver que hace...
	    	funcionHijo(argc,argv,pah,hap);
	        break;

	    case -1: // error
	        perror("fork(): ");
	        return 1;

	    default: //el padre lee, lo escribe un pipe y se queda esperando...
	        padreEmpieza(pah, hap);
	        break;
    }
    return 0;
} 