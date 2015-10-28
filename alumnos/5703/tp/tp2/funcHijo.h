#ifndef _HIJO_H_
	#define _HIJO_H_

	#include <stdio.h>
	#include <unistd.h>
	#include <signal.h>

	int flag = 0;

	void sigusr1(int procPadre, int pah[2], int hap[2]);
	void sigusr2(int procPadre, int argc, char *argv[], int hap[2], int han[2]);

#endif