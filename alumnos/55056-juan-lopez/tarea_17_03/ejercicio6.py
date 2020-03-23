#Ejercicio 6 lista ordenada con entrada de numero con ,
import sys
lista = []
def ordenar(entrada,separador):
    #separa los argumentos de entrada en una lista
    lista_string=entrada.split(separador) 
    for elemento in lista_string:
        #convierte lista_string en una lista de integrer 
        lista.append(int(elemento)) 
    #con sort(reverse=True) ordenamos una lista en forma descendentes
    lista.sort(reverse=True) 
    return lista

if (len(sys.argv) > 1):
    entrada=sys.argv[1]
    #Llama a la funcion enviandole el argumento de entrada
    print "Lista ordenada",ordenar(entrada,",")
else:
    print "No ha ingresado argumentos"
