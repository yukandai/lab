#include "http_worker.h"

int create_socket(char *puerto, int opt, int optlen){

struct addrinfo hints, *result;

int sfd;

	printf ("IPV4 | IPV6\n");
	printf ("Puerto %s\n",puerto);

	bzero(&hints,sizeof(struct addrinfo));

	hints.ai_family = AF_UNSPEC; // funciona con ipv4 y 6
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;


	if (getaddrinfo(NULL,puerto,&hints,&result) != 0) {
		perror("getaddrinfo() error.");
		exit(EXIT_FAILURE);
	}


	do {
		sfd = socket (result->ai_family, result->ai_socktype, result->ai_protocol);	
		if (sfd < 0)
			continue;

		setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &opt, optlen);

		if (bind(sfd,result->ai_addr, result->ai_addrlen) != 0){
			perror ("Error en bind (getaddrinfo)\n");
			return -1;
		}		
	
	} while ( (result = result->ai_next) != NULL);
		

	if (listen (sfd,10) < 0){
			perror("Error en listen (getaddrinfo)");
			return -1;
	}

	return sfd;


} // fin funcion
