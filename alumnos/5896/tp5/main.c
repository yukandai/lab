#include "header.h"


int main(int argc, char * const *argv)
{
	int opcion;
	char *ruta;
	//char buffer[800];
	//memset(buffer,0,sizeof buffer);

	// parseo de ruta y de puerto
	char *archivoConfig = NULL;
	int puerto;

	while ((opcion = getopt (argc, argv, "d:")) >= 0){
		switch (opcion){

			case 'd':  // Abrir archivo .conf
				nombre_archivo(&archivoConfig);	
				break;

		} // cierre switch
	} // cierre while opcion

	if (!archivoConfig){ // default
		archivoConfig = "archivo.conf";
	}

	//fin de parseo de ruta y de puerto


	//declaro puerto y ruta
	puerto = parser_puerto(archivoConfig); //funciones.c devuelve el puerto
	ruta = parser_ruta(archivoConfig);//funciones.c devuelve la ruta
	//fin de declarar puerto y ruta



	//int fdsocket;
	//int opt = 1, optlen = sizeof(opt);
	//socklen_t addrlen;
	//struct sockaddr_in srv_addr;
	//struct sockaddr_in cli_addr;


	/* creación y configuración del socket */

	int sfd;
	struct sockaddr_in direccion = {};

	printf ("Servidor HTTP\n");
	printf ("Puerto: %d\n", puerto);

	signal(SIGCHLD, SIG_IGN);
	sfd = socket (AF_INET,SOCK_STREAM,0);

	if (sfd < -1){
		perror("Error en la creacion del socket\n");
		return -1;
	}

	direccion.sin_family=AF_INET;
	direccion.sin_port = htons(puerto);
	direccion.sin_addr.s_addr = INADDR_ANY;

	if (bind(sfd,(struct sockaddr*) &direccion,sizeof(direccion))==-1){
		perror("Error en bind\n");
		return -1;
	}

	if(listen(sfd,10)<0){
		perror("Error en listen\n");
		return -1;
	}
	//fin de creacion y configuracion de socket

	//CREACION DEL SERVIDOR
	server(ruta,sfd,puerto);
	/*struct sockaddr_in  direccion_cli={};
	  socklen_t direccion_cli_len = sizeof direccion_cli;
	  pthread_t idhilos[MAXHILOS];
	  atributos_t atributos;	
	  int acceptfd;
	  int i=0;
	  char buffer[800];

	  memset(buffer,0,sizeof buffer);

	  char nombre[256];

	  atributos.cantHilos=0;
	  atributos.fdsocket=sfd;
	//	strcpy (atributos.route, ruta);
	//char* ruta = atributos->route;


	while((atributos.acceptfd = accept(atributos.fdsocket,(struct sockaddr *)&direccion_cli,&direccion_cli_len)) > 0) {
	if((atributos.cantHilos)<10){ 
	atributos.id=i++;
	printf("i es igual a : %d",atributos.id);
	if((pthread_create(idhilos+i, NULL,(void *)http_worker, (void*) &atributos)) < 0)    {

	perror("pthread_create");

	return 0;

	}
	(atributos.cantHilos)++;
	}               

	} // fin while

	// pthread_exit(NULL);
	close (atributos.fdsocket);
	 */
	return 0;

} //fin server

