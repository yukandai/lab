/**
 *
 */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

#define SIZE 80

int filter(char *input, char **words_list, int size);
int word_in_list(char *word, char **words_list, int size);


int main(int argc, char **argv)
{
    char buff[SIZE];
    int nchars;
    char *words[] = {"hola", "mono", "tarántula"};
    int size = sizeof (words) / sizeof (*words);

    memset(buff, 0, sizeof buff);

    while ((nchars = read(STDIN_FILENO, buff, sizeof buff)) > 0) {
        filter(buff, words, size);
    }

    return 0;
}


int filter(char *input, char **words_list, int size)
{
    char *word;
    char *delim = "\t\r\n ";

    for (word = strtok(input, delim); word != NULL; word = strtok(NULL, delim)) {
        write(STDOUT_FILENO, " ", 1);

        if (word_in_list(word, words_list, size) == 0) {
            write(STDOUT_FILENO, word, strlen(word));
        } else {
            write(STDOUT_FILENO, "* ", 2);
        }
    }
    
    return 0;
}


int word_in_list(char *word, char **words_list, int size)
{
    int i;
    char *delim = "¡!¿?.,;:-_";
    char tmp[30];
    char *_word, *token;

    memset(tmp, 0, sizeof tmp);
    strncpy(tmp, word, sizeof tmp);
    _word = strtok_r(tmp, delim, &token);

    for (i = 0; i < size; i++) {
        if (strncmp(_word, words_list[i], strlen(words_list[i])) == 0) {
#if DEBUG
            printf("[x] Filtered word: %s\n", _word);
#endif               
            return 1;
        } 
    }

    return 0;
}
