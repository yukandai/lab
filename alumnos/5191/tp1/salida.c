#include "salida.h"

void nombreSalida(char **nombre){

	*nombre = malloc(sizeof(char) * strlen(optarg));
	strncpy(*nombre, optarg, strlen(optarg));
	
}
