#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include "http_worker.h"

int create_socket (datos * d_con)
{
	int  opc = 1, sfd;
	struct addrinfo hints,*res,*result;

	memset(&hints,0,sizeof (struct addrinfo));
	hints.ai_family = AF_UNSPEC; // Mismo que para la fucion Socket()
	hints.ai_socktype= SOCK_STREAM; //Puerto del servicio
	hints.ai_flags = AI_PASSIVE; //Se puede atender cualquier cliente
	
	if((getaddrinfo(NULL,d_con->PORT,&hints,&result))!=0){
		perror("getaddrinfo:");
		exit(EXIT_FAILURE);
	}
	for(res=result;res!=NULL;res=res->ai_next){
		sfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
		if (sfd  < 0){
			perror("socket");
			continue;	//trata con una nueva dirección
		}
		if(setsockopt(sfd,SOL_SOCKET,SO_REUSEADDR,&opc,sizeof (opc))==-1){
			perror ("setsockopt");
			exit(EXIT_FAILURE);
		}
		if (bind(sfd, res->ai_addr, res->ai_addrlen) != 0){
			perror("bind");
			exit(EXIT_FAILURE);
			 }                 
	}
	if(listen(sfd,10)<0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
	freeaddrinfo(result);
	return sfd;
}
