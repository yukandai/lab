#include "tp2.h"
#include "macros.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define debug 0

void doWork(configuration *conf, int pipe1fd[2], int pipe2fd[2], int pipe3fd[2]){
    
  	int i = 0;
    pid_t childpid=0;

    for (i=0; i<DEFAULT_CHILDS; i++){
    	switch ((childpid=fork())){
      		case -1: // Error
        		perror("First fork");
        		exit(EXIT_FAILURE);
      		case 0: // Son
				if (i == 0) {
					// First Child
					close(pipe1fd[WRITE_END]);
        			close(pipe2fd[WRITE_END]);
        			close(pipe2fd[READ_END]);
        			close(pipe3fd[READ_END]);
       
					readAndCount(conf, pipe1fd[READ_END], pipe3fd[WRITE_END]);
       
					close(pipe1fd[READ_END]);
					close(pipe3fd[WRITE_END]);
				} else {
					// Subsequent child
        			close(pipe1fd[READ_END]);
					close(pipe1fd[WRITE_END]);
					close(pipe2fd[WRITE_END]);
					close(pipe3fd[READ_END]);
					close(pipe3fd[WRITE_END]);
					
					capitalizeAndSaveToFile(conf,pipe2fd[READ_END]);      
       
					close(pipe2fd[READ_END]);
				}
				exit(EXIT_SUCCESS); // Kill the son
		}
	}

	close(pipe1fd[READ_END]);
	close(pipe2fd[READ_END]);
	close(pipe3fd[WRITE_END]);

	int writeDescriptors[2];
	writeDescriptors[0] = pipe1fd[WRITE_END];
	writeDescriptors[1] = pipe2fd[WRITE_END];

	//Read from stdin or file and write to pipes
	readAndPassItOn(conf,writeDescriptors);
				
	close(pipe1fd[WRITE_END]);
	close(pipe2fd[WRITE_END]);

	//Wait for first child to finish
	char amount[1024];
	while( read(pipe3fd[READ_END],amount,strlen(amount)) > 0) {
		printf("El padre dice que la cantidad de palabras es: %s\n",amount);
	}
	//Wait for second child to finish ???
	close(pipe3fd[READ_END]);

	if (debug) puts("El padre muriendo");
	_exit(EXIT_SUCCESS);
}
