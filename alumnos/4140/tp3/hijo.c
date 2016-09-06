/*
 * Funciones llamadas por el proceso hijo
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <fcntl.h>

#include "hijo.h"

void leer_memoria(char *pmem) {

    // write(STDOUT_FILENO, pmem, s_buff.st_size);
    write(STDOUT_FILENO, pmem, sizeof pmem);
}

/*void leer_de_memoria(int segmento, int id_sem, struct sembuf str_sem) {

    char *sgto_mem_comp;

    // Mapeo el segmento de memoria al espacio de memoria del proceso
    if ((sgto_mem_comp = shmat(segmento, 0, 0)) < (char *) 0) {
        perror("shmat()");
        exit(EXIT_FAILURE);
    }

    // Asignar memoria para el segmento mapeado
    if ((sgto_mem_comp = malloc(sizeof (char) * TAM_BUFFER)) == NULL) {
        perror("malloc()");
        exit(EXIT_FAILURE);
    }

    // Asigno valores a la estructura para luego abrir el semaforo
    str_sem.sem_num = 0;
    str_sem.sem_opt = 0;            // lo bloqueo
    str_sem.sem_flg = IPC_NOWAIT;

    // Abro el semaforo
    if ((semop(semaforo, &str_sem, 1)) < 0) {
        perror("");
        exit(EXIT_FAILURE);
    }

    // sgto_mem_comp = contar_palabras();

    str_sem.sem_opt = 1;            // lo libero

    // write(STDOUT_FILENO, sgto_mem_comp, sizeof sgto_mem_comp);
}*/
