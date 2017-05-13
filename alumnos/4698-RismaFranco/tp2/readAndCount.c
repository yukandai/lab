#include "tp2.h"
#include "macros.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define debug 1

void readAndCount(configuration *conf, int readEnd, int writeEnd) {

	//Leo de readEnd y escribo en writeEnd
	//
	int nread=0;	
	char buff[1024];
	char result[8];
	int tokens = 0;

	while ( (nread=read(readEnd,buff,sizeof(buff))) > 0 ) {
			tokens += countWords(buff);	
	}
	if (debug) printf("Token result: %d\n",tokens);

	//Convertir el int a string
	snprintf(result,sizeof tokens,"%d",tokens);
	//result[strlen(result)] = '\0';
	
	if (debug) printf("%s cantidad de palabras en string: %s\n",__FILE__,result);
	if ( write(writeEnd,result,strlen(result)) < 0 ) {
		perror("write");
	}

	return;
}
