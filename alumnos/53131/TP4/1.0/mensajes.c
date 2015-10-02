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

void mensajes (int sock, int op){

    char buff[1024];
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
            sprintf(buff, "Content-Type: text/html\r\n");
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
