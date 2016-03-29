#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "http_worker.h"

direccion datosDireccion(char *buff){
	direccion dir;
	char aux[1024];
	int i=0, j=0, fd, leido;


	while(isgraph(buff[i])){
		i++;
	}
	i+=2;	
	while(isgraph(buff[i])){
		dir.arch[j] = buff[i];
		i++;
		j++;
	}
	
	j=0;
	for (i=0; isgraph(dir.arch[i]); i++){
		if(dir.arch[i] == '.'){
			i++;
			while (isgraph(dir.arch[i])){
				dir.ext[j] = dir.arch[i];
				i++;
				j++;
			}
		}
	}
	if (dir.ext[0] == 'j' && dir.ext[1] == 'p' && dir.ext[2] == 'g'){		
		strncpy(dir.mime,"image/jpeg",10);
	}
	if (dir.ext[0] == 'h' && dir.ext[1] == 't' && dir.ext[2] == 'm' && dir.ext[3] == 'l'){
		strncpy(dir.mime,"text/html",9);
	}
	if (dir.ext[0] == 'p' && dir.ext[1] == 'd' && dir.ext[2] == 'f'){
		strncpy(dir.mime,"application/pdf",15);
	}	
	if (dir.ext[0] == 't' && dir.ext[1] == 'x' && dir.ext[2] == 't'){
		strncpy(dir.mime,"text/plain",10);
	}

	memset(aux, 0, sizeof aux);
	dir.len = 0;

	strncat(dir.ruta,"public/", 62);
	strncat(dir.ruta, dir.arch, sizeof dir.arch);
	fd = open(dir.ruta, O_RDONLY);
	while((leido = read(fd, aux, sizeof aux)) > 0){
		dir.len += leido;
	}

	return dir;
}
