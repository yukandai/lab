#include "padre.h"
#include "rot13.h"
void funcionPadre(int padre_escribe_hijo, int padre_lee_hijo){


int leido;
int leidos;
char delimitador[] = " \n";
char buffer[1500];
memset(buffer,0,sizeof(buffer));
char buffer2[1500];
memset(buffer2,0,sizeof(buffer2));
char *result = NULL;
char buf[10];
memset(buf,0,sizeof(buf));
char *buf2 = NULL;


	while((leido = read(STDIN_FILENO,buffer,sizeof(buffer))) > 0){
		result = strtok(buffer,delimitador);
		
		while (result != NULL){

			buf2 = strcpy(buf,result);
			
			if ((write(padre_escribe_hijo,buf2,10)) < 0){
				perror ("error en write");
				exit (-1);
			}
			
			result = strtok(NULL,delimitador);
			
			memset(buf,0,sizeof(buf));
		
		} // fin while
			close(padre_escribe_hijo);

	
	while ((leidos = read(padre_lee_hijo,buffer2,sizeof(buffer2))) > 0){

		write(1,buffer2,strlen(buffer2));
//		write(1," ",1);
	}
	close(padre_lee_hijo);
		
write(1,"\n",1);
		
	}//fin while



}
