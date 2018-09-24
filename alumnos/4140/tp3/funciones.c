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
    int  nread, i, cant=0;
    char buffer[100];

    char *temp      = (char *) malloc(128 * sizeof(char));
    char *palabra   = (char *) malloc(128 * sizeof(char));
    int  *resultado = (int *) malloc(128 * sizeof(int));

    close(fdh[1]);

    while ((nread = read(fdh[0], buffer, sizeof buffer)) > 0)
    {
        for (i=0; i<nread; i++)
        {
            /* 10=nueva linea - 32=espacio - 44=, - 46=. - 174=« */
            if (buffer[i] == 10 || buffer[i] == 32 || buffer[i] == 44 || buffer[i] == 46 || buffer[i] == 174)
            {
                if (strlen(palabra) > 0)
                {
                    /* palabra armada */
                    cant = strlen(palabra);
                    resultado[cant]++;
                    *(palabra) = NULL;
                    //printf("\ncantidad de letras: %d", cant);
                    //printf("\ncantidad de palabras con esas letras: %d", resultado[cant]);
                }
            }
            else
            {
                /* armamos la palabra */
                *(temp) = buffer[i];
                strcat(palabra, temp);
            }
        }
    }

    /* Mostramos el resultado */
    for (i=0; i<sizeof(resultado); i++)
    {
        /** TODO: no muestra (se alamcena?) el total de los resultados */
        printf("\n [%d] palabras con [%d] letras \n", resultado[i], i);
    }

    free(temp);
    free(palabra);
    free(resultado);
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

    char *temp            = (char *) malloc(128 * sizeof(char));
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
            /* 10=nueva linea - 32=espacio - 44=, - 46=. - 174=« */
            if (buffer[i] == 10 || buffer[i] == 32 || buffer[i] == 44 || buffer[i] == 46 || buffer[i] == 174)
            {
                /* NO FORMA LA PALABRA */
                if (strlen(palabra_formada) > 0)
                {
                    /** TODO: ingresa caracteres raros, las palabras las forma y analiza bien */

                    /* palabra armada, la analizo y la concateno a la salida */
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
