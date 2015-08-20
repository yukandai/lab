#include "funciones.h"
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void nieto(int pdesc2[2], int pdesc3[2], int argc, char **argv){
	int leido, opc;
	char buff[10000];
	char *palabras;
	char *palab;
	extern char *optarg;
	extern int optind, opterr, optopt;
	while((opc = getopt(argc, argv, "p:o"))>0){
		switch(opc){
			case 'p':
				palabras = optarg;
				break;
			default:
				printf("MODO DE USO Bla, bla bla bla bla \n");
				exit(1);
		}
	}	

	leido=read(pdesc3[0], buff, sizeof buff);

	palab = strtok(palabras,",");
	char *token = palab;
	parser(buff,leido,palab);
	while((token = strtok(NULL, ",")) !=NULL){
		parser(buff,leido,token);
	}
	write(pdesc2[1],buff,leido);
	return;
}
