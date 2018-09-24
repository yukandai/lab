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
#include <sys/stat.h>
#include <fcntl.h>
#include <wait.h>
#include "funciones.h"

int main(int argc, char *argv[])
{
    char *palabras = "sherlock";

    int   opt;
    int   nreads;
    int   fdfile;

    char  buff[100];
    char  *file_name = NULL;

	char  *addr;
    sem_t *semaforo;

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

	if ( (addr = mmap(NULL, sizeof (char), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0)) < 0 )
	{
		perror("mmap()");
		exit(EXIT_FAILURE);
	}

	semaforo = (sem_t*) addr;
	sem_init(semaforo, 1, 1);

    switch (fork())
    {
        case 0:
            /* HIJO 1 */
			sem_wait(semaforo);
            contar_palabras(addr);
			sem_post(semaforo);
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
				sem_wait(semaforo);
                reemplazar_palabra(addr, palabras);
				sem_post(semaforo);
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
						sem_wait(semaforo);
                        write(addr, buff, nreads);
						sem_post(semaforo);
                    }
                }
                else
                {
                    /* Leemos desde un archivo */
                    if (fdfile = open(file_name, O_RDONLY))
                    {
                        while ((nreads = read(fdfile, buff, sizeof buff)) > 0)
                        {
							sem_wait(semaforo);
		                    write(addr, buff, nreads);
							sem_post(semaforo);
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

	if ( munmap(addr, sizeof (char)) < 0 )
    {
        perror("munmap()");
        exit(EXIT_FAILURE);
    }
	
    free(file_name);
	wait(NULL);

    return 0;
}
