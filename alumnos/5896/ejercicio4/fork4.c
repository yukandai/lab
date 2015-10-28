/**
 * Explique por que cambia el proceso padre del hijo.
 * El proceso padre cambia debido al sleep adentro del proceso hijo que es mas largo que el sleep del padre,
ya que el proceso padre al seguir avanzando en su ejecucion termina antes del proceso hijo. Por lo tanto el 
proceso hijo al estar dormido mas tiempo, al "despertarse" el proceso padre ya a finalizado su ejecucion 
siendo asi un proceso huerfano.
Si el sleep del proceso padre estaria en 3, el proceso hijo no quedaria huerfano.
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

    sleep(3);
    return 0;
}
