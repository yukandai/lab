#include "rot13.h"


/*char *rotate(char *palabra){
	int i=0;

	for(i=0; palabra && palabra[i]; ++i){
		if(palabra[i] >= 'a' && palabra[i] <= 'z'){
			palabra[i] = palabra[i]+13;
		}

	} // fin for

return palabra;
	
}
*/

char* rotate(char *p)
{
    size_t i;
    char c;
 
    for (i = 0; p[i] != '\0'; ++i) {
        switch (p[i]) {
            case 'A' ... 'Z':
                c = 'A'; //Escoge el abecedario de mayúsculas.
                break;
            case 'a' ... 'z':
                c = 'a'; //Escoge el abecedario de minúsculas.
                break;
            default:
                continue;
        }
 
        /*  p[i] - c               : Consigue indice en el abecedario.  Ej: A->0,  Z->25, N->13
         *  p[i] - c + 13          : Mueve el indice 13 posiciones.     Ej: A->13, Z->38, N->26
         * (p[i] - c + 13) % 26    : Rota las posiciones.               Ej: A->13, Z->12, N->0
         * (p[i] - c + 13) % 26 + c: Convierte el indice al abecedario. Ej: A->N,  Z->M,  N->A
         */
 
        c = (p[i] - c + 13) % 26 + c;
        p[i] = c;
    }
 
    return p;
}


