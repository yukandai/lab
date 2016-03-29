#ifndef _HTTP_WORKER_H_
#define _HTTP_WORKER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>


void http_worker(int sd_conn, struct sockaddr *, char *ruta);

void nombre_ruta(char **nombre);

char *URI (char *buffer,char *archivo, char *mime, char *ruta, long *longitud);

#endif