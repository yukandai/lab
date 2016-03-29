#include "http_worker.h"

void nombre_ruta(char **nombre){

      *nombre = malloc( sizeof( char) * strlen( optarg));
      strcpy( *nombre, optarg);

}