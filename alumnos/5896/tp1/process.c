
#include "process.h"
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
