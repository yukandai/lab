#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "func.h"
#include "hijo.h"
#include "nieto.h"

int fd_ph[2],fd_hp[2],fd_hn[2];

int main(int argc, char *argv[]){
	int n,r;
	char buff[BUF_SIZE];
	
	if(pipe(fd_ph)<0 || pipe(fd_hp)<0||pipe(fd_hn)<0){
		perror("Error en pipe()\n");
		exit(EXIT_FAILURE);
	}
	switch(fork()){
		case -1:
			perror("fork: ");
			exit(EXIT_FAILURE);
		case 0:
		      	signal(SIGUSR1,handlerHijo); 	//signal n° 10
			signal(SIGUSR2,handlerNieto);	//signal n° 12
			pause();	
			return 0;
		default:
			close(fd_ph[P_RD]);
			close(fd_hp[P_WR]);
			while((n=read(STDIN_FILENO,buff,sizeof buff))>0){
				write(fd_ph[P_WR],buff,n);
				r=read(fd_hp[P_RD],buff,sizeof buff);
				write(STDOUT_FILENO,buff,r);		
			}
			close(fd_ph[P_WR]);
			close(fd_hp[P_RD]);
	}
	exit(EXIT_SUCCESS);
}
