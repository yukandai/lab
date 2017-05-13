#include "tp2.h"
#include "macros.h"

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define debug 1

void capitalizeAndSaveToFile(configuration *conf, int readEnd) {

	int nread, outputFd;
	char buf[READING_AMOUNT];

	// Open
	if ( (outputFd=open(conf->outputFile,O_CREAT,S_IRWXU|S_IRWXG)) < 0) {
		perror("open");
		_exit(-1);
	}
	if (debug) printf("%s\tSuccessfully opened: %s\n",__FILE__,conf->outputFile);
	
	if (debug) printf("%s reading from desc: %d\n",__FILE__,readEnd);
	while( (nread=read(readEnd,buf,READING_AMOUNT) > 0) ) {

		if (nread == -1) {
			perror("read");
			_exit(-1);
		}

		write(outputFd,buf,nread);
		if (debug) printf("%s\twrite to fd %d string: %s\n",__FILE__,readEnd,buf);
	}

	puts("Cerrando el archivo abierto");
	close(outputFd);

	return;
}
