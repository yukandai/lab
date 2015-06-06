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
char  *palabras(char *palabras, int cont);
//Declaramos variables
char *palabra1f;   
char *palabra2f;   
char *palabra3f;   
#endif
