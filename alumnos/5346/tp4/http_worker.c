#include "funciones.h"

int http_worker(int sd_conn, struct sockaddr* addr){

	int dirlen;
	char *droot="tmp";
	char direccion[100];
	bzero(direccion,512);
	char buff[512];
	bzero(buff,512);
	char* tok;
	char* nomArchivo;

	strcat(direccion, droot);
    dirlen = strlen(direccion);
        
    if(direccion[dirlen-1]=='/'){
    	direccion[dirlen-1] = '\0';
    }


	read(sd_conn, buff, sizeof buff);
	write(STDOUT_FILENO, buff, sizeof buff); 
	
	tok = strtok(buff, " ");
		        
	if((strncmp("GET", tok,3))==0){
		nomArchivo = strtok(NULL, " ");
		printf("En el servidor: %s\n\n",direccion);
		                
		hijo(sd_conn, nomArchivo, &direccion[0]);
		                
		printf("\nSALI DEL HIJO\n"); 
	}

	else if(!(strncmp("GET", tok,3))==0){
		
		char *estado;		
		estado = "HTTP/1.1 500 INTERNAL SERVER ERROR\n\nInternal Server error\n";
		write (sd_conn, "HTTP/1.1 500 INTERNAL SERVER ERROR\n\nInternal Server error\n", strlen (estado));
		printf("\nMETODO NO IMPLEMENTADO\n");


	}
	return 0;
}