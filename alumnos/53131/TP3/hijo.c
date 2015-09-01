#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/shm.h> 
#include <sys/fcntl.h>     
#include <sys/stat.h>
#include <sys/mman.h>
#include <semaphore.h>
#include "hijo.h"
#include "parser.h"

void hijo (void **mem, sem_t **sem, void **leido){

        int l=**(int**)leido, i;
        FILE *fd;
        char proh[50], rep[4]="????";
        char *msje=malloc(l);          
        
        
        fd=fopen ("./palabras.txt", "r");
        //memcpy (msje, *mem, l);
        msje=strcpy (msje, *mem);
        
        while (fscanf (fd, "%s", proh)==1){

            msje=parser(msje, proh, rep);   
        
        }
        write (STDOUT_FILENO, msje, l);      
        //memcpy (*mem, msje, l);
        *mem=strcpy (*mem, msje);
        
        sem_post(*sem);
        fclose (fd);
        remove ("./palabras.txt");
        free (msje);
        
    
 
}
