#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#include "nieto.h"
#include "srch.h"

void handlerNieto(int sig){	//manejador de la señal para crear el nieto
	char buff[BUF_SIZE];
	int n;
	close(fd_ph[P_WR]);
	close(fd_hp[P_RD]);
	switch(fork()){
		case -1:
			perror("fork del nieto");
			exit(EXIT_FAILURE);
		case 0:
			close (fd_hn[P_WR]);
			while((n=read(fd_hn[P_RD],buff,sizeof buff))>0){
				srch(buff,fd_hp[P_WR]);
			}
			close(fd_hp[P_WR]);
			return;
		default:
			while((n=read(fd_ph[P_RD],buff,sizeof buff))>0){
				write(fd_hn[P_WR],buff,sizeof buff);
			}
			close(fd_hn[P_RD]);
			
	}
}
