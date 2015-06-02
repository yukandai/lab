#include "hijo.h"
#include "rot13.h"

int bandera = 0; // variable global

void funcionHijo(int hijo_lee_padre ,int hijo_escribe_padre){
	
	int leidos;
	char buffer[10];
	memset(buffer,0,sizeof(buffer));

	char *frase = NULL;

	printf("Soy el proceso hijo: %d\n",getpid());

	if (signal(SIGUSR1,senal) == SIG_ERR){
		perror ("fallo en signal");
		exit(EXIT_FAILURE);
	}
	
	if (signal(SIGUSR2,senal) == SIG_ERR){
		perror ("fallo en signal 2");
		exit(EXIT_FAILURE);
	}

	pause();	


	while ((leidos = read(hijo_lee_padre, buffer,10)) > 0){
		buffer[leidos] = '\0';

		if (bandera == 1){
			frase = escribirEnPadre(buffer,hijo_escribe_padre);						
	
			write(hijo_escribe_padre,frase,strlen(frase));	
//			write(hijo_escribe_padre,"-",1);
		}
	
	}
//	printf ("hijo ya no lee\n");	
	close(hijo_lee_padre);
	close(hijo_escribe_padre);
	exit(2);
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

char *escribirEnPadre(char *palabra,int hijo_escribe_padre){
	char *cadena = NULL;

	cadena = rotate(palabra);

	cadena = strncat(cadena," ",1);

	return cadena;

}
