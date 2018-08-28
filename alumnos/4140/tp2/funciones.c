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

void agregar_al_registro(char *pal, int *reg)
{
    int largo; //, i;

    largo = strlen(pal);

    printf("PALABRA: %s , LARGO: %d\n", pal, largo);

    *reg = largo;

    /*for(i=1; i<sizeof reg; i++)
    {
        if(reg[i] == largo)
        {
            // Ya esta el largo de palabra, solo incremento el contador
        }
        else
        {
            // NO esta el largo de palabra, lo agrego y la cantidad
        }
    }*/
}

/* Calcula la cantidad de palabras de N caracteres */
void armar_palabra(int *fdh)
{
    int nread, i, cant = 0;
    char buffer[100];

    char *temp = (char *) malloc(128 * sizeof(char));
    char *palabra = (char *) malloc(128 * sizeof(char));

    int *registro = (int *) malloc(sizeof(int));

    close(fdh[1]);

    while ((nread = read(fdh[0], buffer, sizeof buffer)) > 0)
    {
        for (i=0; i<nread; i++)
        {
            /* 10=nueva linea / 32=espacio / 44=, / 46=. */
            if (buffer[i] != 10 && buffer[i] != 32 && buffer[i] != 44 && buffer[i] != 46)
            {
                *(temp) = buffer[i];
                strcat(palabra, temp);
            }
            else
            {
                if (temp > 0)
                {
                    /* Ya tenermos la palabra armada. Contamos los caracteres y armamos el registro */
                    agregar_al_registro(palabra, &registro);
                    //printf("REGISTRO: %d\n", registro);

                    /* warning: assignment makes integer from pointer without a cast [-Wint-conversion] */
                    *(palabra) = NULL;
                }

                *(temp) = buffer[i];
            }
        }
    }

    /* TODO: mostrar resultado */

    free(temp);
    free(palabra);
}

/** Devuelve la palabra en mayusculas si es una de las palabras a ser convertida */
/*char *to_uppercase(char *word, char *palabra)
{
    int i;
    int flag = 0;
    char *uppercase = (char *) malloc(128 * sizeof(char));

    size_t result_1, result_2;

    result_1 = strlen(palabra);
    result_2 = strlen(word);

    // si son de la misma longitud, comparamos las cadenas
    if ((result_1 == result_2) && result_2 > 0)
    {
        if (strncmp(word, palabra, strlen(word)) == 0)
        {
            //printf("-------------- CONVERSION: %s -----------------\n", palabra);
            //printf("-------------- PALABRA: %s -----------------\n\n", word);
            flag = 1;
            // warning: assignment makes pointer from integer without a cast [enabled by default]
            // (uppercase) = toupper(*word);
        }
    }

    //free(uppercase);

    if (flag == 1)
        return uppercase;
    else
        return word;
}*/

char *revisar_palabra(char *pal, char *reservada)
{
    int i;
	int flag = 0;
	char *uppercase = (char *) malloc(128 * sizeof(char));

	if (strlen(reservada) == strlen(pal))
	{
	    if (strncmp(pal, reservada, strlen(pal)) == 0)
		{
	        flag = 1;
	    }
	}

    if (flag == 1)
	{
		for (i=0; i<=strlen(pal); i++)
		{
			uppercase[i] = toupper(pal[i]);
		}
		return uppercase;
    }
	else
	{
        return pal;
    }
}

int openFile(char *file_name)
{
    return open(file_name, O_CREAT | O_RDWR | O_APPEND, 0777);
}

/** Analiza un buffer, formando palabras para luego mandarlas a ser analizadas segun una funcion */
char *revisar_linea(char *line, int length, char *pal_reservada)
{
    int i, fd;

    char *temp = (char *) malloc(128 * sizeof(char));
    char *palabra = (char *) malloc(128 * sizeof(char));
	char *palabraChequeada = (char *) malloc(128 * sizeof(char));

	/* FORMA LA PALABRA */
	for (i=0; i<length; i++)
    {
        /* 10=nueva linea / 32=espacio / 44=, / 46=. */
        if (line[i] != 10 && line[i] != 32 && line[i] != 44 && line[i] != 46)
        {
            *(temp) = line[i];
            strcat(palabra, temp);
        }
        else
        {
            if (temp > 0)
            {
                /* Ya tenermos la palabra armada. Contamos los caracteres y armamos el registro */
				palabraChequeada = revisar_palabra(palabra, pal_reservada);
				//printf("palabra chequeada: %s\n", palabraChequeada);
				//palabraChequeada[strlen(palabraChequeada)] = line[i];

				if (fd = openFile("resultado.txt"))
				{
                	write(fd, palabraChequeada, strlen(palabraChequeada));
					//write(fd, temp, strlen(temp));
                }
				else
				{
                    perror("open");
                    exit(EXIT_FAILURE);
                }

                /* warning: assignment makes integer from pointer without a cast [-Wint-conversion] */
                *(palabra) = NULL;
            }

            *(temp) = line[i];
        }
    }

	//free(temp);
    //free(word);
	//free(palabraChequeada);
  
	return temp;
}

void reemplazar_palabra(int *fdh, char *palabra)
{
    int nread;
    char *line;
    char buffer[100];

    close(fdh[1]);

    while ((nread = read(fdh[0], buffer, sizeof buffer)) > 0)
    {
        //write(STDOUT_FILENO, buffer, nread);
        line = revisar_linea(buffer, nread, palabra);
        //write(STDOUT_FILENO, line, sizeof line);
    }
}