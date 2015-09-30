#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#include "http_worker.h"


void http_worker (int sock, struct sockaddr *cli_addr ){

    void *buff=malloc (128);
    int leido;
    char *response= "HTTP/1.1 404 NOT FOUND \n";   
    sendto (sock, response, strlen(response),0 , cli_addr, sizeof (*(cli_addr)));
    leido=recv (sock, buff, 512, 0);
    write (STDOUT_FILENO, buff, leido);
    write (sock, (void*) msje, 45);
    //printf ("Cliente conectado\n");
    shutdown (sock, 2);
    //close (sock);
      

}
