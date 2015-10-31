#include "header.h"

void *http_worker(atributos_t *atributos)
{

	int fd;
	int leido;
	int leido3;
	int acceptfd = atributos->acceptfd;
	char* ruta = atributos->route;

	//para recurso
	long longitud = 0;
	char archivo[256];
	char tipo[256];

	//para reponse
	char *estado;
	char cabecera[256];
	char *version = "HTTP/1.1";

	char buffer[8000];		//request
	memset (buffer, 0, sizeof buffer);

	char buffer2[800];
	memset (buffer2, 0, sizeof buffer2);


	char *nombre = malloc (256 * sizeof (char));

	if((leido = read (acceptfd, buffer, sizeof (buffer))) > 0)
	{
		//	printf("%s \n",buffer); 
		memset (tipo, 0, sizeof tipo);
		memset (archivo, 0, sizeof archivo);

		nombre = recurso (buffer, archivo, tipo, &longitud, ruta);

		if (!(strncmp (buffer, "GET", 3) == 0))
		{
			estado = "HTTP/1.1 500 INTERNAL SERVER ERROR\n\nInternal Server error\n";
			write (acceptfd, estado, strlen (estado));
			close(acceptfd);

		}


		if ((fd = open (archivo, O_RDONLY)) < 0){
			estado = "HTTP/1.1 404 NOT FOUND\n\nno esta el archivo\n";
			write (acceptfd, estado, strlen (estado));

			close (fd);

			close(acceptfd);


		}
		else
		{
			estado = "200 OK";
			leido3 =
				snprintf (cabecera, sizeof cabecera,
						"%s %s\nContent-Length: %ld\nContent-Type: %s\n\n",
						version, estado, longitud, tipo);
			write (acceptfd, cabecera, leido3);
			
			while ((leido3 = read (fd, buffer2, sizeof buffer2)) > 0)
			{

				write (acceptfd, buffer2, leido3);
				
				memset (buffer2, 0, sizeof buffer2);
			}

			close (fd);
			close(acceptfd);


		}
	}				// fin if leido

	//close (fd);
	//close (acceptfd);
	(atributos->cantHilos)--;
	printf("La cantidad de hilos es%d \n", atributos->cantHilos);
	pthread_exit(NULL);

//	free(nombre);
//	free(buf);
//	free(ext);

	return nombre;

}				// fin funcion
