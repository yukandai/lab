/******************************************************************/
/**                            TP 3                              **/
/******************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>

#include "funciones.h"

int main(int argc, char *argv[])
{
    char *words[] = {"Sherlock","Holmes"};

    int  opt;
    //int  nreads;
    int  fdfile = STDIN_FILENO;
    //char buff[100];

    char *ptr_memo;
    sem_t *sem1, *sem2;

    while ((opt = getopt(argc, argv, "i:")) > 0)
    {
        switch (opt)
        {
        case 'i':
            fdfile = abrir_archivo(optarg);
            break;
        default:
            printf("Modo de uso: \n cat file | ./tp3 \n ./tp3 -i [archivo] \n");
            return 0;
        }
    }

    /* Creamos el espacio de memoria compartida */
    if ( (ptr_memo = mmap(NULL, sizeof (char *), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0)) < 0 )
    {
        perror("mmat()");
        return -1;
    }

	sem1 = (sem_t *) ptr_memo + sizeof sem1;
	sem2 = sem1 + sizeof sem2;

	/* Inicializo los semaforos */
	sem_init(sem1,1,0);
	sem_init(sem2,1,0);

    switch (fork())
    {
    case 0:
        /* HIJO 1 */
        contar_palabras(ptr_memo, "Soy el hijo 1\n");
        sem_post(sem1);
        sem_wait(sem2);
        return 0;
    case -1:
        /* ERROR */
        perror("fork_1()");
        return -1;
    default:
        /* PADRE */

        switch (fork())
        {
        case 0:
            // HIJO 2
            reemplazar_palabra(ptr_memo, words, "Soy el hijo 2\n");
			sem_post(sem1);
			sem_wait(sem2);
            return 0;
        case -1:
            // ERROR
            perror("fork_2()");
            return -1;
        default:
            /* PADRE */

            //while ((nreads = read(fdfile, buff, sizeof buff)) > 0)
            //{
				sem_wait(sem1);
				saludo("Soy el padre\n");
				// write(ptr_memo, buff, nreads);
				sem_post(sem2);
            //}
        }
    }

	wait(NULL);
    return 0;
}
