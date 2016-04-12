#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include "http_worker.h"



int main(int argc, char * const *argv)
{
	int sd, sd_conn;
	int yes= 1;
	int opt = 1, optlen = sizeof(opt);
	socklen_t addrlen;
	struct sockaddr_in srv_addr;
	struct sockaddr_in cli_addr;
                                                          
    /* TODO: agregar creación y configuración del socket */
    sd= socket (AF_INET, SOCK_STREAM, IPPROTO_TCP); 
    setsockopt (sd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof (int));
    memset (&srv_addr, 0, sizeof (srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons (2020);
    srv_addr.sin_addr.s_addr= htonl (INADDR_ANY);


    if ((bind (sd, (struct sockaddr *) &srv_addr, sizeof (srv_addr)))<0){
        perror ("Bind:");
        exit (-1);
    }

    if ((listen (sd, 10))<0){
        perror ("Listen:");
        exit (-1);
    }
	addrlen=sizeof cli_addr;
	
	while( (sd_conn = accept(sd, (struct sockaddr *) &cli_addr, &addrlen)) > 0) {
		switch (fork()) {
			case 0: // hijo
			    http_worker(sd_conn, (struct sockaddr *) &cli_addr);
				return 0;

			case -1: // error
				break;

			default: // padre
			    break;
		}
	}
	return 0;
}


