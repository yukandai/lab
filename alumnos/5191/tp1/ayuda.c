#include "parser.h"


void Ayuda (){
	char *ayuda_texto = "-------------------------AYUDA-------------------------";	
	char *sin_argumento = "cat mensaje.txt | ./tp1";
	char *argumento_o = "cat mensaje.txt | ./tp1 -o mensaje-filtrado.txt";
	char *argumento_h = "cat mensaje.txt | ./tp1 -h";

	write(STDOUT_FILENO,ayuda_texto,strlen(ayuda_texto));
	write(STDOUT_FILENO,"\n",1);	
	write(STDOUT_FILENO,sin_argumento,strlen(sin_argumento));
	write(STDOUT_FILENO,"\n",1);
	write(STDOUT_FILENO,argumento_o,strlen(argumento_o));
	write(STDOUT_FILENO,"\n",1);
	write(STDOUT_FILENO,argumento_h,strlen(argumento_h));	
	write(STDOUT_FILENO,"\n",1);
	

}
