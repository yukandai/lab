#include <stdio.h>
#include <unistd.h>
#include <string.h>

int
main (int argc, char **argv)
{
	int leer = 1, espacio = 0, letra= 0;
	char buff[1]; 
	char mensaje1[20] = "El buffer tiene: ";
    char mensaje2[20] = "El anterior es: ";
    char ant[1] = {'\0'};
    
    printf("Sizeof:%d\n", sizeof mensaje1);
    printf("Strlen:%d\n", strlen(mensaje1));

	while ((leer = read(0, buff, 1))) {
		write(1,mensaje1, strlen(mensaje1));
        write(1, buff, 1);
        write(1, "\n", 1);
		write(1, mensaje2, strlen(mensaje2)); 
        write(1, ant, 1);
        write(1, "\n", 1);
		*ant = *buff;
		if (buff[0] == '\n') {
			espacio++;
		}
	}
	printf("Hay %d espacios\n", espacio);


	return 0;
}
