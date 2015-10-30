#ifndef _HTTP_WORKER_H
	#define _HTTP_WORKER_H_

	#define CONCUR 10
	#define BUF_SIZE 1024

	typedef struct DATOS{
		char PORT[5];
		char ROOT[5];
	} datos; 
	
	void http_worker(int sd_conn,void *addr);
	int create_socket(datos * d_con);
#endif
