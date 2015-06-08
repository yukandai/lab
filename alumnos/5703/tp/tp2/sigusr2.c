#include "sigusr2.h"
#include "global.h"

void sigusr2(int procPadre, int argc, char *argv[], int pah[2], int hap[2]){
	int han[2], leido,fp, leo, i, m_long;
	char buff[MAX], buff2[MAX], buff3[MAX];
	
	if(pipe(han) < 0){
		perror("pipe(): ");
	}

	close(pah[WRITE]);	
	leido = read(pah[READ], buff, sizeof buff);
	close(pah[READ]);

    if((fp = fork()) < 0){	
		perror("fork()");
	} 
	
	if(fp > 0){//el hijo escribe en el pipe3
		close(han[READ]);
		write(han[WRITE], buff, leido);
		close(han[WRITE]);
	}

	if(fp == 0){
		//el nieto lee del pipe3
		close(han[WRITE]);
		leo = read(han[READ],buff2, sizeof buff2);
		close(han[READ]);

		//filtro las palabras
		strcpy(buff3,buff2);
		m_long=0;
		
		for(i = 1; i < argc; i++){
			strcpy(buff3, (funcionNieto(buff3, argv[i])));
			m_long = m_long + strlen(argv[i]);
		}

		//lo escribo en el pipe 2
		close(hap[READ]);
		write(hap[WRITE],buff3, leo-m_long);
		close(hap[WRITE]);			
	}

	kill(procPadre, 23);
}