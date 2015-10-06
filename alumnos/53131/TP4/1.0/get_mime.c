#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include "http_worker.h" 
#include "etc.h"


int get_mime (char *url_o, int size, char **type_o){

    char url [128]="";
    char type[32]="";
    char mime[32]=""; 
    char buff[32]="", buff2 [32]="",buff3[32]="", tmp[32]="";
    int i=0,j=0, fd; 
    int wl=0, leido=0;
    int cont=0, pos=0, length=0;
    char eof='f';
    char c;

    strncpy (url, url_o, size);
    

    
    //write (STDOUT_FILENO, url, strlen (url));
    //printf ("\n");
    while (url[i] != '\0')
    {
        i++;                                 //avanza hasta final de url
    }
     
    while (url[i] != '.')
    {
        i--;                                           //busca el primer punto de adelante para atrás
        cont=cont+1;
    }
    
    //length=cont - 1;
    cont = cont -1;
    wl=cont;
    
    while (cont!=0){
        pos=strlen (url) - cont;
        strncat (type, &url[pos], 1);                            //copia extension sin '.'
        cont=cont-1;
    }
    //write (STDOUT_FILENO, type, wl);
     
    printf ("\n");

    if ((fd= open ("./mimes.txt", O_RDONLY)) == -1 )
        {
            perror ("open failed: ");
        }
    lseek (fd, 0, SEEK_CUR);     //documento al inicio
    while ( eof == 'f' )
        {
            memset (buff, '\0', sizeof buff);
            memset (tmp, '\0', sizeof buff);
            memset (buff2, '\0', sizeof buff);
            memset (buff2, '\0', sizeof buff);
            if ((read (fd, tmp, wl)) <= 0)                       // es EOF?
                {
                    eof='t';
                }else
                {
                     strncat (buff, tmp, wl);

                } 
            if ((leido=strncmp (buff, type, wl)) == 0)           //busca la extension en el archivo 'mimes', de a n caracteres a la vez
                {                                                //n es el largo de la extension --> jpg=3, html=4, etc.
                    while (!isspace(buff2[0]))
                        {                          //avanza espacios
                            read (fd,buff2,1);
                        }
                    while ( c!= '\n')
                        {
                            read (fd, buff, 1);
                            strncat (mime, buff, 1);
                            c=buff[0];
                        }
                    eof = 't';
                }else
                {
                    while (buff3[0] != '\n')
                        {
                        read (fd,buff3,1);
                        }
                    //lseek (fd, 1, SEEK_CUR); 
                }
        } 
       
    memcpy (*type_o, mime, strlen (mime));  
    close (fd);  
}


      











