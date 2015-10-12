#include "../headers/tp3.h"
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

void hijo(datos * d) {

    while (true) {
        sem_wait(d->semH);
        d->mem[0] = '$';
        d->mem[1] = '$';
        printf("hijo: %s\n",d->mem);
        sem_post(d->semP);        
    }
}
