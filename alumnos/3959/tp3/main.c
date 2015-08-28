//@anaquinpm
//El padre lee la entrada STDIN y lo carga en ShMem. Dos Hijos deben procesar la información
//y reemplazar las palabras prohibidas por asteriscos.
//El padre debera mostrar por STDOUT el resultado de lo procesado

#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>	//shm
#include <sys/mman.h>	//shm
#include <sys/wait.h>
#include <unistd.h>	//getopt
#include <stdio.h>	//perror
#include <stdlib.h>	//exit
#include "func.h"
#include "hijo.h"

char *words;
sem_t * sp;

int main(int argc, char *argv[]){
	int n,c=0;
	//char *buff= malloc(BUF_SIZE*sizeof(char));
	char *buff;
	int m_sh= sizeof(char) * BUF_SIZE;
	int m_size= m_sh+sizeof(sem_t);
	void * addr;				 //punteros a ShMem para que escriban los hijos

	addr = mmap(NULL,m_size,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,-1,0);
	if (addr==MAP_FAILED)	perror ("MMAP");

	sp = (sem_t *) addr;
	addr+=sizeof(sem_t);
	buff= (char *)addr;	

	if (((sem_init(sp,1,0))==-1)) {  exit (EXIT_FAILURE); }

	while((c=getopt(argc,argv,"p:"))!=-1||argc==1){
		switch(c){
			case 'p':
				words=argv[2];
				switch(fork()){
					case -1:
						perror("fork: ");
						exit(EXIT_FAILURE);
					case 0:	
						hijo(buff);			
						return 0;
				}
				sem_wait(sp);	
				while((n=read(STDIN_FILENO,buff,m_sh))>0){
					sem_post(sp);
					sem_wait(sp);
					write(STDOUT_FILENO,buff, m_sh);
					}
				wait(NULL);
				return 0;
			default:
				printf("Modo de uso:\t cat mensaje.txt | ./tp3 -p <palabras,a,filtrar>\n");
				return 0;
		}
	}
	exit(EXIT_FAILURE);
}
