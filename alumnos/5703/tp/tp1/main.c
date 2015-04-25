#include "editMessage.h"

int main(int argc, char **argv){

	int option, fd, file = 0, i, m_long;
	char buff[SIZE], buff2[SIZE];	

	while ((option = getopt(argc, argv, "o:h")) >= 0 ){ //Manejo argumentos
		switch (option){
            case 'o': //guardo mensaje en otro archivo
				file= open( optarg , O_RDWR | O_CREAT, 0777);

				if(file < 0 ){
					perror("open()");
					return -1;
				}

				break;

		    case 'h': //imprimo mensaje de ayuda
		    	help();
		    	return -1;

		    default: //mensaje de error si ingresa otro comando
				printf("No se reconoce el comando, por favor ejecuta ./tp1 -h por ayuda\n");
				return 0;
		}
	}

	if(argc < 2){
		char *noArg = "Ingrese al menos una palabra para filtrar. \n";
		write(1, noArg, strlen (noArg));
		return -1;
	}

	while((fd = read(0, buff, sizeof buff)) > 0 ){
		strcpy(buff2,buff);
		m_long=0;
		
		for(i = 1; i < argc; i++){
			strcpy(buff2,replace_filter(buff2, argv[i] , ""));
			m_long = m_long + strlen(argv[i]);
		}

		if(file)
			write(file, buff2 , fd-m_long);
		else
			write(1, buff2, fd-m_long);
	}

	return 0;
}
