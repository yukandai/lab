#include "tp2.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Pipe (int pipefd[2]){
    
    if (pipe(pipefd) == -1){
        perror("error creating pipe");
        exit(EXIT_FAILURE);
    }
}
