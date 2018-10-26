#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <string.h> 

int main(int argc, char **argv) {
    char addr[32];
    memset(addr, 0, sizeof addr);

    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(-1);
    }

    struct hostent *hp = gethostbyname(argv[1]);

    if (hp == NULL) {
        perror("gethostbyname() failed\n");
        return 11;
    }

    int ret=0;
    if ((ret=inet_pton(AF_INET, hp->h_addr_list[0], addr)) != 1) {
        printf("ret: %d\n", ret);
        perror("inet_pton()");
        return -2;
    }

    printf("name = %s\n", hp->h_name);
    printf("addr = %s\n", addr);
    printf("\n");
}
