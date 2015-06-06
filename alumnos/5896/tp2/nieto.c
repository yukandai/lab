#include "nieto.h"
#include "hijo.h"
#include "parser.h"

void nieto (int signo){

	printf("Recibi la señal SIGUSR2 %d\n",signo);
	close(pah[PIPE_WR]);

	leido = read(pah[PIPE_RD],buff,sizeof buff);
	write(han[PIPE_WR],buff,leido);//envio al nieto

	close(pah[PIPE_RD]);
	close(han[PIPE_WR]);
	//CREACION DE NIETO

	pid2=fork();


	//nieto

	if (pid2 == 0){

		close(han[PIPE_WR]);
		close(hap[PIPE_RD]);

		leido = read(han[PIPE_RD],buff,sizeof buff);
		printf("soy el nieto %d hijo de %d y envio esto a mi abuelo:\n",getpid(),getppid());
		//aplicando filtrado de palabras

		filtrar();	
	}

}

