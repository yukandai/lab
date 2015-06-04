 #ifndef HIJOH
          #define HIJOH
  #include <unistd.h>
  #include <stdio.h>
  #include <fcntl.h>
  #include <string.h>
  #include <ctype.h>
  #include <signal.h>
  #define PIPE_RD 0
  #define PIPE_WR 1
  
  
  //Declaramos funciones
  
  void manejador(int signo);
  
  //Declaramos variables
 int pah[2];
 int hap[2];
 int han[2];
 
  
  #endif

