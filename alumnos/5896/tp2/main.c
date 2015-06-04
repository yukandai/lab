#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include "hijo.h"
#include "parser.h"
#include "nieto.h"
/*void palabras(char *palabras);
char palabra1[50];
char palabra2[50];
char palabra3[50];
char *ptr;

int k=1;

*/

int main (int argc, char *const argv[])
{
int operacion=0;
extern char *optarg;
extern int optind, opterr, optopt;

	pipe(pah);
	pipe(hap);
	pipe(han);
	printf("soy %d hijo de %d\n",getpid(),getppid());		
	int pid,leido;
	char mensaje[100],buff[100];
	if (pipe(hap) < 0) {
		perror("pipe():1");
		return -1;
	}
	if (pipe(pah) < 0) {
		perror("pipe():2");
		return -1;
	}
	if (pipe(han) < 0) {
		perror("pipe():3");
		return -1;
	}
	pid=fork();
	if (pid < 0) {
		perror("fork()");
		return -1;
	}

/*       while((operacion = getopt( argc, argv, "p")) >= 0){
                          switch (operacion){
  
  
                                  case 'p':
                                  printf("estoy en p %s \n",argv[2]);
                                palabras(); 
  
                                  
  
                                  break;
                      
  
                                  }
  
                                                          } */
		//hijo
	if (pid == 0){

		printf("soy el hijo \n");
		printf("soy  el hijo %d esperando la señal!\n",getpid());
		if (signal(SIGUSR1, manejador) == SIG_ERR) {
			perror("error en la señal SIGUSR1");
			exit(EXIT_FAILURE);
		}
		if (signal(SIGUSR2, manejador) == SIG_ERR) {
			perror("error en la señal SIGUSR2");
			exit(EXIT_FAILURE);
		}

		for ( ; ; )
			pause();
	}

	//padre	
       while((operacion = getopt( argc, argv, "p")) >= 0){
                          switch (operacion){
  
  
                                  case 'p':
                                  printf("palabras a filtrar %s \n",argv[2]);
                                palabras(argv[2]); 
  
                                  
  
                                  break;
                      
  
                                  }
  
                                                          } 
	

	close(pah[PIPE_RD]);
	close(hap[PIPE_WR]);

	leido=read(STDIN_FILENO,mensaje,sizeof mensaje);
	write(pah[PIPE_WR],mensaje,leido);

	leido = read (hap[PIPE_RD],buff,sizeof buff);
	write(STDOUT_FILENO,buff,leido);

	close(hap[PIPE_RD]);
	close(pah[PIPE_WR]);


	return 0;	
}

/*void palabras(char *palabras){
char s2[4] = ",";
 
  memset(palabra1, 0, sizeof palabra1);
  memset(palabra2, 0, sizeof palabra2);
  memset(palabra3, 0, sizeof palabra3);
   //  printf( "s1=%s\n", argv[2] );
  
     ptr = strtok( palabras, s2 );    // Primera llamada => Primer token
   //  printf( "%s\n", ptr );
          strcpy(palabra1,ptr);
     while( (ptr = strtok( NULL, s2 )) != NULL ){    // Posteriores llamadas
 //      printf( "%s\n", ptr );
  
          k++;
      if(k==2){
           strcpy(palabra2,ptr);
  }
  
  if(k==3){
           strcpy(palabra3,ptr);
  }
  
  }
  
  printf (" palabra1: %s \n",palabra1);
  
  printf (" palabra2: %s \n",palabra2);
  printf (" palabra3: %s \n",palabra3);
  


		}*/
