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


#define SERVER_STRING "Server: tp4_mazz\r\n"

void mensajes (int sock, int op, char *tipo){

    char buff[1024]; 
    char tipo2[32];
    char temp[32];

    memcpy (tipo2, tipo, strlen (tipo));
    //tipo2[strlen(tipo2) -1]
               



    //write (STDOUT_FILENO, tipo2, strlen (tipo2));
    
    switch (op){
        case 505:
            sprintf(buff, "HTTP/1.0 505 INTERNAL SERVER ERROR \r\n");
            write(sock, buff, strlen(buff));
            sprintf(buff, SERVER_STRING);
            write(sock, buff, strlen(buff));
            sprintf(buff, "Content-Type: text/html\r\n");
            write(sock, buff, strlen(buff));
            sprintf(buff, "\r\n");
            write(sock, buff, strlen(buff));
            sprintf(buff, "<HTML><TITLE>INTERNAL ERROR</TITLE>\r\n");
            write(sock, buff, strlen(buff));
            sprintf(buff, "<BODY><P>The server could not fulfill\r\n");
            write(sock, buff, strlen(buff));
            sprintf(buff, "your request.\r\n");
            sprintf(buff, "</BODY></HTML>\r\n");
            write(sock, buff, strlen(buff));
            sprintf (buff, "\r\n");
            write (sock, buff, strlen(buff));

        break; 
       
        case 200:
            sprintf(buff, "HTTP/1.0 202 OK\r\n");
            write(sock, buff, strlen(buff));
            sprintf(buff, SERVER_STRING);
            write(sock, buff, strlen(buff));
            sprintf (buff, "Content-type: ");
            write(sock, buff, strlen(buff));
            strcpy (buff, tipo2);
            write (sock, buff, strlen (tipo2));
            sprintf (buff, "\r\n");            
            write (sock, buff, strlen (buff));
            sprintf(buff, "Transfer-Encoding: chunked\r\n");
            write(sock, buff, strlen(buff));
            sprintf (buff, "\r\n");
            write (sock, buff, strlen(buff));
    break;


        case 404:
            sprintf(buff, "HTTP/1.0 404 NOT FOUND \r\n");
            write(sock, buff, strlen(buff));
            sprintf(buff, SERVER_STRING);
            write(sock, buff, strlen(buff));
            sprintf(buff, "Content-Type: text/html\r\n");
            write(sock, buff, strlen(buff));
            sprintf(buff, "\r\n");
            write(sock, buff, strlen(buff));
            sprintf(buff, "<HTML><TITLE>ERROR 404</TITLE>\r\n");
            write(sock, buff, strlen(buff));
            sprintf(buff, "<BODY><b>404 FILE NOT FOUND</b>\r\n");
            write(sock, buff, strlen(buff));
            sprintf(buff, "<br>The file you have requested does not exist.\r\n");
            write(sock, buff, strlen(buff));
            sprintf(buff, "</BODY></HTML>\r\n");
            write(sock, buff, strlen(buff));
            sprintf (buff, "\r\n");
            write (sock, buff, strlen(buff));

        break; 






    }
}
