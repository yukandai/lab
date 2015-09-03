#include <semaphore.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>


#include "comparar.h"
#include "funhijo.h"

void funhijo(char * mem, int * membits, char * cen1) {


    char aux[1000];

	int bits = 0;

    char * token;

    char * result;

    char delim[] = " \t\r\n\f";

    char strptr[1000];


		printf("\nSoy el hijo con PID:%d\n\n", getpid());

                
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


                /* libero los semáforos */
//                sem_close(sem_1);
//                sem_close(sem_2);
                printf("\nSoy el hijo y termino.....\n");

}
