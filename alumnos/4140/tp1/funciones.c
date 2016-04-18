#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Crea un archivo llamado '@file_name' y retorna un descriptor */
int openFile(char *file_name) {
    return open(file_name, O_CREAT | O_RDWR | O_APPEND, 0777);
}

/* Abre un archivo llamado '@file_name' y retorna un descriptor */
int openExistingFile(char *file_name) {
    return open(file_name, O_RDONLY);
}

/* Lee todos los archivos q comiencen con '@baseName' y crea un archivo cuyo contenido sea lo leido */
void unir(char *fileName) {

    int fd, fd_dogs;
    char *baseName = "dog.ppm-0";
    char buffer[1000] = "";
    char name[10];
    int parte = 0, seguir = 0;     // 0: false | 1: true

    do {
        sprintf(name, "%s%d", baseName, parte);     /* armamos el nombre de archivo */

        if ((fd = open(name, O_RDONLY)) != -1) {
            /* ENCONTRADO */
            if ((fd_dogs = openFile(fileName)) != -1) {
                while (read(fd, buffer, 1000) > 0) {
                    write(fd_dogs, buffer, 1000);
                }
            } else {
                perror("[OPEN] ");
            }

            seguir = 1;
            parte++;
        } else {
            /* NO ENCONTRADO */
            seguir = 0;
        }

        close(fd);
        close(fd_dogs);

    } while (seguir);

}

/* Divide el archivo '@fileName' en n partes iguales */
void dividir(char *fileName) {

    int i, fd, fd_new, bytesLeidos;
    char buffer[52000] = "";
    char *baseName = "part.ppm-0";
    char name[11];

    if ((fd = openExistingFile(fileName)) != -1) {
        /* ENCONTRADO */
        /* Lo divimos en 4 partes */
        for (i = 0; i<=3; i++) {
            sprintf(name, "%s%d", baseName, i);

            if ((fd_new = openFile(name)) != -1) {
                /* Leemos 52k */
                bytesLeidos = read(fd, buffer, 52000);
                write(fd_new, buffer, bytesLeidos);
            } else {
                perror("[OPEN] ");
            }
        }
    } else {
        perror("[OPEN] ");
    }

    close(fd);
    close(fd_new);
}
