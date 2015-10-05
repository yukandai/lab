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

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>



void NombreArchivo(char **nombre); //parser.c

int ParserPuerto(char *archivo); //parser.c

char *ParserRuta(char *archivo); //parser.c

char *http_worker(int acceptfd,char *ruta);

char *Recurso (char *buffer,char *archivo, char *tipo, long * longitud, char *ruta);





#endif

