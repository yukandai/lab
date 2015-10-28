#ifndef _HIJO_H
	#define _HIJO_H_

	extern int fd_ph[2],fd_hp[2],fd_hn[2];
	void handlerHijo(int sig);
	int rot13(char buffer[BUF_SIZE],int leido);
#endif
