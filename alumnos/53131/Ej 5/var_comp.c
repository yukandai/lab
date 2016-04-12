#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_TH 4
#define COUNT_LIMIT 4

int count;
pthread_mutex_t mut_varc;
pthread_cond_t cv_varc;


void* incrementar( void *argu){
    
    pthread_mutex_lock(&mut_varc);
    count++;
    
    printf ("Count (hilo %lu): %d\n", *((unsigned long*) argu), count);
    pthread_cond_signal (&cv_varc);
    pthread_mutex_unlock (&mut_varc);
       
    pthread_exit(NULL);

}



int main (int argc, char**argv){
    
    pthread_t id_hilo[MAX_TH];
    int i=MAX_TH;
    count=0;
    pthread_mutex_init (&mut_varc, NULL);
    pthread_cond_init (&cv_varc, NULL);
    
    while (i--){     
         if (( pthread_create(&id_hilo[i], NULL, incrementar, (void*) &id_hilo[i]))){
            perror ("creat: ");
            return -1;    
            }
    }

    pthread_mutex_lock (&mut_varc);
    
    while (count<COUNT_LIMIT){
        pthread_cond_wait (&cv_varc, &mut_varc);    
    }
    pthread_mutex_unlock (&mut_varc);
    /* La variable i es -1 porque al hacer (i--), primero es evaluada i 
     * y después es decrementada.
     * Al llegar a i=0, se evaluada i, es decrementada, y luego se sale del loop.
     */
    
    printf ("i:%d\n", i);
    for (i=0; i<MAX_TH; i++){
        pthread_join(id_hilo[i], NULL);
    }
    return 0;

}
