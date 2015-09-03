#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>

#include "funhijo.h"



int main(int argc, char **argv) {

    pid_t hijo;
    sem_t *sem_1, *sem_2;
    char *mem;
    int *membits;
    char cen1[1000];
    char buff[100];
    int bits = 0;
    int opt, countflag = 0;
    int leido;

    extern char *optarg;
    extern int optind, opterr, optopt;


    while ((opt = getopt(argc, argv, "p:h")) != -1) {
        switch (opt) {
            case 'p':

                countflag = 1;

                strncat(cen1, optarg, strlen(optarg));
                strncat(cen1, "\0", 1);

                break;

            case 'h':

                write(1, "Uso: ./tp3 -p [PALABRA] \n\n Censura la palabra indicada y las reemplaza por caracteres ? en el texto de entrada\n\n El programa lee la entrada estándar (stdin) por lo que se puede utilizar pipes, \n al estilo 'cat texto.txt | ./tp3 -p palabra'. \n\n Si no se da la palabra a censurar el programa no se ejecuta. \n\n --\n", 313);

                break;

/*            case 'c':
                sem_close(sem_1);
                sem_close(sem_2);
                sem_unlink("/sem_2");
                sem_unlink("/sem_1");

                break; */

            default:

                write(1, "Uso: ./tp3 -p [PALABRA] \n\n Censura la palabra indicada y las reemplaza por caracteres ? en el texto de entrada\n\n El programa lee la entrada estándar (stdin) por lo que se puede utilizar pipes, \n al estilo 'cat texto.txt | ./tp3 -p palabra'. \n\n Si no se da la palabra a censurar el programa no se ejecuta. \n\n --\n", 313);

                break;
        }
    }


    if (countflag == 1) {


        mem = mmap(NULL, 4096, PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);

        membits = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);



        printf("\nCreando semáforos .....\n");

        /* comprueba si ya existe el semáforo y sino lo crea desbloqueado (1)*/
        sem_1 = sem_open("/sem_1", O_CREAT, 0644, 1);
        if (sem_1 == (sem_t *) - 1) {
            perror("\nError creando semáforo padre");
        } else {
            printf("\nSemáforo del padre creado.\n");
        }
        /* comprueba si ya existe el semáforo y sino lo crea ya bloqueado (0)*/
        sem_2 = sem_open("/sem_2", O_CREAT, 0644, 0);
        if (sem_2 == (sem_t *) - 1) {
            perror("\nError creando semáforo hijo");
        } else {
            printf("\nSemáforo del hijo creado.\n");
        }

        hijo = fork();

        switch (hijo) {
            case -1:
                printf("\nerror creando el hijo\n");
                exit(0);
            case 0: /* En el hijo */
                
                sem_wait(sem_2); /* espera que el padre libere el semáforo */
                
                funhijo(mem, membits, cen1);
                                
                sem_post(sem_1); /* activa al padre */
                break;

            default: /*estamos en el padre  */
                printf("\nSoy el padre con PID:%d\n", getpid());

                sem_wait(sem_1); /* espera que el hijo libere el semáforo */

                printf("\nSoy el padre empiezo a leer el stdin .....\n");

                while ((leido = read(0, buff, sizeof buff)) > 1) {

                    strncat(mem, buff, leido);

                    bits = bits + leido;
                }

                *membits = bits;

                printf("\nSoy el padre termino de leer el stdin .....\n");

                sem_post(sem_2); /* activa al hijo */
        }

        sem_wait(sem_1);

        printf("\nSoy el padre leo la memoria compartida y la muestro por pantalla .....\n");

        memset(buff, 0, sizeof (buff));

        leido = 0;

        printf("\n -----\nSalida:\n");

        while (leido < bits) {
            strncpy(buff, mem + leido, 100);

            leido = leido + write(1, buff, sizeof buff);

        }
        /* libero semáforos */
        sem_close(sem_1);
        sem_close(sem_2);
        printf("\n -----\n\nSoy el padre espero que termine el hijo .....\n");
        wait(0); /* Esperar que acabe el hijo */

        printf("\nSoy el padre destruyo los semáforos y termino.....\n");
        sem_unlink("/sem_2");
        sem_unlink("/sem_1");

    }

    return 0;
}
