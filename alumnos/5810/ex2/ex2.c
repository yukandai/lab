/* 
 * File:   main.c
 * Author: francisco
 *
 * Created on April 11, 2015, 7:20 PM
 */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

int process(char *input, int len);

int main(int argc, char **argv) {
    int nchars = 0;
    char buff[SIZE];

    memset(buff, 0, sizeof buff);

    nchars = read(STDIN_FILENO, buff, sizeof buff);


    process(buff, nchars);



    //printf("buff: %s\n", buff);
    //printf("bytes: %d\n", nchars);

    return 0;
}

int process(char *input, int len) {

    int i;

    for (i = 0; i < len; i++)
        *(input + i) = toupper(*(input + i));



    return write(STDOUT_FILENO, input, len);
}




