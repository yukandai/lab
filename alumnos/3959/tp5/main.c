#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "http_worker.h"

//pthread_t t_id[CONCUR];
int main(int argc, char * const *argv){
	int sd, sd_conn,opc=0;
	int nro_proceso;
	char buffer[BUF_SIZE];
	datos d_con;


    /* TODO: agregar creación y configuración del socket */
	if((opc=getopt(argc,argv,"d:"))!=0 && argc==3){
		strncpy(d_con.ROOT,argv[2],strlen(argv[2]));			
	}else{	
		strncpy(d_con.ROOT,"www/",4);			
	}
	printf("Mi directorio ROOT es: %s\n",d_con.ROOT);
	strncpy(d_con.PORT,"8080",4);			
	
	sd = create_socket(&d_con);		 //creo el socket

	while((sd_conn = accept(sd,NULL,0))>0){
		nro_proceso=fork();
		if (nro_proceso == 0) { 
			printf("Se conecto un cliente\n");	
			write (sd_conn, "Hola, Bienvenido!\r\n", 19); 
			read (sd_conn, buffer, sizeof buffer); 
			printf("El cliente escribió: %s\n", buffer);
			close(sd_conn);
			return 0;
		}
		close(sd_conn);
	}
	close(sd);
	perror("acept ()");
	return 0;
}
