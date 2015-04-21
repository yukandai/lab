#include "parser.h"


void mensajeFiltrado(char *mensaje, char *archivo){

	int fd;
	
	if (archivo != NULL){ // hago open de ese archivo
		
		if ((fd = open(archivo,O_CREAT|O_RDWR|O_APPEND,0666)) < 0){
			perror("Error en open\n");
			exit(-1);//return errno;
		}

		if (write(fd,archivo,strlen(archivo) == -1)){
			perror("Error en write\n");
			exit(-1);//return errno;
		}

		write(fd,mensaje,strlen(mensaje));
		write(fd,"\n",1);
		
		close(fd);
	} else { // escribo en la salida estandar
		write(STDOUT_FILENO,mensaje,strlen(mensaje));
		write(STDOUT_FILENO,"\n",1);		
	}


}
