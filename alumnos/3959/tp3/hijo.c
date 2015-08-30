#include <semaphore.h>
#include "func.h"
#include "hijo.h"
#include "srch.h"

int hijo(){
	sem_wait(sp);
	srch();
	sem_post(sp);
	return 0;
	}
