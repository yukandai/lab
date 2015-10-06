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


void parse_and_frac (struct size *req_size, char *buff, char *method, char *url , char *type){

    size_t i=0, j=0;
    char url_ptr[32];
    int size;

    while ((!isspace(buff[j])) && (i < (req_size->method_url- 1))){ //Busco METODO en mensaje HTTP
        method[i] = buff[j];
        i++; j++;
    }
    method[i]='\0';
    
    i=0;

    while (isspace(buff[j]) && (j < req_size->buff))
        j++;                                        //Avanza espacios
    
    while ((!isspace(buff[j])) && (i < (req_size->method_url - 1)) && (j < (req_size->buff))){ //Busco URL en mensaje HTTP
                                 
        url[i] = buff[j];
        i++; j++;                                    
    }
    url[i]='\0'; 
    strncpy (url_ptr, url, strlen (url));
    size=strlen (url);
    get_mime (url_ptr, size, &type);  //busca MIME type          





}
