#include "hijo.h"
#include "nieto.h"
#include "parser.h"
//Funcion manejador


void manejador (int signo){

	//Si la señal es SIGUSR1 entonces
	if(signo==SIGUSR1){
		printf("Recibi la señal SIGUSR1 %d\n",signo);
		close(hap[PIPE_RD]);
		close(pah[PIPE_WR]);


		leido = read(pah[PIPE_RD],buff,sizeof buff);
		printf("soy el hijo %d y envio esto a mi padre %d:\n",getpid(),getppid());
		//aplicando rot13 a buff

		ROT13();


	}
	//Si es SIGUSR2 entonces
	else{
		if(signo==SIGUSR2)
		{
			nieto(signo);
		}
	}
}
