#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

#include "http_worker.h" 
#include "etc.h"


int http_worker (int sock,  struct sockaddr* cli_addr){

    char buff[1024]="";
    char method[255]="";
    char url[255]="";
    char path[512]="";
    char tipo[32]="";
    struct size req_size;
    struct stat st;       
    int leido=0;

    req_size.buff=sizeof (buff);           
    req_size.method_url=sizeof (url); //envio estructura con tamaños a función ya que 
    req_size.path=sizeof (path);      //no puede recuperarse tamaño de puntero con sizeof


    
    leido = get_line(sock, buff, sizeof (buff));//lee primera linea de respuesta (método y URL)
    parse_and_frac (&req_size, buff, method, url, tipo);//busco URL y Método
    
    if (strcasecmp (method, "GET") == 0){
    
        ext_arch (sock, &req_size, url, path, tipo);

    }else{
        mensajes (sock, 505, "");
    }
                                                               
   //write (STDOUT_FILENO, method, strlen (method));
   //write (STDOUT_FILENO, tipo, strlen (tipo));
    
    /*--Cerrando conexión a socket--*/

    shutdown (sock, SHUT_WR);
    close (sock);
    return 0;
    /*-------------------------------*/  

}
