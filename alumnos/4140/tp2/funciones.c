/******************************************************************/
/**                         FUNCIONES                            **/
/******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/* Calcula la cantidad de palabras de N caracteres */
void contar_palabras(int *fdh)
{
    int  nread, i, cant = 0;
    char buffer[100];
    char *temp = (char *) malloc(128 * sizeof(char));
    char *palabra = (char *) malloc(128 * sizeof(char));
	char *linea_revisada  = (char *) malloc(128 * sizeof(char));

	char *longitudes  = (char *) malloc(128 * sizeof(char));
	
    close(fdh[1]);

    while ((nread = read(fdh[0], buffer, sizeof buffer)) > 0)
    {
        for (i=0; i<nread; i++)
		{
		    /* 10=nueva linea - 32=espacio - 44=, - 46=. */
	        if (buffer[i] != 10 && buffer[i] != 32 && buffer[i] != 44 && buffer[i] != 46)
			{
				if (palabra > 0)
				{
					/* palabra armada, analizo la cantidad de letras */
					cant = strlen(palabra);

					for(i=1; i<sizeof longitudes; i++)
					{
						if(longitudes[i] == cant)
						{
							// Ya esta el largo de palabra, solo incremento el contador
						}
						else
						{
							// NO esta el largo de palabra, lo agrego y la cantidad
						}
					}
					
					strcat(linea_revisada, palabra);
		            *(palabra) = NULL;
	            }

				/* es un signo, directamente lo paso a la linea */
				*(temp) = buffer[i];
            	strcat(linea_revisada, temp);
	        }
			else
			{
				/* es una letra, armo la palabra */
				*(temp) = buffer[i];
            	strcat(palabra, temp);
	        }
	    }

		//write(fd_file, linea_revisada, nread);
		*(linea_revisada) = NULL;
    }

    /* TODO: mostrar resultado */

    free(temp);
    free(palabra);
	free(linea_revisada);
}

char *revisar_palabra(char *pal, char *reservada)
{
    int  i;
	char *uppercase = (char *) malloc(128 * sizeof(char));

	if (strlen(reservada) == strlen(pal))
	{
	    if (strncmp(pal, reservada, strlen(pal)) == 0)
		{
			for (i=0; i<=strlen(pal); i++)
			{
				uppercase[i] = toupper(pal[i]);
			}
			return uppercase;
	    }
	}

	free(uppercase);

    return pal;
}

int abrir_archivo(char *file_name)
{
    return open(file_name, O_CREAT | O_RDWR | O_APPEND, 0777);
}

void reemplazar_palabra(int *fdh, char *palabra_a_remplazar)
{
	int  i;
	int  fd_file;
    int  nread;
    char buffer[100];

    char *temp = (char *) malloc(128 * sizeof(char));
    char *palabra_formada = (char *) malloc(128 * sizeof(char));
	char *linea_revisada  = (char *) malloc(128 * sizeof(char));
	
    close(fdh[1]);

	if ( (fd_file = abrir_archivo("resultado")) < 0 )
	{
        perror("open");
        exit(EXIT_FAILURE);
    }
	
    while ((nread = read(fdh[0], buffer, sizeof buffer)) > 0)
    {
	    for (i=0; i<nread; i++)
		{
		    /* 10=nueva linea - 32=espacio - 44=, - 46=. */
	        if (buffer[i] != 10 && buffer[i] != 32 && buffer[i] != 44 && buffer[i] != 46)
			{
				if (palabra_formada > 0)
				{
					/* palabra armada, la analizo y la concateno a la salida */
					//printf("palabra: %s, resultado: %s\n",palabra_formada,revisar_palabra(palabra_formada, palabra_a_remplazar));
	                strcat(linea_revisada, revisar_palabra(palabra_formada, palabra_a_remplazar));
		            *(palabra_formada) = NULL;
	            }

				/* es un signo, directamente lo concateno a la salida */
				*(temp) = buffer[i];
	            strcat(linea_revisada, temp);
	        }
			else
			{
				/* es una letra, armo la palabra */
				*(temp) = buffer[i];
            	strcat(palabra_formada, temp);
	        }
	    }

		write(fd_file, linea_revisada, nread);
		*(linea_revisada) = NULL;
    }

	free(temp);
    free(palabra_formada);
	free(linea_revisada);
}