#Ejercicio 3: histograma con argumentos
import sys

lista = []
cantidad = len(sys.argv)
#dependiendo de la cantidad de caracteres de la lista 
#sera la cantidad de "barras" del histograma
#al recorrer la lista se dibujan n asteriscos * siendo n
#el numero en la lista
def crear_histograma(lista,caracter="*"): 
    for i in lista:
        print (caracter * i)

if (len(sys.argv) > 1):
    #Lee todos los valores que son ingresados como argumentos
    valor=sys.argv[1:] 
    for elemento in valor:
        lista.append(int(elemento))
    print lista
    print "Histograma de", int(cantidad)-1 , "numeros"
    crear_histograma(lista)
else:
    print "No ha ingresado argumentos"