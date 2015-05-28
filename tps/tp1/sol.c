/**
 * tp2
 */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

#define SIZE 80

int filter(char *input, const char **words_list, int list_len);
int word_in_list(const char *word, const char **words_list, int list_len);


int main(int argc, char * const * argv)
{
    char buff[SIZE];
    int nchars;
    const char *words[] = {"hola", "mono", "tarántula"};
    int list_len = sizeof (words) / sizeof (*words);

    memset(buff, 0, sizeof buff);

    while ((nchars = read(STDIN_FILENO, buff, sizeof buff)) > 0) {
        filter(buff, words, list_len);
    }

    return 0;
}


int filter(char *input, const char **words_list, int list_len)
{
    char *word;
    char *delim = "\t\r\n ";

    for (word = strtok(input, delim); word != NULL; word = strtok(NULL, delim)) {
        write(STDOUT_FILENO, " ", 1);

        if (word_in_list(word, words_list, list_len) == 0) {
            write(STDOUT_FILENO, word, strlen(word));
        } else {
            write(STDOUT_FILENO, "* ", 2);
        }
    }
    
    return 0;
}


int word_in_list(const char *word, const char **words_list, int list_len)
{
    int i;
    char *delim = "¡!¿?.,;:-_";
    char tmp[30];
    char *_word, *token;

    memset(tmp, 0, sizeof tmp);
    strncpy(tmp, word, sizeof tmp);
    _word = strtok_r(tmp, delim, &token);

    for (i = 0; i < list_len; i++) {
        if (strncmp(_word, words_list[i], strlen(words_list[i])) == 0) {
#if DEBUG
            printf("[x] Filtered word: %s\n", _word);
#endif               
            return 1;
        } 
    }

    return 0;
}
