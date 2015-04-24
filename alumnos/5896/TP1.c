/**
* Trabajo Practico Nº1
*/
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#define SIZE 80
int process(char *input, int op, char *nombre,int len);
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
				printf("./tp1 -o mensajefiltrado.txt: (make test2)\nGuarda mensaje filtrado en un archivo llamado mensajefiltrado.txt\n");
				break;

				}

							}
		return 0;
		}

int process(char *input, int op, char *nombre, int len)
{
  int i;
  int m;
  char filtrado[1024];
  char palabra[1024]="hola";
  char *token;
  int fd;
  int leido=0;
  memset(filtrado, 0, sizeof filtrado);

  fd = open(nombre,O_RDWR|O_CREAT,0777);
   token = strtok(input, " \n\t");
   m = strcmp(token,palabra);
   if (m==0) {
              token="****";
             }  
   strcat(filtrado,token);
   strcat(filtrado," ");
    while( (token = strtok( NULL, " \n\t" )) != NULL ){
                                       i = strcmp(token,palabra);
                                       if (i==0){
						token="****";
						}
					strcat(filtrado,token);
					strcat(filtrado," ");
					}

    if(op==0){	//muestra por salida
	write(STDOUT_FILENO, filtrado, strlen(filtrado));
	}else{ //guarda en archivo
	printf("el mensaje se ha filtrado a un archivo llamado %s \n", nombre);


	write(fd, filtrado, strlen(filtrado)); 
    }
return 0;
}
