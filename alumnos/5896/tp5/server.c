#include "header.h"
  
   
   #define MAXHILOS 10
   
   int server (char *ruta, int fdsocket, int puerto){
   
    struct sockaddr_in  direccion_cli={};
  
   socklen_t direccion_cli_len = sizeof direccion_cli;
   //pthread_mutex_init (&exc , NULL );          
   pthread_t idhilos[MAXHILOS];
   atributos_t atributos;
   
   
   int i=0;
   
   char buffer[800];
   
   memset(buffer,0,sizeof buffer);
   
  
   atributos.cantHilos=0;
   atributos.fdsocket=fdsocket;
   while((atributos.acceptfd = accept(atributos.fdsocket,(struct sockaddr *)&direccion_cli,&direccion_cli_len)) > 0) {
  //         if((atributos.cantHilos)<10){
                  atributos.id=i++;
                  printf("i es igual a : %d\n",atributos.id);
                  if((pthread_create(idhilos+i, NULL,(void *)http_worker, (void*) &atributos)) < 0){
  
                          perror("pthread_create");
  
                          return 0;
  
                  }
                  (atributos.cantHilos)++;
//          }               
   //close (atributos.fdsocket);
  
   } // fin while
// pthread_exit(NULL);
   close (atributos.fdsocket);
   return 0;
  
  } //fin server

