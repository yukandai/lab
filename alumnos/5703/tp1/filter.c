#include "editMessage.h"

char * replace_filter(char *message, char *filter, char *replace){
	char *buffer;
  	char *p;
	
	if(!(p = strstr(message, filter)))  //busca 'filter' en 'message', si no esta devuelve NULL y entra al if sino devuelve a 'p' un puntero al comienzo de la subcadena 'filter'
		return message;

	buffer = (char*)malloc(strlen(message)+strlen(replace)-strlen(filter)+1);

	strncpy(buffer, message, p-message); //copia al buffer el mensaje hasta el filter (la posicion numero 'p-message')

	sprintf(buffer+(p-message), "%s%s", replace, p+strlen(filter)); //despues del buffer me va a pegar el 'replace' y el resto del mensaje sin el 'filter' 

	return replace_filter(buffer, filter, replace); //hago llamadas recursivas para reemplazar todos los filtros
	
}
