#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef _HTTP_WORKER_H_
	#define _HTTP_WORKER_H_

	int http_worker(int, struct sockaddr*);
#endif