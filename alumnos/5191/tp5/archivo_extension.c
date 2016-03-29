#include "http_worker.h"

char *archivo_extension(char *resource){
	char buffer[RES_LEN];
	memset(buffer,0,sizeof(buffer));
	char *ext = NULL;
	char *validar_punto = NULL;

	strncpy(buffer,resource,strlen(resource));

	validar_punto = strchr( buffer, '.' ); 
	
	if (validar_punto == NULL){
		ext = NULL;
	} else {
		ext = strtok(buffer, ".");
		ext = strtok(NULL, " ");
	}
	
	return ext;
} // fin funcion