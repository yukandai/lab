#include "hijo.h"
#include "nieto.h"
#include "sigusr.h"


void funcionHijo(int hijo_lee_padre ,int hijo_escribe_padre){

	int tuberia_nieto_hijo[2]; // pipe3
	
	int leidos;

	char buffer[10];
	memset(buffer,0,sizeof(buffer));
	char buffer3[10];
	memset(buffer3,0,sizeof(buffer3));

	char *frase = NULL;

	char buf[10];
	memset(buf,0,sizeof(buf));

	printf("Soy el proceso hijo: %d\n",getpid());

	if (signal(SIGUSR1,senal) == SIG_ERR){
		perror ("fallo en signal");
		exit(EXIT_FAILURE);
	}
	
	if (signal(SIGUSR2,senal) == SIG_ERR){
		perror ("fallo en signal 2");
		exit(EXIT_FAILURE);
	}

	if (pipe(tuberia_nieto_hijo) != 0){
		perror("Error pipe nieto hijo");
		exit(-1);
	}

	pause();	


	if (bandera == 1){
		while ((leidos = read(hijo_lee_padre, buffer,10)) > 0){
			buffer[leidos] = '\0';

			//if (bandera == 1){
				frase = escribirEnPadreSIGUSR1(buffer,hijo_escribe_padre);						
				write(hijo_escribe_padre,frase,strlen(frase));	
			//}
			
		

		} // fin while
		close(hijo_lee_padre);
		close(hijo_escribe_padre);
	}

	if (bandera == 2){
		
		// creo nieto --> fork
		switch(fork()){
			case -1: // error fork
				perror("error en fork - nieto");
				exit(-1);
			case 0: // nieto
				printf("Soy el proceso hijo: %d\n",getpid());

						close(tuberia_nieto_hijo[1]);
						funcionNieto(tuberia_nieto_hijo[0],hijo_escribe_padre);
						exit(2);
					default: // hijo escribe en pipe3
						while ((leidos = read(hijo_lee_padre, buffer,10)) > 0){
							buffer[leidos] = '\0';
								
							close(tuberia_nieto_hijo[0]); // cierro lectura pipe3
							write(tuberia_nieto_hijo[1],buffer,strlen(buffer));	

						}
						close(hijo_lee_padre);
						close(tuberia_nieto_hijo[1]);
					
		}										
							
				
	}				


	exit(2);
}
