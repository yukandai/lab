#ifndef _HIJO_H_
#define _HIJO_H_

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

		
		
		void funcionHijo(int hijo_lee_padre,int hijo_escribe_escribe);
		void senal(int nro);
		char *escribirEnPadre (char *buffer, int la);		
		
  
#endif
