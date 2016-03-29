#include "http_worker.h"

int http_worker(int sd_conn, struct sockaddr* addr){

	socklen_t len;
	
	sd_conn = socket (PF_INET, SOCK_STREAM, 0);

	/* Set addr */
	addr.sin_port = htons (3456);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);//INADDR_ANY se queda 
	//esperando de todas las dirrecciones pero en el puerto especificado
	addr.sin_family = PF_INET;

	len = sizeof addr ;

	if (connect(sd_conn, (const struct sockaddr *) &addr, len)<0){
		perror("connect()");
		return -1;
	}

	return 0;
}