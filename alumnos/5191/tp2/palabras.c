#include "palabras.h"

void obtenerPalabras(char **palabras){

	*palabras = malloc(sizeof(char) * strlen(optarg));
	strncpy(*palabras, optarg, strlen(optarg));
	
}

/*int obtenerCantidadPalabras(char *palabras){
	int cantidad;
	char *dimension = NULL;
	char delimitador[] = ",";

	dimension = strtok(palabras,delimitador);

	while (dimension != NULL){
		cantidad++;		
		dimension = strtok(NULL,delimitador);
	}

	return cantidad;
}
*/
