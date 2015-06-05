#include "funcPadre.h"
#include "global.h"

void senalPadre(int nro){
	flagPadre = 1;
}

int funcPadre(int hap[2]){
	int leo;
	char buff[MAX];

	close(hap[WRITE]);
	leo = read(hap[READ],buff, sizeof buff);
	close(hap[READ]);
	
	write(STDOUT_FILENO, buff, leo);

	return 0;
}

void padreEspera(int hap[2]){
	if(flagPadre == 0){
		sleep(2);
		padreEspera(hap);
	}else{
		funcPadre(hap);
	}
}

void padreEmpieza(int pah[2], int hap[2]){
	char buff[MAX];
	int leido;

	signal(SIGURG ,senalPadre); //23 SIGURG
	
	printf("Proceso Padre Nro: %d\n", getpid()); //muestro el numero del proceso
		
	leido = read(STDIN_FILENO, buff, sizeof buff);	
	
	close(pah[READ]);
	write(pah[WRITE], buff, leido);
	close(pah[WRITE]);
	
	padreEspera(hap);
}