#ifndef _EDITMESSAGE_H_
#define _EDITMESSAGE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define SIZE 500
	
	char * replace_filter(char *message, char *filter, char *replace);
	void help();
  
#endif

