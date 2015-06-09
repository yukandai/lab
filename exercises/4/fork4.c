/**
 * Explique por que cambia el proceso padre del hijo.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *const argv[])
{
    printf ("pid proceso %d, y el padre (bash) %d\n", getpid(), getppid());

    if (fork() == 0) {
        printf ("pid proceso hijo %d, y el padre %d\n", getpid(), getppid());
        sleep(2);
        printf ("pid proceso hijo %d, y el padre %d ???\n", getpid(), getppid());
        return 0;
    }

    sleep(1);
    return 0;
}
