/**
 * Ejercicio 2) 
 */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

int process(char *input, int len);

int main(int argc, char **argv){
    	int nchars = 0;
    	char buff[SIZE];
	
    	memset(buff, 0, sizeof buff);	
	while((nchars = read(STDIN_FILENO, buff, sizeof buff)) > 1){
		process(buff,nchars);
	}

    	//printf("buff: %s\n", buff);
    	//printf("bytes: %d\n", nchars);

    	return 0;
}

int process(char *input, int len){
	int i = 0;
	while(i < len){
		input[i] = toupper(input[i]);
		i++;
	}	

	return write(STDOUT_FILENO, input, len);
}
