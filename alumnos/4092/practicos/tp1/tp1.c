/**
 * Trabajo Practico 1
 * Franco Morosini
 */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>

int process(char *input, int len, int salida, char *archi);
void escribir(char *input, int len, char *filtro);

int main(int argc, char **argv){
    	char buff[100000];
	char *archi;
	int leido, opc;
	int salida = 0;
	extern char *optarg;
	extern int optind, opterr, optopt;
	while ((opc = getopt(argc, argv, "o:h"))>0){
		switch(opc){
			case 'o':
				salida = 1;
				archi = optarg;
				break;
			case 'h':
				printf("\nMODO DE USO\ncat Archivo.txt | ./ej1\ncat Archivo.txt | ./ej1 -o SalidaArchivo.txt\n");
				exit(1);
			default:
				printf("\n ./ej1 -h\n");
				exit(1);
		}
	} 
    	memset(buff, 0, sizeof buff);	
	while((leido = read(STDIN_FILENO, buff, sizeof buff)) > 1){
		process(buff,leido,salida,archi);
	}
    	return 0;
}

int process(char *input, int len, int salida, char *archiSalida){
	char buff2[1000];
	char *palabra;
	int fd, leido, fdsalida;
	fd = open("FiltroPalabras.txt",O_RDONLY);
	if (fd < 0){
		write(STDERR_FILENO,"Error al leer fichero\n",22);
		return -1;
	}
	while((leido = read(fd,buff2,sizeof buff2)) > 0){
		palabra = strtok(buff2,",");
		char *token = palabra;
		escribir(input,len,palabra);	
		while((token = strtok(NULL, ",")) != NULL){			
			escribir(input,len,token);
		}
	}
	if (salida == 0){
		return write(STDOUT_FILENO, input, len);
	}
	else{
		fdsalida = open(archiSalida, O_RDWR|O_CREAT|O_TRUNC, 0777);
		return write(fdsalida, input, len);	
	}
}

void escribir(char *input, int len, char *filtro){
	int i,j,x;
	for(i=0;i<len;i++){
		x=0;
		for (j=0; j<strlen(filtro);j++){
			if (filtro[j] != '\0' && filtro[j] != '\n'){
				if (input[i+j] != filtro[j]){
					x=1;
				}
			}
		}
		if (x==0){
			for (j=0; j<strlen(filtro); j++){
				if (filtro[j] != '\0' && filtro[j] != '\n'){
					*(input+i+j) = '*';
				}
			}
		}			
	}
}
