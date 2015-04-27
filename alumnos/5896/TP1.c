/**
* Trabajo Practico Nº1
*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#define SIZE 80
#include "process.h"
int main(int argc, char **argv)
{
int nchars = 0;
char buff[SIZE];
int operacion=0;
extern char *optarg;
extern int optind, opterr, optopt;

	memset(buff, 0, sizeof buff);
	if(argc==1){ 
		while((nchars = read(STDIN_FILENO, buff, sizeof buff)) > 0){

                                            process(buff,operacion,NULL,nchars);
                            
			}	
		}	
	while((operacion = getopt( argc, argv, "o:h")) >= 0){
   			switch (operacion){

   
				case 'o':
				//printf("estoy en o \n");
				while(
  
  				(nchars = read(STDIN_FILENO, buff, sizeof buff)) > 0){
                                          process(buff,operacion,optarg,nchars);
                         		 }		

				break;
				case 'h':
			//	printf("estoy en h \n");
				printf("Modo de uso:\n./TP1: (make test1)\n Muestra mensaje filtrado en pantalla.\n");
				printf("./tp1 -o mensajefiltrado.txt: (make test2)\nGuarda mensaje filtrado en un archivo llamado mensajei-filtrado.txt\n");
				break;

				}

							}
		//return 0;
		}


