#include <stdio.h>
#include <unistd.h>
#include<string.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char **argv)
{
	int i,input_fd, output_fd;
	char buff[2048];
	input_fd = read(STDIN_FILENO,buff,sizeof buff);
	if(input_fd == -1){
		perror("open");
		return 2;
	}
		
	/*output_fd = open("salida.txt",O_RDWR|O_CREAT|O_TRUNC,0666);
	if(output_fd == -1){
		perror("open");
		return 3;
	}*/
	//Cantidad de palabras
	/*
	char *auxP = malloc(sizeof(buff));
	strcpy(auxP, buff);
	
	int palabras = 0;
	char pal[] = " .,:;()-";
	for (char *p = strtok(auxP,pal); p != NULL; p = strtok(NULL,pal))
	{
		palabras++;
	}
	printf("Hay %d palabras\n", palabras);

	//Cantidad de oraciones
	char *auxO = malloc(sizeof(buff));
	strcpy(auxO, buff);
	
	int oraciones = 0;
	char or[] = ".";
	for (char *q = strtok(auxO,or); q != NULL; q = strtok(NULL,or))
	{
		oraciones++;
	}
	printf("Hay %d oraciones\n", oraciones*/	
	write(1,buff,sizeof buff);



	return (0);
}
