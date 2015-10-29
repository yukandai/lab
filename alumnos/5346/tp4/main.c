#include "funciones.h"


int main(int argc, char * const *argv)
{
	int sd, sd_conn;
	int opt = 1, optlen = sizeof(opt);
	socklen_t addrlen;
	struct sockaddr_in srv_addr;
	struct sockaddr_in cli_addr;
	char *ip = "127.0.0.1";
	int port = 2000;

    /* TODO: agregar creación y configuración del socket */

    sd = socket (PF_INET, SOCK_STREAM, 0);

	/* Set srv_addr */
	srv_addr.sin_port = htons (port);
	//srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	inet_aton(ip,&srv_addr.sin_addr);// esta funcion pasa de ascci a red la variable
	srv_addr.sin_family = AF_INET;

	addrlen = sizeof srv_addr ;

	if (bind(sd, (const struct sockaddr *) &srv_addr, addrlen)<0){
		perror("bind()");
		return 1;
	}
	if (listen(sd, 10) < 0){
		perror ("listen()");
		return 1;
	}

	printf("Estoy por entrar al servidor: %s\nY mi puerto es: %d\r\n\n",ip ,port);

	signal(SIGCHLD, SIG_IGN);
	while( (sd_conn = accept(sd, (struct sockaddr *) &cli_addr, &addrlen)) > 0) {
		switch (fork()) {
			case 0: // hijo
				close(sd);
				http_worker(sd_conn, (struct sockaddr *) &cli_addr);
				close (sd_conn);
				return 0;

			case -1: // error
				break;

			default: // padre
				break;
		}
		close (sd_conn);
	}
	close(sd);
	return 0;
}