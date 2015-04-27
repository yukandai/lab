/**
 * TP 1)
 * La aplicación a desarrollar será parte de un sistema que utiliza el gobierno de un país, para
 * filtrar los mensajes enviados a ciertas redes sociales.
 *
 * La aplicación deberá identificar las palabras configuradas para eliminarlas del mensaje original
 * y escribir el resultado filtrado por stdout. También deberá tener una opción para enviar el
 * resultado a un archivo.
 */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 100

void processMessage(char *input, int len, char *file_name);
char *checkWord(char *input);
int openFile(char *file_name);

int main(int argc, char **argv) {

    int opt, nchars = 0;
    void *memoria;
    char buff[SIZE];
    char *file_name = NULL;

    while ((opt = getopt(argc, argv, "h::o:")) != -1) {
        switch (opt) {
            case 'h':
                printf("Modo de uso: \n ./tp1 -h\n ./tp1 -o mensaje-filtrado.txt\n");
                return 0;
            case 'o':
                file_name = optarg;
                break;
        }
    }

    memoria = memset(buff, 0, sizeof buff);
    while ((nchars = read(STDIN_FILENO, buff, sizeof buff)) > 0) {
        processMessage(memoria, nchars, file_name);
    }

    return 0;
}

/* *************************************************************** */
/*                          FUNCIONES                              */
/* *************************************************************** */

void processMessage(char *input, int len, char *file_name) {

    int i, j, fd;
    int cantPal=0;
    char *temp = (char *) malloc(128 * sizeof(char));
    char *palabra = (char *) malloc(128 * sizeof(char));
    char *palabraChequeada = (char *) malloc(128 * sizeof(char));

    for (i=0; i<len; i++) {
        if (input[i] != 32 && input[i] != 10) {
            *(temp) = input[i];
            strcat(palabra, temp);
        } else {
            if (temp > 0) {
                palabraChequeada = checkWord(palabra);
                palabraChequeada[strlen(palabraChequeada)] = input[i];

                if (file_name) {
                    if (fd = openFile(file_name)) {
                        write(fd, palabraChequeada, strlen(palabraChequeada));
                    } else {
                        perror("open");
                        exit(EXIT_FAILURE);
                    }
                } else {
                    write(STDOUT_FILENO, palabraChequeada, strlen(palabraChequeada));
                }

                *(palabra) = NULL;
                cantPal++;
            }
        }
    }

    close(fd);
}

char *checkWord(char *input) {
    char *pal_prohibidas[] = {"estupido", "estupida", "tonto", "tonta", "imbecil"};
    int i, flag = 0;
    char *cod_censura = (char *) malloc(128 * sizeof(char));

    for (i=0; i<=sizeof(*pal_prohibidas); i++) {
        if (strlen(pal_prohibidas[i]) == strlen(input)) {
            if (strncmp(input, pal_prohibidas[i], strlen(input)) == 0) {
                flag = 1;
                break;
            }
        }
    }

    if (flag == 1) {
        *(cod_censura) = 35;
        return cod_censura; // Palabra censurada
    } else {
        return input;       // Palabra valida
    }
}

int openFile(char *file_name) {
    return open(file_name, O_CREAT | O_RDWR | O_APPEND, 0777);
}
