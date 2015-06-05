#ifndef _NIETO_H_
#define _NIETO_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/types.h>
    #include <ctype.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <sys/wait.h>
    #include <signal.h>



//        void funcionNieto(char *buffer,int nieto_escribe_hijo,int nieto_lee_hijo);
//        void senal(int nro);
  //      char *escribirEnPadre (char *buffer, int la);
		void funcionNieto2(int nieto_escribe_padre,int nieto_lee_padre, int padre_escribe_hijo, int padre_lee_hijo);
		void funcionHijoNieto(int nieto_escribe_padre, int nieto_lee_padre);
		void funcionNieto(int nieto_lee_hijo,int nieto_escribe_padre);



#endif

