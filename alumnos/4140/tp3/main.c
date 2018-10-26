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
	//char *words[] = {"Sherlock","Holmes"};

    int  opt;
	//int  nread;
    int  fdfile = STDIN_FILENO;
    char buffer[100];
	char *addr;
	int  *leer;
	int  *nread;

    sem_t *sempa, *semh1, *semh2;

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
    if ( (addr = mmap(NULL, 100, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0)) < 0 )
    {
        perror("mmat_1()");
        return -1;
    }

    if ( (leer = mmap(NULL, (sizeof(int)), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0)) < 0 )
    {
        perror("mmat_2()");
        return -1;
    }

	if ( (nread = mmap(NULL, (sizeof(int)), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0)) < 0 )
    {
        perror("mmat_3()");
        return -1;
    }

	/* Inicializamos los semaforos */
	sempa = (sem_t *) addr + sizeof sempa;
	semh1 = sempa + sizeof semh1;
	semh2 = sempa + sizeof semh2;

	sem_init(sempa,1,1);
	sem_init(semh1,1,0);
	sem_init(semh2,1,0);

    switch (fork())
    {
    case 0:
        /* HIJO 1 */
        while (*leer == 0)
        {
			sem_wait(semh1);
			//contar_palabras(addr);
			write(STDOUT_FILENO, addr, *nread);
			sem_post(semh2);
		}
		sem_post(semh2);
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
            /* HIJO 2 */
            while (*leer == 0)
			{
				sem_wait(semh2);
				//reemplazar_palabra(addr, words);
				sem_post(sempa);
			}
			sem_post(sempa);
            return 0;
        case -1:
            /* ERROR */
            perror("fork_2()");
            return -1;
        default:
            /* PADRE */
            while ((*nread = read(fdfile, buffer, sizeof buffer)) > 0)
			{
				sem_wait(sempa);
				memcpy(addr, buffer, *nread); // strcpy(addr, buffer);
				//write(STDOUT_FILENO, addr, *nread);
				sem_post(semh1);
			}
			*leer = 1;
			sem_post(semh1);
        }
    }

	wait(NULL);
    return 0;
}
