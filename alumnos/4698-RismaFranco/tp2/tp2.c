#include "tp2.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define debug 1

int main(int argc, char **argv) {

	if (debug) printf("------------ Starting %s --------------\n",argv[0]);

  	configuration *conf = (configuration *)malloc(sizeof(configuration));
  	
	// Child pipes
	int pipe1fd[2];
  	int pipe2fd[2];

    // Handle options
  	optionsHandler(argc,argv,conf);
	if (debug) printf("Opciones: inputFile: %s\t outputFile: %s\n",conf->inputFile, conf->outputFile);

    // Create 1st pipe
    Pipe(pipe1fd);
	if (debug) puts("Pipe 1 creted");

    // Create 2nd pipe
    Pipe(pipe2fd);
	if (debug) puts("Pipe 2 created");
	
    // Fork
    doWork(conf, pipe1fd, pipe2fd);

	/*
    //Father
    dadWork(conf, pipe1fd, pipe2fd);



    do {
        memset(buffer, 0, sizeof buffer);
        nread = read(STDIN_FILENO, buffer, sizeof buffer);
        write(STDOUT_FILENO, buffer, nread);
    } while (nread > 0);
*/
    return 0;
}

