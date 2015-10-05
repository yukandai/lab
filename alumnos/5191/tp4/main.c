#include "http_worker.h"

int main(int argc, char * const *argv) {
	int sd;
	int sd_conn;
	int opt = 1;
	int optlen = sizeof(opt);
	socklen_t addrlen;
	struct sockaddr_in srv_addr;
	struct sockaddr_in cli_addr;

	//
	int opcion;
	int puerto = 2222;
	char *ruta = NULL;
	//
	
	while ((opcion = getopt(argc,argv, "d:")) != -1){
		switch (opcion){
			case 'd':  // ruta
				NombreRuta(&ruta);	
				break;
		} // fin switch
	} // fin while

	if (ruta == NULL){
		perror("Error en la ruta");
		return -1;
	}
	/* TODO: agregar creación y configuración del socket */
	sd = socket (AF_INET,SOCK_STREAM,0);

	if (sd < -1){
		perror("Error en la creacion del socket\n");
		return -1;
	}

	srv_addr.sin_family=AF_INET;
	srv_addr.sin_port = htons(puerto);
	srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &opt, optlen);

	if (bind(sd,(struct sockaddr*) &srv_addr,sizeof(srv_addr))==-1){
		perror("Error en bind\n");
		return -1;
	}

	if(listen(sd,10)<0){
		perror("Error en listen\n");
		return -1;
	}

	signal(SIGCHLD,SIG_IGN);

	while( (sd_conn = accept(sd, (struct sockaddr *) &cli_addr, &addrlen)) > 0) {
		switch (fork()) {
			case 0: // hijo
				printf ("Direccion del nuevo cliente: %s en el puerto %d \n",inet_ntoa((struct in_addr) cli_addr.sin_addr),puerto);
				http_worker(sd_conn, (struct sockaddr *) &cli_addr,ruta);
				return 0;

			case -1: // error
				perror("Error en la creacion de fork\n");
				break;

			default: // padre
				printf("Inicio de Servidor en el puerto: %d",puerto);
				
				break;
		} // fin switch
		close(sd_conn);
	} // fin while

	return 0;
} // fin main

