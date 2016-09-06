/*
 * Computación II: TP3: Comunicación entre procesos con memoria compartida.
 * <carlos.taffernaberry@um.edu.ar>
 * <federico.hernandez@um.edu.ar>
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>
#include <wait.h>
#include <signal.h>

#include "padre.h"
#include "hijo.h"

int main(int argc, char **argv) {

    int option;
    int fd_file;
    int leidos = 0;

    char buffer[50];
    char *file_name = NULL;
    char *ptr_mem;

    int rta_sem;
    sem_t *sem;
    pid_t pid_hijo;

    while ((option = getopt(argc, argv, "i:")) != -1) {
        switch (option) {
            case 'i':
                file_name = optarg;
                break;
            default:
                printf("Modo de uso: \n ./tp3 -i file.txt (<file.txt> nombre del archivo que va a ser procesado\n");
                return 0;
        }
    }

    if ((fd_file = abrir_archivo(file_name))) {

        ptr_mem = crear_segmento_memoria();
        rta_sem = crear_semaforo(sem);

        switch ((pid_hijo = fork())) {
        case -1:
            /* ERROR */
            perror("fork()");
            exit(EXIT_FAILURE);
        case 0:
            /* HIJO */
            // while (sizeof ptr_mem > 0) {
                sem_post(sem);
                leer_memoria(ptr_mem);
                sem_wait(sem);
            // }
            /* aviso q termine de leer -> SIGTTIN: Terminal read from BG [21 (M=26, P=27))] */
            /*if (kill(getppid(), 21) < 0) {
                perror("kill()");
                exit(EXIT_FAILURE);
            }*/
            exit(EXIT_SUCCESS);
        default:
            /* PADRE */
            while ((leidos = read(fd_file, buffer, sizeof buffer)) > 0) {
                sem_post(sem);
                escribir_memoria(ptr_mem, buffer, leidos);
                sem_wait(sem);
            }
            /* aviso que no tengo mas q escribir -> SIGTTOU: Terminal write from BG [22 (M=27, P=28)] */
            /*if (kill(pid_hijo, 22) < 0) {
                perror("kill()");
                exit(EXIT_FAILURE);
            }*/
        }

    } else {
        perror("open()");
        exit(EXIT_FAILURE);
    }

    if (wait(NULL) < 0) {
        perror("wait()");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}
