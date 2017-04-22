#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){

int leido, i, countpal=0, countesp=0, countorac=0,tmpint ;
char buff[1000],tmp[1475],espec[14]="áéíóúüñ", orac[6]=". \n\t", pal[6]=" \n\t";
char *ptr;

while ( leido = read(STDIN_FILENO,buff, sizeof buff) > 0){
write(STDOUT_FILENO,buff, sizeof buff);

ptr = strtok( buff, espec );
while( (ptr = strtok( NULL, espec )) != NULL ){
     countesp++;
     
} 

ptr = strtok( buff, orac );
while( (ptr = strtok( NULL, orac )) != NULL ){
     //countorac++;
     
}

ptr = strtok( buff, pal );
while( (ptr = strtok( NULL, pal )) != NULL ){
     //countpal++;
     
}
//printf("leido: %d\n", sizeof buff);
	for(i=0; i<sizeof buff;i++){
		if (( (buff[i] == 32 || buff[i] == 46 || buff[i] == 10 || buff[i] == 40)&& ((buff[i+1] >= 65 && buff[i+1] <= 90 ) || (buff[i+1] >= 97 && buff[i+1] <= 121 )) )){
			buff[i] = '/';
			countpal++;
		}		
		
		if ((buff[i] == 46 && buff[i+1] != 46) ){
			countorac++;
		}
	}

//write(STDOUT_FILENO,buff, sizeof buff);
memset(buff,0,sizeof buff);
}


//write(STDOUT_FILENO,"\n*Cantidad de palabras: ", 24);
//printf("\n%d\n", sizeof countpal );
//write(STDOUT_FILENO,"\nCantidad de oraciones: ", 23);
//write(STDOUT_FILENO,countorac, sizeof countorac);
//write(STDOUT_FILENO,"\nCantidad de palabras con caracteres especiales: ", 49);
//write(STDOUT_FILENO,countesp, sizeof countesp);
//write(STDOUT_FILENO,"\n\n", 3);
printf("\n\n*Cantidad de palabras: %d \n",countpal);
printf("*Cantidad de oraciones: %d \n",countorac);
printf("*Cantidad de palabras con caracteres especiales: %d \n",countesp);

	return 0;
}