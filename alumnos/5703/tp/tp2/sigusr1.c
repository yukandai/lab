#include "sigusr1.h"
#include "global.h"

char rot13(char s);

void sigusr1(int procPadre, int pah[2], int hap[2]){	
	int leo,i;
	char buff[MAX]; 
	char buff2[MAX];
	
	close(pah[WRITE]);
	while((leo = read(pah[READ],buff, sizeof buff)) > 0){
		for(i = 0; i < leo; i++){
		    *(buff2+i) = rot13(*(buff+i));
		}
		//lo escribo en el pipe2
		close(hap[READ]);
		write(hap[WRITE],buff2, leo);
		close(hap[WRITE]);
	}
	close(pah[READ]);

	kill(procPadre, 23); //despierto al padre despues de escribir en hap(pipe2)
}

char rot13(char c) {
    if (isalpha(c)) {
        char alpha = islower(c) ? 'a' : 'A';
        return (c - alpha + 13) % 26 + alpha;
    }
    return c;
}