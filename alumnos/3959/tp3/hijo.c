#include <semaphore.h>
#include "func.h"
#include "hijo.h"
#include "srch.h"

int hijo(){
	srch(input);
	sem_post(sp);
	return 0;
	}
