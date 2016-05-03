#include <unistd.h>


int main(int argc, char **argv)
{
	int fd[2],leido;
	char buff[100];
	if (pipe(fd) < 0){
		perror("pipe()");
		return -1;
	}
	if(fork()){
		while(leido!=0){
			leido = read(STDIN_FILENO, buff, sizeof buff);
			write(fd[1],buff,leido);
			}
		return 0;
	}
	while(leido!=0){
		leido = read(fd[0],buff,sizeof buff);
		write(STDOUT_FILENO,buff,leido);
	}
	return 0;
}
