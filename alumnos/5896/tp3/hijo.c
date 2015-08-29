#include "parser.h"
#include "hijo.h"
#include "main.h"

void hijo(){

	memset(filtrado, 0, sizeof filtrado);
	//char palabra[1024]="hola";
	strcpy(mensajeafiltrar,orgmensaje);

	//empieza el filtrado
	token = strtok(mensajeafiltrar, " \n\t");
	m = strcmp(token,palabra1f);
	n = strcmp(token,palabra2f);
	p = strcmp(token,palabra3f);
	if (m==0 || n==0 || p==0) {
		token="****";
	}  
	strcat(filtrado,token);
	strcat(filtrado," ");
	while( (token = strtok( NULL, " \n\t" )) != NULL ){
		m = strcmp(token,palabra1f);
		n = strcmp(token,palabra2f);
		p = strcmp(token,palabra3f);
		if (m==0 || n==0 || p==0){
			token="****";
		}
		strcat(filtrado,token);
		strcat(filtrado," ");
	}
	char *pfiltrado=filtrado;
	printf("soy %d  hijo de %d  mostrando el mensaje original: %s\n",getpid(),getppid(),orgmensaje);
	//	printf("%s soy el hijo %d de %d \n",filtrado,getpid(),getppid());
	//	printf("%s soy el hijo %d de %d a travez del puntero \n",pfiltrado,getpid(),getppid());

	//sobrescribo el mensaje filtrado a la memoria compartida
	strcpy(orgmensaje,pfiltrado);	






}
