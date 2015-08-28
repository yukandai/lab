#include <semaphore.h>
#include <stdio.h>
#include "func.h"
#include "hijo.h"
#include "srch.h"

int hijo(char *buff){
	sem_post(sp);
	sem_wait(sp);
	srch(buff);
	sem_post(sp);
	return 0;
	}

