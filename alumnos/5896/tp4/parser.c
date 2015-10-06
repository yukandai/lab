#include "header.h"

void NombreArchivo(char **nombre){

	*nombre = malloc( sizeof( char) * strlen( optarg)); //reservamos el tamaño del nombre del archivo de configuracion
	strcpy( *nombre, optarg);

}


int ParserPuerto(char *archivo){

	char buffer[800];
	memset(buffer,0,800);

	char *buf;
	int puerto;
	int fd;

	fd = open(archivo,O_RDONLY);
	read (fd,buffer,sizeof(buffer));
	close (fd);

	if ( !strncmp (buffer, "port", 4 )) {
		buf = strtok( buffer, "=" ); // primer token (puerto)
		buf = strtok( NULL, "\n" ); // segundo token (numero puerto)
		puerto = atoi(buf);
	}

	//printf ("puerto %d\n",puerto);
	return puerto;

} // fin funcion ParserPuerto

char *ParserRuta(char *archivo){

	char buffer[800];
	memset(buffer,0,800);
	int fd;

	fd = open(archivo,O_RDONLY);
	read (fd,buffer,sizeof(buffer));
	close (fd);


	char *buf;

	char *buf2 = "/";

	char *ruta = malloc(300*sizeof(char));


	if ( strncmp (buffer, "droot", 5 )) {		

		buf = strtok( buffer, "/" );

		buf = strtok( NULL, "\n" );  
		//printf("\n\%sn",buf); 

		strcpy (ruta,buf2);
		strcat(ruta,buf);

		//printf ("buff %s\n",ruta);


	}

	return ruta;


} // fin funcion ParserRuta
