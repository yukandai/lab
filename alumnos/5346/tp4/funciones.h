#ifndef _FUNCIONES_H_
        #define _FUNCIONES_H_
        
        #include <sys/socket.h>
        #include <unistd.h>
        #include <stdio.h>
        #include <netinet/in.h>
        #include <assert.h>
        #include <arpa/inet.h>
        #include <fcntl.h>
        #include <string.h>
        #include <signal.h>
        #include <stdlib.h>
        #include "funciones.h"
	#include "http_worker.h"

        int hijo(int,char*,char*);
        int extencion(int,char*);			
#endif