#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
#include "http_worker.h"

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_t t_id;
int main(int argc, char * const *argv){
	int sd, sd_conn, rc, opc=0;

	if((opc=getopt(argc,argv,"d:"))!=0 && argc==3){
		strncpy(d_con.ROOT,argv[2],strlen(argv[2]));			
	}else{	
		strncpy(d_con.ROOT,"www/",4);			
	}
	printf("Mi directorio ROOT es: %s\n",d_con.ROOT);
	strncpy(d_con.PORT,"8080",4);			
	
	sd = create_socket(&d_con);		 //creo el socket
	signal(SIGPIPE,SIG_IGN);
	while((sd_conn = accept(sd,NULL,0))>0){
		if((pthread_mutex_lock(&mtx))!=0){perror("MUTEX LOCK");}
		if((rc=pthread_create(&t_id,NULL,http_worker,(void *) sd_conn))!=0){
			perror("pthread_create fail");
			}
	}
	pthread_mutex_destroy(&mtx);
	close(sd);
	perror("acept ()");
	return 0;
}
