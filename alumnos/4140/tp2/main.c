/******************************************************************/
/**                            TP 2                              **/
/******************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#include "funciones.h"

int main(int argc, char *argv[])
{
    char *word = "argentina";

    int  opt;
    int  nreads;
    int  fdfile = STDIN_FILENO;
    int  fdh1[2];
    int  fdh2[2];
    char buff[100];

    while ((opt = getopt(argc, argv, "i:")) > 0)
    {
        switch (opt)
        {
        case 'i':
            fdfile = abrir_archivo(optarg);
            break;
        default:
            printf("Modo de uso: \n cat file | ./tp2 \n ./tp2 -i [archivo] \n");
            return 0;
        }
    }

    if (pipe(fdh1) < 0)
    {
        perror("pipe(fdh1)\n");
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

            close(fdh1[0]);
            close(fdh2[0]);

            while ((nreads = read(fdfile, buff, sizeof buff)) > 0)
            {
                write(fdh1[1], buff, nreads);
                write(fdh2[1], buff, nreads);
            }
        }
    }

    return 0;
}
