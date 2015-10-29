#include "http_worker.h"

char *archivo_extension(char *resource){
	char buffer[RES_LEN];
	memset(buffer,0,sizeof(buffer));
	char *ext = NULL;
	char *validar_punto = NULL;

	strncpy(buffer,resource,strlen(resource));

	validar_punto = strchr( buffer, '.' ); 
	if (validar_punto == NULL){
		ext = "error";
	} else {
		ext = strtok(buffer, ".");
		//printf("\n111--------%s\n",ext);
		ext = strtok(NULL, " ");
		//printf("\n--------%s\n",ext);
	}
	
	return ext;
} // fin funcion