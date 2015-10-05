#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>

int numero = 0;

void * hilo1(void *arg){
	int i;

	for(i=0;i<100000;i++){
		numero = numero + 1;
	}
	pthread_exit(NULL);
}

void * hilo2(void *arg){
	int i;

	for(i=0;i<100000;i++){
		numero = numero - 1;
	}
	pthread_exit(NULL);
}

void * hilo3(void *arg){
	int i;

	for(i=0;i<100000;i++){
		numero = numero + 1;
	}
	pthread_exit(NULL);
}

void * hilo4(void *arg){
	int i;

	for(i=0;i<100000;i++){
		numero = numero - 1;
	}
	pthread_exit(NULL);
}

#define MAX_TH 4

int main(){
	
	printf("soy el hilo del main mi pid es: %d\n", getpid());
	pthread_t tid[MAX_TH];
	int i = 4;
		
	pthread_create(&tid[0], NULL, hilo1, NULL);
	pthread_create(&tid[1], NULL, hilo2, NULL);
	pthread_create(&tid[2], NULL, hilo3, NULL);
	pthread_create(&tid[3], NULL, hilo4, NULL);
			

	//printf("i: %d\n", i);
	for(i = 0; i < MAX_TH; i++){
		pthread_join(tid[i], NULL);
	}
	//sleep(1);
	//pthread_exit(NULL);// termina el hilo aca, por mas q siga escribiendo abajo mas funciones..
	//printf("Ahora voy a trabajar solo\n");
	printf("Valor final del numero = %d\n", numero);
	pthread_exit(NULL);
	return 0;
}