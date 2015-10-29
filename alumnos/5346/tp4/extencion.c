#include"funciones.h"

int extencion(int fd2 , char* tipo){


	printf("esto es tipo %s \n\n",tipo);

	if((strncmp("html",tipo,4))==0 ){
		printf("estoy en html \n\n\n");
		write (fd2, "HTTP/1.1 200 OK\r\n" , 17);

		write(fd2,"Content-Type: text/html; charset=UTF-8\r\n", 39);
		return 0;      
	}

	else if((strncmp("jpeg",tipo,4))==0){
		printf("estoy en jpeg \n\n");
		write (fd2, "HTTP/1.1 200 OK\r\n" , 17);
		write(fd2,"Content-Type: image/jpeg; charset=UTF-8\r\n", 41);
		return 0;

	}
	else if((strncmp("jpg",tipo,3))==0){
		printf("estoy en jpg");
		write (fd2, "HTTP/1.1 200 OK\r\n" , 17);
		write(fd2,"Content-Type: image/jpg; charset=UTF-8\r\n", 40);
		return 0;

	}
	else if((strncmp("png",tipo,3))==0){
		write (fd2, "HTTP/1.1 200 OK\r\n" , 17);
		printf("estoy en png \n\n\n");
		write(fd2,"Content-Type: image/png; charset=UTF-8\r\n", 40);
		return 0;

	}
	else if((strncmp("pdf",tipo,3))==0){
		printf("estoy en pdf \n\n\n");
		write (fd2, "HTTP/1.1 200 OK\r\n" , 17);

		write(fd2,"Content-Type: application/pdf; charset=UTF-8\r\n", 46);
		return 0;

	}


	else{
		printf("estoy en no funciona \n\n\n");
		write(fd2,"HTTP/1.1 404 Not Found\r\n", 24);

		return -1;
	}

}

