#include "funcHijo.h"
#include "global.h"

void senalHijo (int nro){
	flag = 1;
}

void senalNieto(int nro){
	flag = 2;
}

void hijoEsperaSenal(int procPadre, int argc, char *argv[], int pah[2], int hap[2]){
	if(flag == 1){ //llamo a la funcion del hijo
		sigusr1(procPadre, pah, hap);
	} 
	else if(flag == 2){ //llamo a la funcion del nieto
		sigusr2(procPadre, argc, argv, pah, hap);
	}
	else { //lo dejo esperando hasta que llegue la señal
		sleep(2);
		hijoEsperaSenal(procPadre, argc, argv, pah, hap);
	}
}

void funcionHijo(int argc, char *argv[], int pah[2], int hap[2]){
	signal(SIGUSR1, senalHijo);
	signal(SIGUSR2, senalNieto);
		
	printf("Proceso Hijo  Nro: %d - Esperando señal...\n",getpid());
	
	hijoEsperaSenal(getpid()-1, argc, argv, pah, hap);
}