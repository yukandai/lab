#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "func.h"
#include "hijo.h"

void handlerHijo(int sig){
	char buff[BUF_SIZE];
	int n;
	close(fd_ph[P_WR]);
	close(fd_hp[P_RD]);
	while((n=read(fd_ph[P_RD],buff,sizeof buff))>0){
		rot13(buff,n);
		write(fd_hp[P_WR],buff,n);
		}
}

int rot13(char buffer[BUF_SIZE],int leido){
        char *ptr=NULL;
        int i;

        ptr = buffer;
                for(i=0;i<leido;i++){
                       if(isalpha(*(ptr+i))){
				if(islower(*(ptr+i))){
					
					if((*(ptr+i)+13)>122)
						*(ptr+i)=*(ptr+i)-13;
					else
						*(ptr+i)=*(ptr+i)+13;	
				}
				else{
					if((*(ptr+i)+13)>90)
						*(ptr+i)=*(ptr+i)-13;
					else
						*(ptr+i)=*(ptr+i)+13;

				}
			}
                }
               
        return 0;
}
