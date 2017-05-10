#include "tp2.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define debug 0

int countWords(char *buffer) {
	
	int count = 0;
	char *token, *ptr;

	char delimiter[] = " \n\t\r";
	
	token = strtok_r(buffer,delimiter,&ptr);
	if (!token) {
		return 0;
	}
	count++;
	if (debug) printf("\nToken[%d]: %s",count,token);

	while ( (token=strtok_r(NULL,delimiter,&ptr)) != NULL ) {
		count++;
		if (debug) printf("\nToken[%d]: %s",count,token);
	}

	if (debug) printf("\nTokens totales en la pasada: %d",count);
	return count;
}
