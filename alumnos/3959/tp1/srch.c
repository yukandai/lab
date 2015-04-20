#include "func.h"

int srch(char *input, int fd_o){
	char *str1;				//puntero para el TOKEN
	int i,chk=0;
	char out_buff[1024]; 			//buffer de la salida filtrada
        char *palabras[]={"hola","como"};	//palabras a buscar		
	
	memset(out_buff,0,sizeof out_buff);
	for(str1=strtok(input," ");str1!=NULL;str1=strtok(NULL," "),chk=0){
		for(i=0;i<2 ;i++){
			if(((strcmp(str1,palabras[i]))==0)&&chk==0){	//comparo cada palabra para ver si las imprimo
									//con valor devuelto por strcmp puedo dar tolerancia a la comparación
				//printf("palabra filtrada:%s\n",palabras[i]);
				chk=1;
			}
		}
		if(chk!=1){						//sino esta filtrada la agrago al buff de salida	
			strcat(out_buff,str1);				
			strcat(out_buff," ");				//agrego un espacio ya que strtok los quita
		}
	}
	if(fd_o!=-1)	write (fd_o,out_buff,strlen (out_buff));
	else if(fd_o==-1) write (STDOUT_FILENO,out_buff,sizeof out_buff);
	return 0;
}
