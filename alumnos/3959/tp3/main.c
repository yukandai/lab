//@anaquinpm
//El padre lee la entrada STDIN y lo carga en ShMem. Dos Hijos deben procesar la información
//y reemplazar las palabras prohibidas por asteriscos.
//El padre debera mostrar por STDOUT el resultado de lo procesado

#include <sys/types.h>	//shm
#include <sys/mman.h>	//shm
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>	//getopt
#include <stdio.h>	//perror
#include <stdlib.h>	//exit
#include <string.h> 	//strcpy
#include "func.h"
#include "hijo.h"

char *words;
char *input;
sem_t * sp;

int main(int argc, char *argv[]){
	int n,fd,c=0;
	int m_sh= sizeof(char) * BUF_SIZE;
	int m_size= m_sh+sizeof(sem_t);
	int val_sp=0;
	void * addr;				 //punteros a ShMem para que escriban los hijos
	char buff[BUF_SIZE];

	if((fd=shm_open("/shm",O_CREAT| O_RDWR |O_TRUNC,0666))==-1) exit(EXIT_FAILURE);
	if((ftruncate(fd,m_size))==-1) exit(EXIT_FAILURE);
	addr = mmap(NULL,m_size,PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS,fd,0);
	if (addr==MAP_FAILED) exit (EXIT_FAILURE);

	sp = (sem_t *) addr;
	addr+=sizeof(sem_t);
	input= (char *)addr;	

	if (((sem_init(sp,1,0))==-1)) exit (EXIT_FAILURE); 

	while((c=getopt(argc,argv,"p:"))!=-1||argc==1){
		switch(c){
			case 'p':
				words=argv[2];
				switch(fork()){
					case -1:
						perror("fork: ");
						exit(EXIT_FAILURE);
					case 0:
						hijo();
						//printf("soy el hijo:\n%s\n",buff);
						return 0;
					default:
						while((n=read(STDIN_FILENO,buff,m_sh))>0){
							strcpy(input,buff);	
							sem_getvalue(sp,&val_sp);
							printf("sp_value:%d\n",val_sp);
							sem_wait(sp);
							write(STDOUT_FILENO,input,n);
							wait(NULL);
							shm_unlink("/shm");
						}
				return 0;


				}
			default:
				printf("Modo de uso:\t cat mensaje.txt | ./tp3 -p <palabras,a,filtrar>\n");
				return 0;
		}
	}
	exit(EXIT_FAILURE);
}
