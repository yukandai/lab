#include <semaphore.h>
#include <stdio.h>	//printf
#include "func.h"
#include "hijo.h"
#include "srch.h"

int hijo(){
	int value=0;
	sem_getvalue(sp,&value);
	printf("sp:%d\n",value);
	if(value==-1) sem_post(sp);
	srch(input);
	sem_post(sp);
	return 0;
	}
