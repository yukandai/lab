#include "editMessage.h"

#define SIZE 1000

int main(int argc, char **argv){

	int option, fd, file = 0;
	char buff[SIZE];
	//char *fileName;
	//Manejo argumentos
	while ((option = getopt(argc, argv, ":o:h")) >= 0 ){
		switch (option){
            case 'o':
	        //guardo mensaje en otro archivo
				//file = 1;
				//fileName = optarg;
				file= open( optarg , O_RDWR | O_CREAT, 0777);

				if(file < 0 ){
					perror("open()");
					return -1;
				}

				break;

		    case 'h':
			//imprimo mensaje de ayuda
	        	printf("========================= TP 1 - Compu2 =========================\n\n");
	        	printf("Opciones de compilación:\n");
	        	printf("\t-$ cat mensaje.txt | ./tp1\n\t-$ cat mensaje.txt | ./tp1 -o mensaje-filtrado.txt\n\t-$ cat mensaje.txt | ./tp1 -h\n");
	        	printf("Para ejecurtar el programa debe ingregar el nombre del archivo \nque contenga el mensaje a analizar, luego | ./tp1 para mostrar\nel resultado por consola o el nombre del archivo que contiene el \nmensaje | ./tp1 -o nombre del archivo donde lo quiere guardar.\n\n");
	           	printf("=================================================================\n\n");
	           	return 0;

		    default: 
			//mensaje de error si ingresa otro comando
				printf("No se reconoce el comando, por favor ejecuta ./tp1 -h por ayuda\n");
				return 0;
		}
	}

	while((fd = read(0, buff, sizeof buff)) > 0 ){
		if(file)
			write(file, replace_filter(buff," hinchada "," "),fd);
		else
			write(1,replace_filter(buff," hinchada "," "),fd);
	}

	return 0;
}