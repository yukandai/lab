#include "sigusr.h"
#include "rot13.h"



char *escribirEnPadreSIGUSR1(char *palabra,int hijo_escribe_padre){
	char *cadena = NULL;

	cadena = rotate(palabra);

	cadena = strncat(cadena," ",1);

	return cadena;

}

void senal(int signal){

	printf("soy la señal %d\n",signal);
		 switch (signal) {
                case SIGUSR1:
					bandera = 1;
                    break;
                case SIGUSR2:
					bandera = 2;
                    break;
                default:
					bandera = 0;
                    perror("ERROR EN SIGNAL");
                    exit (-1);
            }
}
