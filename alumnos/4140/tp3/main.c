/******************************************************************/
/**                            TP 3                              **/
/******************************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>
#include "funciones.h"

int main(int argc, char *argv[])
{
    char *palabras = "sherlock"; //char *palabras[] = {"sherlock","holmes"};

    int  opt;
    int  nreads;
    int  fdfile = STDIN_FILENO;

    char buff[100];
    char *addr;

    while ((opt = getopt(argc, argv, "i:")) != -1)
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

    /* Creamos el espacio de memoria compartida */
	if ( (addr = mmap(NULL, sizeof (char *), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0)) < 0 )
    {
        perror("mmat()");
        exit(EXIT_FAILURE);
    }

	switch (fork())
    {
    case 0:
        /* HIJO 1 */
        contar_palabras(addr);
        return 0;
    case -1:
        /* ERROR */
        perror("fork_1()");
        exit(EXIT_FAILURE);
    default:
        /* PADRE */

        switch (fork())
        {
        case 0:
            /* HIJO 2 */
            reemplazar_palabra(addr, palabras);
            return 0;
        case -1:
            /* ERROR */
            perror("fork_2()");
            exit(EXIT_FAILURE);
        default:
            /* PADRE */

			while ((nreads = read(fdfile, buff, sizeof buff)) > 0)
            {
                write(addr, buff, nreads);
            }
        }
    }

    wait(NULL);

    return 0;
}
