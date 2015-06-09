#ifndef _SIGUSR_H_
#define _SIGUSR_H_

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <sys/types.h>
	#include <ctype.h>
	#include <unistd.h>
	#include <sys/stat.h>
	#include <fcntl.h>
	#include <errno.h>
	#include <sys/wait.h>
	#include <signal.h>	

		
		int bandera;
		char *escribirEnPadreSIGUSR1 (char *buffer, int hijo_escribe_padre);		
		void senal(int signal);
		char *parsearFraseSIGUSR2(char *palabra,char *palabrasFiltrar[],int cantidad);
  
#endif
