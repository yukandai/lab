#include "parser.h" 
#include "salida.h"

int main (int argc, char **argv){

int leido;
char opcion; 
char *archivo = NULL;
char buffer[1500];
//bzero(buffer,1500); // luego le pongo memset
memset(buffer,0,sizeof(buffer));

char delims[] = " \n\t";
char *result = NULL;
char *palabra = NULL;
char buffer2[1500];
//bzero(buffer2,1500);
memset(buffer2,0,sizeof(buffer2));
int cantidad = 0;


	while ((opcion = getopt (argc, argv, "o:h")) != -1){
		switch (opcion){
			case 'o':
				nombreSalida(&archivo);						
				break;
			case 'h': 
				Ayuda();
				return -1; // asi se deja de ejecutar
				break;
		}
	}


	while ((leido = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0){

		result = strtok(buffer,delims); // innecesario strtok_r

		while (result != NULL){
//			
			palabra = filtrarPalabra(result);
			result = strtok(NULL,delims);

			strcat(buffer2,palabra); // agrego cada palabra para luego formar el texto filtrado
			cantidad = (int)strlen(palabra);

			if (cantidad != 0){ // agrego un espacio si la palabra no esta en la blacklist
				strcat(buffer2," ");
			} 


		}


		mensajeFiltrado(buffer2,archivo);
		
	}
 
return 0; 
} 
