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
    void *msje="hola mundo\n";
    sendto (sock, msje, strlen(msje),0 , cli_addr, sizeof (*(cli_addr)));
    leido=recv (sock, buff, 512, 0);
    write (STDOUT_FILENO, buff, leido);
    shutdown (sock, 2);
    
      

}
