#include <sys/types.h> 
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <netdb.h>
#include <signal.h>
#include "http_worker.h"


int main(int argc, char * const *argv)
{
	int sd, sd_conn;
	int opt = 1, optlen = sizeof(opt);
	socklen_t addrlen;
	struct sockaddr_in srv_addr;
	struct sockaddr_in cli_addr;
	
	
	signal(SIGCHLD, SIG_IGN); //ELimina los procesos zombis
	addrlen = sizeof(&cli_addr);
    	
	if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket()");
		return -1;
	}

	srv_addr.sin_family=AF_INET;
	srv_addr.sin_port=htons(8080);
	srv_addr.sin_addr.s_addr = INADDR_ANY;

	setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &opt, optlen);

	if (bind (sd, (struct sockaddr *) &srv_addr, sizeof srv_addr) == -1){
		perror("bind()");
		return -1;
	}
	if (listen(sd,10) == -1){
		perror("listen()");
		return -1;
	}

	while((sd_conn = accept(sd, (struct sockaddr *) &cli_addr, &addrlen)) > 0){
		switch (fork()) {
			case 0: // hijo
				close(sd);
				http_worker(sd_conn, (struct sockaddr *) &cli_addr);
				close(sd_conn);
				return 0;

			case -1: // error
				break;

			default: // padre
				close(sd_conn);
				break;
		}
	}

	return 0;
}

