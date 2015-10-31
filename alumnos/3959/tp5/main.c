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

pthread_t t_id;
int main(int argc, char * const *argv){
	int sd, sd_conn,opc=0;
//	char buffer[BUF_SIZE];

	if((opc=getopt(argc,argv,"d:"))!=0 && argc==3){
		strncpy(d_con.ROOT,argv[2],strlen(argv[2]));			
	}else{	
		strncpy(d_con.ROOT,"www/",4);			
	}
	printf("Mi directorio ROOT es: %s\n",d_con.ROOT);
	strncpy(d_con.PORT,"8080",4);			
	
	sd = create_socket(&d_con);		 //creo el socket
	while((sd_conn = accept(sd,NULL,0))>0){
		pthread_create(&t_id,NULL,(void *)http_worker,(void *) sd_conn);
		//close(sd_conn);
	}
	close(sd);
	perror("acept ()");
	return 0;
}
