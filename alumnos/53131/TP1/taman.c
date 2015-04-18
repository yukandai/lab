#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "filtrar.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int taman (){

        int tm=0;
        int fd;
        char ch [100];
        fd=open("./temp",O_RDONLY, 0644);
        
        while ((read(fd, ch, sizeof ch)>0))
            {
        
                tm=lseek (fd, 0, SEEK_END); 
                      
                        
            }
                            
        return tm;






}
