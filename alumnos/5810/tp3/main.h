/* 
 * File:   main.h
 * Author: francisco
 *
 * Created on August 27, 2015, 6:28 AM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif


    pid_t hijo;

    sem_t *sem_1, *sem_2;

    char *mem;

    int *membits;

    char delim[] = " \t\r\n\f";

    char * result;

    char * strptr;

    char * aux;

    char * token;

    char * cen1;

    char buff[100];

    int bits = 0;

    int i = 0, opt, countflag = 0;

    int leido;

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */
