#ifndef NIETOH
             #define NIETOH
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <string.h>
    #include <ctype.h>
    #include <signal.h>
    #define PIPE_RD 0
    #define PIPE_WR 1
  
  
    //Declaramos funciones
  
    void nieto(int signo);
  
    //Declaramos variables
 
	  char buff[100];
          int leido;
          int pid2;
 
  
    #endif
  
