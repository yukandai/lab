#ifndef MAINH
#define MAINH
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

//Declaramos funciones


//Declaramos variables
char mensaje[100],buff[100];
//	char *orgmensaje;
int pid;
int leido;
int fd, fdo;
int operacion;
extern char *optarg;
extern int optind, opterr, optopt;

#endif
