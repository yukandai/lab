#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *word = "argentina";
    for (int i=0; i<strlen(word); i++) {
        printf("%c", toupper(word[i]));
    }
    printf("\n");
    return 0;
}
