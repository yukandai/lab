#include "parser.h"

char *filtrarPalabra (char *palabra){

	int flag = 0;

	char *palabrafiltrada1 = "saludos";
	char *palabrafiltrada2 = "wii";
	char *palabrafiltrada3 = "mono";

	//printf ("el mensaje es: %s\n",mensaje);

	//printf("cantidad de caracteres del mensaje %d\n",(int)strlen(mensaje));


if  ((strcmp(palabra,palabrafiltrada1) == 0) || (strcmp(palabra, palabrafiltrada2) == 0) || (strcmp(palabra,palabrafiltrada3) == 0)) {
	flag = 1;
}

	if (flag){
		//printf ("flag: %d\n",flag);
		palabra = "";
	}
 
	

return palabra;

}
