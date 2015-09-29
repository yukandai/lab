#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <errno.h>
#include <sys/shm.h> 
#include <sys/fcntl.h>     
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <sys/wait.h>
#include "hijo.h"
#include "parser.h"  
#include "otras.h"

int main (int argc, char **argv){

    const int SIZE=4096;
    char c;
    void *mem , *leido;
    int *carat, status;
    sem_t *sem=mmap(0, sizeof (sem), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0); //semáforo compartidp
    mem= mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);         //mensaje compartido
    leido=mmap (0, 8,  PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);        //cantidad de caracteres leidos

if (sem_init (sem, 1, 0)<0){ //inicia semáforo
    perror ("Seminit: ");
    return -1;}

/*     erores       */
if (mem == MAP_FAILED) {
    printf("Map failed\n");
    return -1;}
if (sem == MAP_FAILED){
    printf("Map of semaphore failed\n");
    return -1;}
/*                   */
switch (fork()){
    case 0:
            sem_wait(sem);
            hijo (&mem, &sem,*(int*)leido);
            return 0;
    break;
    default:
        while((c=getopt (argc, argv, "p:")) != -1){
            switch (c){
                case 'p':
                    crear_arch (&argc, argv);  //crea archivo temporal con palabras a filtrar
                    *((int*)leido)=read (STDIN_FILENO, mem, SIZE);
                    sem_post(sem);
                    wait (&status);
                    sem_destroy(sem);
                    return 0;
                break;
                case '?':
                    printf ("Error\n");
                    return -1;
                break;
            }
        }
        if (argc==1){
            printf ("Necesita argumento\n");
        }
    break;
    }
}                                                              
