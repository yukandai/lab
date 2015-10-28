#include "funcNieto.h"
#include "global.h"

char * funcionNieto(char *message, char *filter){
	char *buffer;
  	char *p;
	
	if(!(p = strstr(message, filter)))
		return message;
	
	buffer = (char*)malloc(strlen(message)-strlen(filter));

	strncpy(buffer, message, p-message);

	sprintf(buffer+(p-message), "%s", p+strlen(filter));

	return funcionNieto(buffer, filter);
	
}