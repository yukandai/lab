/**
 * Explique por que cambia el proceso padre del hijo.
 *
 * Rta:
 * Al terminar el padre su ejecucion antes q la del proceso hijo, el proceso hijo es ahora un proceso huerfano,
 * eso quiere decir, q ahora su padre sera init (id=1)
 * 
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
