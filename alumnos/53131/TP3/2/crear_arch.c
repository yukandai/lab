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


       FILE *fp;
       int i, fd, leido;
       char *str;

       fd=open ("./palabras.txt", O_RDWR | O_CREAT | O_TRUNC, 0777);
       //fp=fdopen (fd, "w+");
       str=strtok (*(argv+2),",");
                       
       while (str!= NULL){
            
           //fprintf (fp, "%s\n", str);
           leido=strlen (str);
           write (fd,str, leido); 
           write (fd,"\n", 1); 
           
           str =strtok (NULL, ",");
       }

         //fclose (fp);
         close (fd);
         
}
