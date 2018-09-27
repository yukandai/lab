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

    int   opt;
    int   nreads;
    int   fdfile;

    char  buff[100];
    char  *file_name = NULL;

    int   memo;
    char  *addr;

    //int   s_init;
    //sem_t *semaforo;

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

    /* Creamos el espacio de memoria compartida */
    if ( (memo = shmget(IPC_PRIVATE, 4096, IPC_CREAT | 0600)) < 0 )
    {
        perror("shmget()");
        exit(EXIT_FAILURE);
    }

    /*if ( (s_init = sem_init(semaforo, 1, 0)) < 0 )
    {
        perror("sem_init()");
        exit(EXIT_FAILURE);
    }*/
    //semaforo = (sem_t*) addr;

    switch (fork())
    {
    case 0:
        /* HIJO 1 */

        /* Vinculamos la memoria comportida */
        if ( (addr = shmat(memo, 0, SHM_RDONLY)) < 0 )
        {
            perror("shmat()");
            exit(EXIT_FAILURE);
        }

        //sem_wait(semaforo);
        contar_palabras(addr);
        //sem_post(semaforo);

        if ( (shmdt(addr)) < 0 )
        {
            perror("shmdt()");
            exit(EXIT_FAILURE);
        }

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

            /* Vinculamos la memoria comportida */
            if ( (addr = shmat(memo, 0, SHM_RDONLY)) < 0 )
            {
                perror("shmat()");
                exit(EXIT_FAILURE);
            }

            //sem_wait(semaforo);
            reemplazar_palabra(addr, palabras);
            //sem_post(semaforo);

            if ( (shmdt(addr)) < 0 )
            {
                perror("shmdt()");
                exit(EXIT_FAILURE);
            }

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
                    //sem_wait(semaforo);
                    write(memo, buff, nreads);
                    //sem_post(semaforo);
                }
            }
            else
            {
                /* Leemos desde un archivo */
                if (fdfile = open(file_name, O_RDONLY))
                {
                    while ((nreads = read(fdfile, buff, sizeof buff)) > 0)
                    {
                        //sem_wait(semaforo);
                        write(memo, buff, nreads);
                        //sem_post(semaforo);
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
    wait(NULL);

    return 0;
}
