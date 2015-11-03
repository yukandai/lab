#include "header.h"

void nombre_archivo(char **nombrearchivo){

	*nombrearchivo = malloc( sizeof( char) * strlen( optarg)); //reservamos el tamaño del nombre del archivo de configuracion
	strcpy( *nombrearchivo, optarg);

}


int parser_puerto(char *archivo){

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

char *parser_ruta(char *archivo){

	char buffer[800];
	memset(buffer,0,800);
	int fd;

	fd = open(archivo,O_RDONLY);
	read (fd,buffer,sizeof(buffer));
	close (fd);


	char *buf;

	char *buf2 = "/";

	char *rutaparser = malloc(300*sizeof(char));


	if ( strncmp (buffer, "droot", 5 )) {		

		buf = strtok( buffer, "/" );

		buf = strtok( NULL, "\n" );  
		//printf("\n\%sn",buf); 

		strcpy (rutaparser,buf2);

		strcat(rutaparser,buf);

		//printf ("buff %s\n",ruta);


	}

	return rutaparser;


} // fin funcion ParserRuta
