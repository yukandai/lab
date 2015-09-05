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

        int l=**(int**)leido, i=0,j, fd, cant, cond=1, nol ;
        char proh[32]="", rep[32]="", c, buff[32]="",*msje=malloc(l+1), tmp2[2];      
        void *temp;

        if (!msje){
            free (msje);
            puts ("malloc failed");
            exit (1);
        }
        fd=open ("./palabras.txt", O_RDONLY , 0444);
        msje=strcpy (msje, *mem);
        while ((read(fd, &tmp2[0],1))>0){
            i=0;

            lseek (fd, -1, SEEK_CUR);
            do{

            cant=read (fd, &buff[i], 1);
            c=buff[i];
            i++;
            }while (c!='\n');
            
                        
           

            snprintf (&proh[0], i, "%s", &buff[0]); 
            //memset (&rep[0], '*', i);
            snprintf (&rep[0], i, "***********************************") ;
            temp=msje;
            msje=parser(msje, &proh[0], &rep[0]);
            
       
        
        }; 
        write (STDOUT_FILENO, msje, l);
        *mem=strcpy (*mem, msje);
        
        free (msje);
        free (temp);
        sem_post(*sem);
        close (fd);
        //remove ("./palabras.txt");

        
    
 
}
