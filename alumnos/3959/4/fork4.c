/* @anaquinpm
 * Pablo Anaquín 		10/05/2015
 *
 * Explique por que cambia el proceso padre del hijo.
 *
 * El proceso padre termina antes que el hijo, sin esperarlo o requerir su estado devuelto. 
 * El proceso "init", padre de todos los procesos (PID 1), adopta al hijo huérfano, por eso
 * al requerir el PPID despues que el padre termine, retorna el PID del proceso "init".
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
