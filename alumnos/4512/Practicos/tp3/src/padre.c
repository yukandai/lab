#include "../headers/tp3.h"
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>

void padre(datos * d) {
    int leido;
    while (true) {
        sem_wait(d->semP);
        leido = read (0 , d->mem , BLOQUE_DE_LECTURA_DE_DISCO );
        
        if ( leido <= 0)
            break;
        
        printf("PADRE: %s\n", d->mem);
        sem_post(d->semH);
    }
}
