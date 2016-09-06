/*
 * Funciones llamadas por el proceso padre
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <fcntl.h>

#include "padre.h"

int abrir_archivo(char *file_name) {

    return open(file_name, O_RDWR, 0777);
}

char *crear_segmento_memoria() {

    char *seg_mem;

    if ((seg_mem = mmap(NULL, sizeof (char), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0)) < 0) {
        perror("mmap()");
        exit(EXIT_FAILURE);
    }

    return seg_mem;
}

int crear_semaforo(sem_t sem) {

    int res_sem;

    if ((res_sem = sem_init(&sem, 1, 0)) < 0) {      /* Semaforo sin nombre, valor inicial 0 */
        perror("sem_open()");
        exit(EXIT_FAILURE);
    }

    return res_sem;
}

void escribir_memoria(char *pmem, char *buff, int cant) {

    // write(*pmem, buff, cant);   /* write(STDOUT_FILENO, buff, cant); */
    // *pmem = buff;
}

/*void escribir_en_memoria(char *buff, int cant, int segmento, int semaforo, struct sembuf str_sem) {

    char *sgto_mem_comp;

    // Mapeo el segmento de memoria al espacio de memoria del proceso
    if ((sgto_mem_comp = shmat(segmento, 0, 0)) < (char *) 0) {
        perror("shmat()");
        exit(EXIT_FAILURE);
    }

    // Asignar memoria para el segmento mapeado
    if ((sgto_mem_comp = malloc(sizeof (char) * cant)) == NULL) {
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

    sgto_mem_comp = buff;

    str_sem.sem_opt = 1;            // lo libero

    // write(STDOUT_FILENO, sgto_mem_comp, cant);
}*/

/*void mostrar_resultado() {
    // leemos de memoria y mostrados datos
    write(STDOUT_FILENO, "palabras de 2 letras: 8\npalabras de 3 letras: 21\n", 50);
}*/
