#include "http_worker.h"

int main(int argc, char * const *argv) {
	int sd;
	int sd_conn;
	int opt = 1;
	int optlen = sizeof(opt);
	socklen_t addrlen;
	//struct sockaddr_in srv_addr;
	//struct addrinfo hints, *result;
	struct sockaddr_in cli_addr;

	addrlen = sizeof(cli_addr);
	//
	int opcion;
	char *puerto = "2222";
	char *ruta = NULL;
	
	pthread_t tid;
	pthread_attr_t atributos;

	pthread_attr_init(&atributos);
	pthread_attr_setdetachstate(&atributos,PTHREAD_CREATE_DETACHED);
	//

	while ((opcion = getopt(argc,argv, "d:")) != -1){
		switch (opcion){
			case 'd':  // ruta
				nombre_ruta(&ruta);	
				break;
		} // fin switch
	} // fin while

	if (ruta == NULL){
		write (STDERR_FILENO , "Error en la ruta\n",17 );
		return -1;
	}
	/* TODO: agregar creación y configuración del socket */
	
	sd = create_socket(puerto,opt,optlen);


	while( (sd_conn = accept(sd, (struct sockaddr *) &cli_addr, &addrlen)) > 0) {
		//pthread_create(&tid,&attr, http_worker, (void *)&sd_conn);
		//datos_array[sd_conn].socketfd = sd_conn;
		//pthread_create (&tid,&atributos, http_worker, (void *) &datos_array[sd_conn]);				
		pthread_create (&tid,&atributos, http_worker, (void *)&sd_conn); 
	} // fin while
	close(sd_conn);

	free(ruta);
	return 0;
} // fin main

