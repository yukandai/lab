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

void crear_arch (int *argc, char **argv){


       FILE *fd;
       int i;
       char *str;

       fd=fopen ("./palabras.txt", "w");
       
       str=strtok (*(argv+2),",");
      
       while (str!= NULL){
            
            fprintf (fd, "%s\n", str);
            str =strtok (NULL, ",");
       }

         fclose (fd);

}
