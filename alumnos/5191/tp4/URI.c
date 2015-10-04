#include "http_worker.h"

char *URI (char *buffer,char *archivo, char *mime, char *ruta){

	char *buffer2 = malloc(1024*sizeof(char));
	char *buffer3 = malloc(256*sizeof(char));
	char *buffer4 = malloc(256*sizeof(char));

	char *version = malloc(256*sizeof(char));
	//char *cabecera = malloc(256*sizeof(char));
	
	char *archivo2;

	char extensionaux[256];
	memset(extensionaux,0,sizeof(extensionaux));
	
	char *extension = malloc(256*sizeof(char));

	strncpy(buffer2,buffer,strlen(buffer));

	printf("---------------------------------------\n");
	printf ("%s\n",buffer);
	printf("---------------------------------------\n");
	
	strtok_r(buffer2," ",&version);
	//printf("El metodo es: %s\n",buffer2); // get | post
	strtok_r(NULL," ",&version);

	strtok(version,"");  // parseo solo HTTP/1.1
	strtok(version,"\n");

	
	buffer3 = strtok(buffer,"/"); 
	buffer3 = strtok(NULL," "); 
	archivo2 = buffer3; // archivo2 = index.html o cualquier otro pedido 

	/*printf ("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2\n");
	printf ("%s\n",archivo2); // nomb
	printf ("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@2\n");*/

	// podria poner una redireccion si no existe el archivo solicitado

	strncpy(extensionaux,archivo2,strlen(archivo2));

	buffer4 = strtok(extensionaux,".");
	buffer4 = strtok(NULL," ");
	extension = buffer4;

	printf("archivo2: %s\n",archivo2);
	printf("version: %s\n",version);
	printf("Extension: %s\n",extension);



	return buffer2;
}