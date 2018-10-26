#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

#include "hijo.h"


struct resource {
    char domain[120];
    char word[30];
};

struct resource *parse_resource(char *buff);


void hijo(int connd)
{
    char buff[1024];
    int leido;

    memset(buff, 0, sizeof buff);

    leido = read(connd, buff, sizeof buff);

    struct resource *r = parse_resource(buff);

    printf("domain: %s\n", r->domain);
    //write(STDOUT_FILENO, buff, leido);
    //write (connfd ,buff ,leido);
    // se conecta como cliente a un servidor http

    if (r) free(r);
}

struct resource *parse_resource(char *buff)
{
    char *tok;
    struct resource *r = malloc(sizeof (struct resource));

    memset(r->domain, 0, sizeof (r->domain));
    memset(r->word, 0, sizeof (r->word));

    tok = strtok(buff, " /");
    tok = strtok(NULL, " ");
    
    printf("tok: %s\n", tok);
    strncpy(r->domain, tok, sizeof (r->domain));

    return r;
}

