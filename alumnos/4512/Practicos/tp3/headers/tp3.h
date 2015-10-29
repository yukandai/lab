#ifndef TP3_H
#define	TP3_H
#include <semaphore.h>

#define LMDP 64
#define CANTIDAD_DE_ARREGLOS_CHAR_A_RECORRER 2 //a recorrer para parsear, del TP1
#define PTR_SIZE 8 //para que corra en 64 bits = 8, en 32 bits = 4
#define BLOQUE_DE_LECTURA_DE_DISCO 128
#define COMPARTIDO 1 //flag para semaforos
#define BLOQUEADO 0//para semaforos
#define LISTO 1 //para semaforos
#define PRIMERO 1 //primer argumento para hacer palabra prohibida
#define ULTIMO argc //ultimo argumento para hacer palabra prohibida

typedef enum {
    false = 0, true = 1
} bool;

typedef struct {
    char * mem; //arreglo de palabras de entrada
    sem_t * semH; //semaforo hijo
    sem_t * semP; //semaforo padre
    void* sharedMem; //puntero al espacio de memoria compartida
} datos; //estructura de datos para navegar

void hijo(datos*);
void padre(datos*);
void error(int, const char *);

#endif	/* TP3_H */