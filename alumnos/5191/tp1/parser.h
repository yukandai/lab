#ifndef _PARSER_H_
#define _PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
	
	void Ayuda();	
	char *filtrarPalabra(char *palabra);
	void mensajeFiltrado(char *archivo, char *mensaje);
#endif


