#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include "func.h"
#include "srch.h"

int srch(char *input){		//input es el *dato
	char *str1;				//puntero para el TOKEN
	int i,pt=0,chk=0;
	char out_buff[BUF_SIZE]; 		//buffer de la salida filtrada
        char *palabras[10];
	char point[BUF_SIZE];			//para recobrar separadores
	char relleno[20];			//asteriscos
	int n_palabras=0;

	memset(out_buff,0,sizeof out_buff);
	memset(point,0,sizeof point);
	memset(relleno,'*',sizeof relleno); 	//conjunto de '*' para  completar
	strcpy(&point[0],input);		//input se destruye cuando pasa por strtok, asi que la copio
	
	for(i=0,str1=strtok(words,",");str1!=NULL;str1=strtok(NULL,","),i++){	//parseo las palabras a filtrar
		palabras[i]=str1;
	}
	n_palabras=i; 					//guardo las cantidad de palabras a filtrar

	for(str1=strtok(input," \n\t,.");str1!=NULL;str1=strtok(NULL," \n\t,."),chk=0){ 	//en strtok el 2° argumento son los delimitadores
		for(i=0;i<n_palabras;i++){
			if(((strcmp(str1,palabras[i]))==0)&&chk==0){		//comparo cada palabra para ver si las imprimo
			//	printf("palabra filtrada:%s\n",palabras[i]);
				chk=1;
			}
		}
		for( ;str1[0]!=point[pt];pt++){				//for para recobrar el separador de la cadena original
			strncat(out_buff,&point[pt],1);			
		}
		pt=pt+(strlen(str1));					//puntero para dejar marcado el siguiente separador
			
		if(chk!=1){ strcat(out_buff,str1); }			//si no esta filtrada la agrego al buff de salida
		else { strncat(out_buff,relleno,strlen(str1)); }	//agrego asteriscos para remplazar la palabra

	}
	strcpy(input,out_buff);
	msync(input,strlen(out_buff), MS_ASYNC);
	return 0;
}
