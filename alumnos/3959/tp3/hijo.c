#include <semaphore.h>
#include "func.h"
#include "hijo.h"
#include "srch.h"

int hijo(char * input){
	sem_wait(sp);
	srch(input);
	sem_post(sp);
	return 0;
	}
