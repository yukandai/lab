#include "../headers/tp3.h"
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

void hijo(datos * d) {

    while (true) {
        sem_wait(d->semH);
        d->mem[0] = '-';
        d->mem[1] = '-';
	d->mem[2] = '-';
	d->mem[3] = '-';
	d->mem[4] = '-';
        printf("HIJO: %s\n",d->mem);
        sem_post(d->semP);        
    }
}
