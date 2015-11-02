#ifndef _HTTP_WORKER_H
	#define _HTTP_WORKER_H_
	#include <semaphore.h>
	#define CONCUR 10
	#define BUF_REQ  512
	#define BUF_ARCH  1024
	#define BUF_NBR_ARCH  256

	typedef struct DATOS{
		char PORT[5];
		char ROOT[5];
	} datos; 

	void * http_worker (void *fd_con);
	int create_socket(datos * d_con);
	datos d_con;
	sem_t sem_thr;
#endif
