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

#include "main.h"
#include "comparar.h"



int main(int argc, char **argv) {

    char * result = (char*) calloc(1000, sizeof (char));

    char * strptr = (char*) calloc(1000, sizeof (char));

    char * aux = (char*) calloc(1000, sizeof (char));

    char * token = (char*) calloc(1000, sizeof (char));

    char * cen1 = (char*) calloc(1000, sizeof (char));

    extern char *optarg;
    extern int optind, opterr, optopt;


    while ((opt = getopt(argc, argv, "p:h:c")) != -1) {
        switch (opt) {
            case 'p':

                countflag = 1;

                strncat(cen1, optarg, strlen(optarg));
                strncat(cen1, "\0", 1);

                break;

            case 'h':

                write(1, "Uso: ./tp3 -p [PALABRA] \n\n Censura la palabra indicada y las reemplaza por caracteres ? en el texto de entrada\n\n El programa lee la entrada estándar (stdin) por lo que se puede utilizar pipes, \n al estilo 'cat texto.txt | ./tp3 -p palabra'. \n\n Si no se da la palabra a censurar el programa no se ejecuta. \n\n --\n", 313);

                break;

            case 'c':
                sem_close(sem_1);
                sem_close(sem_2);
                sem_unlink("/sem_2");
                sem_unlink("/sem_1");

                break;

            default:

                write(1, "Uso: ./tp3 -p [PALABRA] \n\n Censura la palabras indicada y las reemplaza por caracteres ? en el texto de entrada\n\n -s [NOMBRE DE ARCHIVO] Seleccionar el nombre del archivo fuente para censurar \n                        (Source), si se omite se lee el stdin. \n -f [NOMBRE DE ARCHIVO] Seleccionar el nombre del archivo destino para la cens\n                        ura, si se omite la salida sera por stdout. \n -2 [PALABRA]           Seleccionar una segunda palabra adicional para censurar. \n -3 [PALABRA]           Seleccionar una tercera palabra adicional para censurar. \n -h                     Ver este archivo de ayuda. \n\n Nota: Para usar el parametro -2 y -3 se necesita haber usado los parametros anteriores.\n\n", 696);

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
                printf("\nSoy el hijo con PID:%d\n\n", getpid());

                sem_wait(sem_2); /* espera que el padre libere el semáforo */

                printf("\nSoy el hijo y empiezo a leer la memoria compartida.....\n");

                bits = *membits;

                strncpy(aux, mem, bits);

                for (token = strtok(aux, delim); token; token = strtok(NULL, delim)) {

                    result = comparar(token, cen1);
                    strncat(strptr, result, strlen(token));
                    strncat(strptr, " ", 1);

                }

                printf("\nSoy el hijo y termino de procesar el texto.....\n");

                strncpy(mem, strptr, bits);

                sleep(1);
                sem_post(sem_1); /* activa al padre */

                /* libero los semáforos */
                sem_close(sem_1);
                sem_close(sem_2);
                printf("\nSoy el hijo y termino.....\n");
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
                sleep(1);
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
