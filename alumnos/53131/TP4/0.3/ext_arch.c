#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>   
#include <unistd.h>
#include <fcntl.h>

#include "http_worker.h" 
#include "etc.h" 

int ext_arch (int cli_sock, struct size* taman, char *url, char *path)
{

        int res; 
        int fd;
        char buff [1024]="";
                       
        sprintf (path, "/var/www/html");
        strncat (path, url, taman->method_url);  //crea path entero
            
        if ((res=access (path, F_OK)) != 0)            //evalúa existencia de archivo
        {
            mensajes (cli_sock, 404);    
            return -1; 
        }else if (((access (path, R_OK)) != 0) && ((access (path, X_OK) != 0)))      //evalúa permisos de archivo
        {
            mensajes (cli_sock, 505);
            return -1;
        
        }else
        {     
            if ((fd=open (path, O_RDONLY)) != -1)
            {   
                mensajes (cli_sock, 200);   
                while ((read (fd, buff, sizeof buff)) !=0)
                {
                    write (cli_sock, buff, strlen (buff));
                }  
            
            }else
            {   
            
                mensajes (cli_sock, 505); 
            
            }

            
        
        
        }


}
