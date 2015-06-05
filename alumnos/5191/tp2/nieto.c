#include "nieto.h"
#include "padre.h"

void funcionNieto(int nieto_lee_hijo,int nieto_escribe_padre){

	int leidos;
	char buffer[10];
	memset(buffer,0,sizeof(buffer));

	while ((leidos = read(nieto_lee_hijo, buffer,10)) > 0){
		buffer[leidos] = '\0';

		printf("bufffffff %s\n",buffer);
	}
	

}
//void funcionPadreNieto()
/*void funcionPadreNieto(){

}*/
