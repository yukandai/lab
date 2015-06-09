#include "nieto.h"
#include "palabras.h"
#include "sigusr.h"


void funcionNieto(int nieto_lee_hijo,int nieto_escribe_padre, char *palabras){

	int leidos;
	
	int cantidad = 0;	
	int espacio = 0;

	char buffer[10];
	memset(buffer,0,sizeof(buffer));

	char *dimension = NULL;
	char delimitador[] = ",";
	char delimitador2[] = " \n\t";
	char *result = NULL;
	
	char *palabrasFiltrar[20] ={};// {palabras}; // hay q ponerle la cantidad  --- no me deja setear palabrasfiltrar[cantidad] :(
	char *frase = NULL;
	char buffer2[1500];
	memset(buffer2,0,sizeof(buffer2));
	char *palabrasTmp = NULL;

	palabrasTmp = palabras;
	//cantidad = obtenerCantidadPalabras(palabras);
	

	dimension = strtok(palabrasTmp,delimitador);
	while (dimension != NULL){
		palabrasFiltrar[cantidad] = dimension;
	
		dimension = strtok(NULL,delimitador);
		cantidad++;
	}
	

	/*printf("x %s\n",palabrasFiltrar[0]);
	printf("y %s\n",palabrasFiltrar[1]);
	printf("z %s\n",palabrasFiltrar[2]);
	printf("can %d\n",cantidad);
	*/
	while ((leidos = read(nieto_lee_hijo, buffer,10)) > 0){
		buffer[leidos] = '\0';

		result = strtok(buffer,delimitador2);

		while (result != NULL){

			frase = parsearFraseSIGUSR2(result,palabrasFiltrar,cantidad);
	
			result = strtok(NULL,delimitador2);

			strncat(buffer2,frase,strlen(frase)); // agrego cada palabra para luego formar el texto filtrado

			espacio = (int)strlen(frase);

			if (espacio != 0){
				strncat(buffer2," ",1);
			}
		}


	}
	// escribo en pipe 2
		write(nieto_escribe_padre,buffer2,strlen(buffer2));	
		write(nieto_escribe_padre,"\n",1);

}
