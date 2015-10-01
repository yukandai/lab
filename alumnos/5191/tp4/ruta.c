#include "header.h"

void NombreRuta(char **nombre){

      *nombre = malloc( sizeof( char) * strlen( optarg));
      strcpy( *nombre, optarg);

}