#include <unistd.h>
#include <stdio.h>
#include <string.h>
int
main (int argc, char **argv)
{
    char mensajeBuffer[17] = "El buffer tiene: ";
    char mensajeAnterior[16] = "El anterior es: ";
	char mensajePalabras[17] = "Palabras leidas: ";
    char mensajeOraciones[18] = "Oraciones leidas: ";
    char mensajeEspacios[22] = "Cantidad de espacios: ";
    char valores[3];
    char buffer[1];
	char anterior[1] = {'1'};
	int readed = 1, palabra = 0, oraciones = 0, espacios = 0;

    while (read(0, buffer, 1)) {
    	/*
        write(1,mensajeBuffer, strlen(mensajeBuffer));
        write(1, buffer, 1);
        write(1, "\n", 1);
		write(1, mensajeAnterior, strlen(mensajeAnterior)); 
        write(1, anterior 1);
        write(1, "\n", 1);
        */
        printf("El buffer tiene: %s y el anterior: %s\n", buffer, anterior);
        *anterior = *buffer;
/*	
        //Cuenta las palabras    
		if (*buffer == ' ' || *buffer == '.' || *buffer == ',' || *buffer == '(' || *buffer == ')' || *buffer == '\n') {
			palabra++;
			if (*anterior == ' ' || *anterior == '.' || *anterior == ',' || *anterior == '(' || *anterior == ')' || *anterior == '\n' || *anterior == '1') {
				palabra--;
			}
		}

        //Cuenta las oraciones
		if (*buffer == '.') {
			oraciones++;
			if (*anterior == '.' || *anterior == '1') {
				oraciones--;
			}
		}

        //Cuenta los espacios
    	if (*buffer == '\n') {
			espacios++;
		}

	
        *anterior = *buffer;
	*/
    }
    /*
    valores[0] = palabra;
    valores[1] = oraciones;
    valores[2] = espacios;
    //Imprimo las estadisticas
    write(1, mensajePalabras, strlen(mensajePalabras));
    write(1, valores[0], 1);
    write(1, "\n", 1);
    write(1, mensajeOraciones, strlen(mensajeOraciones));
    write(1, valores[1], 1);
    write(1, "\n", 1);
    write(1, mensajeEspacios, strlen(mensajeEspacios));
    write(1, valores[2], 1);
    write(1, "\n", 1);
    */
	return (0);	
}
