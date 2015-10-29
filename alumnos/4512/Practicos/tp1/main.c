#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFF1SIZE 5
#define BUFF2SIZE 80
#define MILONCHAR 30

void _error(int fd,char * funcion) {
    if (fd < 0) {
        perror(funcion);
    }
}

int procesarPalabra(char * buff2, char ** diccionario) {
    
    int i=0, exito = 0;  
    
    //Longitud erronea procesamiento termina si las longitudes no coinciden:
    
    for(i=0;i<3;i++){
        
        if(strlen(buff2) == (strlen(*(diccionario+i))+1)){   
            exito = 1;
            break;
        }
    }   
    if(exito != 1)
        return 0; //no hay match
    
    for( i=0 ; i<3 ; i++ ){
        //printf("*diccionario+%d): %s\n",i,*diccionario+i);
        //printf("i: %d\n",i);
        char * str = strstr(buff2,*(diccionario+i));

        if (str) {            
            strncpy(buff2, "***********************************************************", strlen(*(diccionario+i)));
            break;
        }
    }
    return 1; //hay match
}

int main(int argc, char** argv) {

    //arrays init
    char buff1[BUFF1SIZE];
    char buff2[BUFF2SIZE];    
    int c;
    extern char *optarg;
    int fdi = 0;
    int fdo = 1;

    //char ** diccionario = (char**)calloc(1,8); 
    char ** diccionario = (char**) malloc(3*8); 
    int miembrosDiccionario = 0;
    int bytesread=0;
    int j = 0, i = 0;

    
    //palabras prohibidas

    *(diccionario+0)    = "la";
    *(diccionario+1)    = "de";
    *(diccionario+2)    = "sin";

    
    
    while ((c = getopt(argc, argv, "i:o:h")) != -1) {
        switch (c) {
            case 'i':
                //archivo de entrada
                fdi = open (optarg, O_RDONLY );
                _error(fdi,"open()");
                break;
            case 'o':
                //archivo de salida
                fdo = open(optarg, O_WRONLY | O_CREAT | O_TRUNC, 0640);
                 _error(fdo,"open()");
                break;
            case 'h':
                printf("\n\n\t\tAYUDA\n\n\tFiltrado de palabras en un texto:\n\n-i [camino de archivo]:\tSe especifica el archvio de entrada. \nEn caso de no especificarse, la entrada es por teclado\n\n-o [camino de archivo] Se especifica el archivo de salida. \nEn caso de no especificarse, la salida es por pantallan\n\n\nCreado por Ivan Derlich, Abril 2015\n\n\n");
                exit(0);
                break;
            default:
                printf("default\n");
        }
    }     
        
    
    //abro, comparo y escribo
    while ((bytesread = read(fdi, buff1, (sizeof buff1)+1)) > 1) {
        for (i = 0; i < bytesread; i++) {

            buff2[j] = buff1[i];

            if (buff2[j] == ' ' || buff2[j] == '\n' || buff2[j] == ','|| buff2[j] == ';' || buff2[j] == ':' || buff2[j] == '!'|| buff2[j] == ';') {
                
                buff2[j + 1] = '\0';
                procesarPalabra(buff2,diccionario); 
                write(fdo,buff2,strlen(buff2));                
                j = 0;
                
            } else {
                j++;
            }
            
            //sino carga un caracter mas no se porque
            if(bytesread<BUFF1SIZE){
                break;
            }       
            
        }
        //write(1,buff2,bytesread);
    }
        

    
    //borro la segunda linea de punteros del diccionario
    for(i=0;i<miembrosDiccionario;i++){
        //if(realloc(*(diccionario+i),0)==NULL) 
        if(realloc(*(diccionario+i),0))
            perror("Error a la hora de liberar el espacio ocupado por el diccionario en memoria principal");
    }
    
    //borro la primer linea de punteros de diccionario
    realloc(diccionario,0);
    
    close(fdi);
    close(fdo);

    return (0);
}
