#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "http_worker.h"

void http_worker(int sd_conn, void *cli_addr){
	int leido, archivo;
	char buff[1024], buff2[1024];
	char cabecera[1024];	
	direccion dir;
	
	memset(buff, 0, sizeof buff);
	memset(cabecera, 0, sizeof cabecera);
	if ((leido = read(sd_conn, buff, sizeof buff)) > 0){
		dir = datosDireccion(buff);
		if ((archivo = open (dir.ruta, O_RDONLY)) < 0){
			perror ("open");
			leido = snprintf (cabecera, sizeof cabecera, "HTTP/1.0 404 Not Found\r\nContent-Type: text/html\r\nContent-Length: 50\r\n\r\n");
			write (sd_conn, cabecera, leido);
			write (sd_conn, "Error 404 no exite archivo\n", 27);
		}
		else{
			leido = snprintf (cabecera, sizeof cabecera, "HTTP/1.0 200 OK\r\nContent-Type: %s\r\nContent-Length: %ld\r\n\r\n", dir.mime, dir.len);
			write (sd_conn, cabecera, leido);
			
			memset (buff2, 0, sizeof buff2);
			while ((leido = read (archivo, buff2, sizeof buff2)) > 0){
				write (sd_conn, buff2, leido);			
			}
		}
	}
	else{
		leido = snprintf (cabecera, sizeof cabecera, "HTTP/1.0 500 Internal Server Error\nContent-Type: text/html\r\nContent-Length: 50\r\n\r\n");
		write (sd_conn, cabecera, leido);
		write (sd_conn, "Error 500: Error en el Servidor\n", 32);
	}
}

