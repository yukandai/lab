#include "http_worker.h"

void http_worker(int sd_conn, struct sockaddr * cliente, char *ruta){
	
	int fd;
	int leido;
	long longitud = 0;

	char buffer[1024];
	memset(buffer,0,sizeof(buffer));

	//char *version = NULL;
	char archivo[256];

	char mime[256]; 
	char *metodo = NULL;
	char *estado = NULL;

	if ((leido = read(sd_conn, buffer, sizeof(buffer))) > 0){
		memset(archivo,0,sizeof(archivo));
		memset(mime,0,sizeof(mime));

		metodo = URI(buffer,archivo,mime,ruta, &longitud);

		if (!(strncmp(metodo,"GET",3) == 0)){
			estado = "500 INTERNAL SERVER ERROR\n";
			write(acceptfd,estado,strlen(estado));
			exit(0);
		}

		if ((fd = open(archivo, O_RDONLY)) < 0){
			estado = "404 NOT FOUND";
		}

	} // fin if leido

} // fin funcion