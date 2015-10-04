#include "http_worker.h"

void http_worker(int sd_conn, struct sockaddr * cliente, char *ruta){
	
	int leido;

	char buffer[1024];
	memset(buffer,0,sizeof(buffer));

	//char *version = NULL;
	char archivo[256];
	char mime[256]; 

	if ((leido = read(sd_conn, buffer, sizeof(buffer))) > 0){
		memset(archivo,0,sizeof(archivo));
		memset(mime,0,sizeof(mime));

		URI(buffer,archivo,mime,ruta);

	} // fin if leido

} // fin funcion