#ifndef _HEADER_H_
#define _HEADER_H_

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
#include <signal.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>



void nombre_archivo(char **nombre); //parser.c

int parser_puerto(char *archivo); //parser.c

char *parser_ruta(char *archivo); //parser.c

char *http_worker(int acceptfd,char *ruta);

char *recurso (char *buffer,char *archivo, char *tipo, long * longitud, char *ruta);





#endif

