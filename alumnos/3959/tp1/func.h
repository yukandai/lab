#ifndef _FUNC_H
	#define _FUNC_H_
	#include <sys/types.h>		//open
	#include <sys/stat.h>		//open
	#include <fcntl.h>		//open
	#include <stdio.h>
	#include <unistd.h>		//getopt
	#include <string.h> 		//memset_strtok_strcmp
	#include <stdlib.h>		//exit

	int srch(char *input,int fd_o);
#endif
