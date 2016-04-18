/** Aplicación que sirve para unir partes de archivos en un solo archivo */

#include <stdio.h>
#include <unistd.h>

#include "funciones.h"

int main(int argc, char **argv) {

    char *file_name = NULL;

    file_name = argv[1];

    unir(file_name);

    return 0;
}
