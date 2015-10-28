#include <unistd.h>
#include <stdio.h>


int main(int argc, char **argv)
{
    switch (fork()) {
    case 0: // hijo        
        return 0;      

    case -1: // error
        perror("fork(): ");
        return 1;

    default: // padre
        break;
    }

    return 0;
}

