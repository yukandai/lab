#include "parser.h"

char *filtrarPalabra (char *palabra){

	int flag = 0;

	char *palabrafiltrada1 = "saludos";
	char *palabrafiltrada2 = "wii";
	char *palabrafiltrada3 = "mono";

	//printf ("el mensaje es: %s\n",mensaje);

	//printf("cantidad de caracteres del mensaje %d\n",(int)strlen(mensaje));


	if  ((strncmp(palabra,palabrafiltrada1,strlen(palabra)) == 0) || (strncmp(palabra, palabrafiltrada2,strlen(palabra)) == 0) || (strncmp(palabra,palabrafiltrada3,strlen(palabra)) == 0)) {
		flag = 1;
	}

	if (flag){
		//printf ("flag: %d\n",flag);
		palabra = "";
	}
 	
	return palabra;

}
