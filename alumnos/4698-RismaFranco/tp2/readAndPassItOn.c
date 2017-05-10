#include "tp2.h"
#include "macros.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>

void readAndPassItOn (configuration *conf, int writeDescriptors []) {

	int nread = 0, descriptor = -1;
	char buffer[READING_AMOUNT];

	if (conf->inputFileFlag) {
		//Open file
		puts("Leo del archivo");
		if ( (descriptor=open(conf->inputFile,O_RDONLY)) == -1){
			perror("open");
			exit(EXIT_FAILURE);
		}
	} else {
		puts("Leo de STDIN");
		descriptor = STDIN_FILENO;
	}

	printf("Leo desde %d\n",descriptor);
	while ( (nread=read(descriptor,buffer,READING_AMOUNT)) > 0) {
		if (write(writeDescriptors[0],buffer,nread) == -1) {
			perror("write into first fd");
		}
		if (write(writeDescriptors[1],buffer,nread) == -1) {
			perror("write into second fd");
		}
	}
	return;

}
