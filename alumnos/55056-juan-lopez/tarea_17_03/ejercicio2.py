#Ejercicio 2: suma con argumentos
import sys

if (len(sys.argv) > 1):
    #Lee el primero y segundo argumento
    entrada=sys.argv[1]
    entrada2=sys.argv[2]
    i=int(entrada2)
    salida=''
    salidanum=0
    while i > 0:
        i=i-1
        salida = (str(entrada)
                 + salida)
        salidanum = (int(salida)
                    + salidanum)
        #print salida
    
    print "resultado de la suma: ",str(salidanum)
    
    
else:
    print "Indicar 2 numeros como argumento para realizar la suma"

