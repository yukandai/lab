#include "funciones.h"

int hijo(int sd_conn, char* nomArchivo, char* direccion){

        int N, txt, leido;
        char bufaux[512];
        bzero(bufaux,512);
       
        
        strcat(direccion, nomArchivo);
                
        nomArchivo = strtok(nomArchivo, ".");
        nomArchivo = strtok(NULL, ".");
        
        printf("La direccion es: %s\n", direccion);
       
        
        if((txt = open(direccion, O_RDWR, S_IRWXU))<0){
                perror("ERROR en el hijo:Error en open: ");
		write(sd_conn,"HTTP/1.1 404 Not Found\r\n", 24); 

		return 0;
	}
	
	N=extencion(sd_conn,nomArchivo);
	write (sd_conn, "\r\n" , 2);
	if(N>=0){
		while ((leido = read (txt, bufaux,512))>0) {
			write(sd_conn,bufaux, sizeof (bufaux));
			bzero(bufaux,512);
		}                     
	}       
        
        return 0;
}