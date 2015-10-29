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

#include <pthread.h>

#define RES_LEN 256

typedef struct http_req {
	char method[6];
	char resource[RES_LEN];
	char version[10];	
} http_req_t;

char *ruta;

void nombre_ruta(char **nombre);

int create_socket(char *puerto,int opt,int optlen);

void *http_worker(void *sd_conn);

char *archivo_extension(char *resource);


#endif