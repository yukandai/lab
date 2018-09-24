/******************************************************************/
/**                            TP 3                              **/
/******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <fcntl.h>

#include "funciones.h"

int main(int argc, char *argv[])
{
    //char *word = "argentina";

    int opt;
    //int nreads;
    int fdfile;
    //int fdh1[2];
    //int fdh2[2];
    int fdmem;

    char buff[100];
    char *file_name = NULL;

    while ((opt = getopt(argc, argv, "i:")) != -1)
    {
        switch (opt)
        {
            case 'i':
                file_name = optarg;
                break;
            default:
                printf("Modo de uso: \n cat file | ./tp2 \n ./tp2 -i [archivo] \n");
                return 0;
        }
    }

    /*if (pipe(fdh1) < 0)
    {
        perror("pipe(fdh1)\n");
        exit(EXIT_FAILURE);
    }*/

	/* Open physical memory */
	fdmem = shm_open("Physical", O_RDWR, 0777);

	if (fdmem < 0)
	{
		perror("shm_open()\n");
        exit(EXIT_FAILURE);
	}

    switch (fork())
    {
        case 0:
            /* HIJO 1 */
            contar_palabras(fdh1);
            return 0;
        case -1:
            /* ERROR */
            perror("fork_1()");
            exit(EXIT_FAILURE);
        default:
            /* PADRE */

            if (pipe(fdh2) < 0)
            {
                perror("pipe(fdh2)\n");
                return -1;
            }

            switch (fork())
            {
            case 0:
                /* HIJO 2 */
                reemplazar_palabra(fdh2, word);
                return 0;
            case -1:
                /* ERROR */
                perror("fork_2()");
                exit(EXIT_FAILURE);
            default:
                /* PADRE */

                if (file_name == NULL)
                {
                    /* Leemos desde pantalla */
                    while ((nreads = read(STDIN_FILENO, buff, sizeof buff)) > 0)
                    {
                        close(fdh1[0]);
                        close(fdh2[0]);
                        write(fdh1[1], buff, nreads);
                        write(fdh2[1], buff, nreads);
                    }
                }
                else
                {
                    /* Leemos desde un archivo */
                    if (fdfile = open(file_name, O_RDONLY))
                    {
                        /* Cierro las tuberias para lectura  */
                        close(fdh1[0]);
                        close(fdh2[0]);

                        while ((nreads = read(fdfile, buff, sizeof buff)) > 0)
                        {
                            /* Escribo en las tuberias de cada hijo */
                            write(fdh1[1], buff, nreads);
                            write(fdh2[1], buff, nreads);
                        }
                    }
                    else
                    {
                        perror("open_file()");
                        exit(EXIT_FAILURE);
                    }
                }
            }
    }

    free(file_name);

    return 0;
}
