#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#define PIPE_RD 0
#define PIPE_WR 1
#define STDIN 0
#define STDOUT 1
#define STDERR 2

int sigflag = 3;

/*
Tareas:
        -Tratar de eliminar la mayor cantidad de librerias
        -Reemplazar todos los printf por funciones customizadas y luego eliminar la liberia stdio.h

 */
//Configuracion
#define TAMBUFF1 2
#define TAMBUFF2 80
//--

void imprimir(int fd, char * buff) {
    write(fd, buff, strlen(buff));
}

void error_(char * mensaje) {
    imprimir(STDERR, "Error: ");
    imprimir(STDERR, mensaje);
    exit(EXIT_FAILURE);
}

void rot13(char *str) {
    int i = 0;

    /* You do this until you find a '\0' */
    for (i = 0; str[ i ] != '\0'; i++) {

        /* Use the pointer notation if you passed a pointer. */
        /* If the letter is between a and m you can simply  sum it. */
        if (*(str + i) >= 'a' && *(str + i) < 'n')
            *(str + i) += 13;

            /* If the letter is between the n and z you have to do the opposite.*/
        else if (*(str + i) >= 'n' && *(str + i) <= 'z')
            *(str + i) -= 13;
    }
}

void filtrado(int fdo, int leido, char * buff1, char * buff2, char ** diccionario) {
    int i = 0;
    int j = 0;

    for (i = 0; i < leido; i++) {

        buff2[j] = buff1[i];

        if (buff2[j] == ' ' || buff2[j] == '\n' || buff2[j] == ',' || buff2[j] == ';' || buff2[j] == ':' || buff2[j] == '!' || buff2[j] == ';') {

            buff2[j + 1] = '\0';
            procesarPalabra(buff2, diccionario);
            write(fdo, buff2, strlen(buff2));
            j = 0;

        } else {
            j++;
        }

        //sino carga un caracter mas no se porque
        if (leido < TAMBUFF1) {
            break;
        }

    }
    //write(1,buff2,bytesread);
}

int procesarPalabra(char * buff2, char ** diccionario) {

    int i = 0, exito = 0;

    //Longitud erronea procesamiento termina si las longitudes no coinciden:

    for (i = 0; i < 3; i++) {

        if (strlen(buff2) == (strlen(*(diccionario + i)) + 1)) {
            exito = 1;
            break;
        }
    }
    if (exito != 1)
        return 0; //no hay match

    for (i = 0; i < 3; i++) {
        //printf("*diccionario+%d): %s\n",i,*diccionario+i);
        //printf("i: %d\n",i);
        char * str = strstr(buff2, *(diccionario + i));

        if (str) {
            strncpy(buff2, "***********************************************************", strlen(*(diccionario + i)));
            break;
        }
    }
    return 1; //hay match
}

void transferir2(int fdi1, int fdo1, int fdi2, int fdo2) { //transferencia bidireccional
    int leido;
    char buff[TAMBUFF1];

    while ((leido = read(fdi1, buff, sizeof buff)) > 1) {
        write(fdo1, buff, leido);

        leido = read(fdi2, buff, sizeof buff);
        write(fdo2, buff, leido);
    }
}

void transferir(int fdi, int fdo, int flag) {

    int leido;
    char buff1[TAMBUFF1];
    char buff2[TAMBUFF2];


    while (((leido = read(fdi, buff1, sizeof buff1)) > 1)) {
        switch (flag) {

            case 0: //transferir sin interferir en los datos
                break;
            case 1: //transferir aplicando rot13
                rot13(buff1);
                break;
            case 2:; //transferir filtrando datos
                char ** diccionario = (char**) malloc(3 * 8);
                *(diccionario + 0) = "la";
                *(diccionario + 1) = "de";
                *(diccionario + 2) = "el";
                filtrado(fdo, leido, buff1, buff2, diccionario);
                if (realloc(diccionario, 0)) {
                    error_("Error ubicando liberando memoria del diccionario\n");
                }
                break;
            default:
                error_("Seleccionar un flag valido para la funcion transferir()\n");
        }
        write(fdo, buff1, leido);
    }
}

void sigusr1() {
    sigflag = 1;
}

void sigusr2() {
    sigflag = 2;
}

int main(int argc, char ** argv) {

    pid_t cpid;
    char test[] = "test\n";
    char buff[TAMBUFF1];


    int pah[2];
    int xap[2];

    //Validacion de datos de configuracion y contexto de ejecucion
    if (TAMBUFF1 < 2) {
        error_("TAMBUFF1 tiene que ser mas grande que 1\n");
    }
    if (TAMBUFF1 > TAMBUFF2) {
        error_("Buffer primario es mas grande que buffer secundario\n");
    }
    if (argc != 1) {
        error_("El programa no admite argumentos\n");
    }
    //--
    //Creacion  de tuberias
    if (pipe(pah) == -1 || pipe(xap) == -1) {
        error_("No se pudo crear pah[] o xap[]\n");
    }
    //--
    //Creacion del hijo
    cpid = fork();
    if (cpid == -1) {
        error_("Fallo en la funcion fork() del padre\n");
    }
    //--
    //hijo  
    if (cpid == 0) {

        signal(SIGUSR1, sigusr1);
        signal(SIGUSR2, sigusr2);

        cpid = getpid();

        printf("Esperando que se envie señal al proceso #%d\n", cpid);

        pause();

        close(pah[PIPE_WR]);
        close(xap[PIPE_RD]);

        if (sigflag != 1 && sigflag != 2) {
            error_("Valor de sigflag no valido\n");
        }

        switch (sigflag) {
            case 1://SIGUSR 1
                printf("Opcion 1: Rot13\n");
                printf("Ingrese texto a procesar:\n");
                transferir(pah[PIPE_RD], xap[PIPE_WR], sigflag);
                close(xap[PIPE_WR]);
                break;
            case 2:; //SIGUSR 2          
                printf("Opcion 2: Filtrado de texto\n");
                printf("Ingrese texto a procesar:\n");
                int han[2];
                int cpid2;

                if (pipe(han) == -1) {
                    error_("No se pudo crear pah[]\n");
                }

                cpid2 = fork();

                if (cpid2 == -1) {
                    error_("Fallo en la funcion fork() del padre\n");
                }

                if (cpid2 == 0) {//nieto                    
                    transferir(han[PIPE_RD], xap[PIPE_WR], 2);

                } else {//continuacion del hijo
                    close(xap[PIPE_WR]);
                    close(han[PIPE_RD]);
                    transferir(pah[PIPE_RD], han[PIPE_WR], 0);
                }
                close(pah[PIPE_RD]);

                break;
            default:
                error_("Valor de sigflag no valido\n");
        }
        //while(transferir(pah[PIPE_RD],xap[PIPE_WR],*opt)>1);

        //poner en suspension
        cpid = getpid();
        kill(cpid, SIGTSTP);
        //--        

        //finalizando hijo
        close(pah[PIPE_RD]);
        exit(EXIT_SUCCESS);
        //--
    }//--

        //padre
    else {

        close(pah[PIPE_RD]);
        close(xap[PIPE_WR]);

        transferir2(STDIN, pah[PIPE_WR], xap[PIPE_RD], STDOUT);
        write(STDOUT, "\n", 1);

        //finalizando padre
        close(pah[PIPE_WR]);
        close(xap[PIPE_RD]);
        exit(EXIT_SUCCESS);
    }
    //--
    error_("Error grave\n");
    return 0;
}