#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../headers/tp3.h"
#include <sys/mman.h>

int main(int argc, char** argv) {
    argv++;
    argc++;
    datos d;
    int tam = BLOQUE_DE_LECTURA_DE_DISCO + 2 * sizeof (sem_t) + sizeof (int); //2 memorias y 2 semaf
    d.mem = d.sharedMem = mmap(NULL, tam, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    d.semH = d.sharedMem + BLOQUE_DE_LECTURA_DE_DISCO;
    d.semP = d.sharedMem + BLOQUE_DE_LECTURA_DE_DISCO + sizeof (sem_t);

    sem_init(d.semH, COMPARTIDO, BLOQUEADO);
    sem_init(d.semP, COMPARTIDO, LISTO);

    pid_t pid = fork();
    switch (pid) {
        case 0: //hijo
            hijo(&d);
            return (EXIT_SUCCESS);
            break;
        case -1:
            perror("Error de fork()");
    }
    padre(&d);
    munmap(d.sharedMem, 0);

    return (EXIT_SUCCESS);
}
