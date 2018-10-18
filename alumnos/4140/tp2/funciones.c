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

void contar_palabras(int *fdh)
{
    int  i;
    int  cant = 0;
    int  nread;
    char buffer[100];

    char *temp    = (char *)malloc(128*sizeof(char));
    char *palabra = (char *)malloc(128*sizeof(char));

    /* TEST */
    int j;
    int incrementada = 0;
    int palabras_formadas = 0;
    int *cant_letras   = (int *)malloc(1940*sizeof(int));
    int *cant_palabras = (int *)malloc(1940*sizeof(int));

    close(fdh[1]);

    while ((nread = read(fdh[0], buffer, sizeof buffer)) > 0)
    {
        for (i=0; i<nread; i++)
        {
            /* Si el caracter NO es una letra */
            if ( (buffer[i] >= 0 && buffer[i] <= 64) || (buffer[i] >= 91 && buffer[i] <= 96) || (buffer[i] >= 123 && buffer[i] <= 127) || buffer[i] == 174 || buffer[i] == 175 )
            {
                /* Chequeamos si hay una palabra formada */
                if (strlen(palabra) > 0)
                {
					palabras_formadas++;
                    cant = strlen(palabra);
                    incrementada = 0;

					//printf("Palabra: %s [%d letras] [TOTAL %d palabras]\n", palabra, cant, palabras_formadas);

					/* Me fijo si esa cantidad de letras ya esta guardada */
					for(j=1; j<palabras_formadas; j++)
					{
						if (cant_letras[j] == cant)
						{
							/* Ya esta esa cantidad de letras, entonces incremento el contador */
							cant_palabras[j]++;
							incrementada=1;
							break;
						}
					}

					if (incrementada == 0)
					{
						/* No hay palabras de ese largo, la ingreso y seteo la cantidad */
						cant_letras[palabras_formadas] = cant;
						cant_palabras[palabras_formadas]++;
					}

					/* "Blanqueamos" la variable */
                    memset(palabra,0,128*sizeof(char));
                }
            }
            else
            {
                /* Guardamos el caracter para armar la palabra */
                *temp = buffer[i];
                strcat(palabra, temp);
            }
        }
    }

    /* Mostramos el resultado */
    for (i=1; i<palabras_formadas; i++)
    {
        if ( (*(cant_palabras+i) != 0) && (*(cant_letras+i) != 0) )
        {
            printf("\n [%d] palabras con [%d] letras \n", *(cant_palabras+i), *(cant_letras+i));
        }
    }

    free(temp);
    free(palabra);
    free(cant_letras);
    free(cant_palabras);
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

    char *temp            = (char *)malloc(128 * sizeof(char));
    char *palabra_formada = (char *)malloc(128 * sizeof(char));
    char *linea_revisada  = (char *)malloc(128 * sizeof(char));

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
            /* Si el caracter NO es una letra */
            if ( (buffer[i] >= 0 && buffer[i] <= 64) || (buffer[i] >= 91 && buffer[i] <= 96) || (buffer[i] >= 123 && buffer[i] <= 127) || buffer[i] == 174 || buffer[i] == 175 )
            {
                /* NO FORMA LA PALABRA */
                if (strlen(palabra_formada) > 0)
                {
                    /* Palabra armada, la analizo y la concateno a la salida */
                    strcat(linea_revisada, revisar_palabra(palabra_formada, palabra_a_remplazar));
                    /* "Blanqueamos" la variable */
                    memset(palabra_formada,0,128*sizeof(char));
                }

                /* es un signo, directamente lo concateno a la salida */
                *temp = buffer[i];
                strcat(linea_revisada, temp);
            }
            else
            {
                /* es una letra, armo la palabra */
                *temp = buffer[i];
                strcat(palabra_formada, temp);
            }
        }

        write(fd_file, linea_revisada, strlen(linea_revisada));
        /* "blanqueamos" la variable */
        memset(linea_revisada,0,128*sizeof(char));
    }

    free(temp);
    free(palabra_formada);
    free(linea_revisada);
}
