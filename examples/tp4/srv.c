#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <netdb.h>

#include "hijo.h"

/*struct sockaddr_in {
  short            sin_family;   // e.g. AF_INET
  unsigned short   sin_port;     // e.g. htons(3490)
  struct in_addr   sin_addr;     // see struct in_addr, below
  char             sin_zero[8];  // zero this if you want to
  };
  struct in_addr {
  unsigned long s_addr;  // load with inet_aton()
  };*/
int main(){
    int fd, connfd, pid;
    struct sockaddr_in srv_addr={};
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if  (fd < 0 ){
        perror ("socket");
        return -1;
    }

    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(8080);
    srv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    int opt = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof opt);
    if (bind(fd,(struct sockaddr *)&srv_addr, sizeof srv_addr) < 0 ) {
        perror ("bind");
        return -1;
    }

    listen(fd, 5);
    //signal(SIGCHLD, SIG_IGN); //para sacar procesos terminados de la PCB ...

    while ((connfd = accept(fd,NULL, 0)) > 0){
        pid = fork();
        //hijo
        if (pid == 0) {
            hijo(connfd);
            return 0;
        }
        close(connfd);
    }
    return 0;
}	
