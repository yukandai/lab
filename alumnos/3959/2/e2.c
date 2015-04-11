/**
 * @anquinpm
 * Ejercicio 2) Leer README.md
 */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

int process(char *input, int len);

int main(int argc, char **argv)
{
    int nchars = 0;
    char buff[SIZE];

    memset(buff, 0, sizeof buff);		//buff a "0"
    while( (nchars = read(STDIN_FILENO, buff, sizeof buff))>0){
	process(buff,nchars);   	
    }
   return 0;
}

int process(char *input, int len){
   int i=0;
   for(i=0;i<len;i++){
   	input[i]=toupper(input[i]);
   } 
    return write(STDOUT_FILENO, input, len);
 }
