#include "func.h"		//mi lib para las funciones

extern char * optarg;		//var para getopt
extern int optin,opterr,optopt; //
char * opc_o=NULL;		// -o <arhc_de_salida>	

int main (int argc, char *argv[]){

	char buff[1024];
	int c,nchars,fd_d;
	memset (buff,0,sizeof buff);

	if(argc==1){
		while((nchars = read(STDIN_FILENO,buff,sizeof buff))>0){
			srch(buff,1);//buscar desde STDOUT
		}
	}
	else{
		while((c=getopt(argc,argv, "ho:"))!=-1){			//parseo las opciones del programa
			switch(c){
			case 'h':						//-h brinda el modo de uso por pantalla
				printf("Modo de uso:\n./tp1\t\t\t\t\tmuestra msj filtrado\n");
				printf("./tp1 -o msj_filtrado.txt\t\tmensaje-filtrado en un archivo\n");
				return 0;
			case 'o':
				opc_o=optarg;					//
				printf("archivo a crear:%s\n",opc_o);
				if((fd_d = open (opc_o,O_RDWR|O_CREAT|O_TRUNC,0666))!=-1){ 	//arch result de busqueda
					while((nchars = read(STDIN_FILENO,buff,sizeof buff))>0){
						srch(buff,fd_d);//buscar desde STDOUT
					}	
				}else {
					perror("No pude crear el archivo de salida");
					exit(EXIT_FAILURE);
				}
				close(fd_d);
				return 0;
			}
		}
	   }
	exit(EXIT_SUCCESS);
}
