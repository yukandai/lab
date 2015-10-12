#include "../headers/tp3.h"
#include <stdio.h>

void error(int condicion_int, const char * mensaje) {
    if (condicion_int)
        printf("%s", mensaje);
}
