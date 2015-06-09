#include "editMessage.h"

int main(int argc, char **argv){

	int option, fd, file = 1, i, m_long;
	char buff[SIZE], buff2[SIZE], *noComan, *noArg;	

	while ((option = getopt(argc, argv, "o:h")) >= 0 ){ //Manejo argumentos
		switch (option){
            case 'o': //guardo mensaje en otro archivo
				file = open( optarg , O_RDWR | O_CREAT, 0777);
				if( file < 0 ){
					perror("open()");
					return -1;
				}
				break;

		    case 'h': //imprimo mensaje de ayuda
		    	help();
		    	return 0;

		    default: //mensaje de error si ingresa otro comando
				noComan = "No se reconoce el comando, por favor ejecuta ./tp1 -h por ayuda.\n";
				write(STDERR_FILENO, noComan, strlen(noComan));
				return -1;
		}
	}

	if(argc < 2){
		noArg = "Ingrese al menos una palabra para filtrar.\n";
		write(STDOUT_FILENO, noArg, strlen(noArg));
		return -1;
	}

	while((fd = read(STDIN_FILENO, buff, sizeof buff)) > 0 ){
		strcpy(buff2,buff);
		m_long=0;
		
		for(i = 1; i < argc; i++){
			strcpy(buff2, replace_filter(buff2, argv[i], ""));
			m_long = m_long + strlen(argv[i]);
		}
			
		if(file != 1){ //si lo guardo en un archivo borro el largo de los dos primeros parametros: -o nombrearchivo.ext
			m_long = m_long - strlen(argv[1]) - strlen(argv[2]) ;
		}

		write(file, buff2 , fd-m_long); //file va a ser 1 o el nombre del archivo donde quiero escribir	
	}
	return 0;
}
