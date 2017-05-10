#include "tp2.h"
#include "macros.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void doWork(configuration *conf, int pipe1fd[2], int pipe2fd[2]){
    
  	int i = 0;
    
    for (i=0; i<DEFAULT_CHILDS; i++){
    	switch (fork()){
      		case -1: // Error
        		perror("First fork");
        		exit(EXIT_FAILURE);
      		case 0: // Son
				if (i == 0) {
					puts("Soy el primer hijo");
					// First Child
					// Read from the pipe1 n bytes and write results to pipe2
					close(pipe1fd[WRITE_END]);
        			close(pipe2fd[WRITE_END]);
        			close(pipe2fd[READ_END]);
       
					readAndCount(conf, pipe1fd[READ_END], pipe2fd[WRITE_END]);
       
					close(pipe1fd[READ_END]);
				} else {
					puts("Soy el otro hijo");
					// Subsequent child
					close(pipe1fd[WRITE_END]);
					close(pipe2fd[WRITE_END]);
        			close(pipe1fd[READ_END]);
       
					capitalize(conf,pipe1fd[READ_END], pipe2fd[WRITE_END]);
       
					close(pipe2fd[READ_END]);
				}
				exit(EXIT_SUCCESS); // Kill the son
		}
	}

	puts("Soy el papa");
	// Close read ends
	close(pipe1fd[READ_END]);
	close(pipe2fd[READ_END]);

	int writeDescriptors[2];
	writeDescriptors[0] = pipe1fd[WRITE_END];
	writeDescriptors[1] = pipe2fd[WRITE_END];

	//Read from stdin or file and write to pipes
	readAndPassItOn(conf,writeDescriptors);
				
	close(pipe1fd[WRITE_END]);
	close(pipe2fd[WRITE_END]);
}
