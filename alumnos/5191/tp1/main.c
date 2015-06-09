#include "parser.h" 
#include "salida.h"

int main (int argc, char **argv){

	int leido;
	int cantidad = 0;

	char opcion; 
	char delims[] = " \n\t";
	char *archivo = NULL;
	char *result = NULL;
	char *palabra = NULL;

	char buffer[1500];
	memset(buffer,0,sizeof(buffer));
	char buffer2[1500];
	memset(buffer2,0,sizeof(buffer2));


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
			
			palabra = filtrarPalabra(result);
			result = strtok(NULL,delims);

			strncat(buffer2,palabra,strlen(palabra)); // agrego cada palabra para luego formar el texto filtrado
			cantidad = (int)strlen(palabra);

			if (cantidad != 0){ // agrego un espacio si la palabra no esta en la blacklist
				strncat(buffer2," ",1);
			} 

		}

		mensajeFiltrado(buffer2,archivo);
		
	}
 
	return 0; 
} 
