/** Aplicación que sirve para dividir un archivo en una cantidad de partes iguales excepto la última */

#include <unistd.h>

#include "funciones.h"

int main(int argc, char **argv) {

    char *file_name = NULL;

    file_name = argv[1];

    dividir(file_name);

    return 0;
}
