#ifndef PARSERH
#define PARSERH
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#define PIPE_RD 0
#define PIPE_WR 1


//Declaramos funciones

void ROT13();
void filtrar();
void palabras(char *palabras);
//Declaramos variables


#endif
