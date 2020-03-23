# Ejercicio 4: histograma con manejo de archivos 
import sys
lista = []
def crear_histograma(lista,caracter="*"):
	for i in lista:        
		print (caracter * i)

def leer_archivo(texto):
    #abriendo archivos
    f= open(texto,"r") 
    #leyendo archivo y guardando en entrda
    leido=f.read() 
    #cerrando el descriptor
    f.close()
    return leido

texto="histograma.txt"
entrada=leer_archivo(texto)
print "Valores de entrada de archivo",(entrada) 
#eliminando \n de la entrada
entrada_limpia=entrada.rstrip() 
#conviertiendo la entrada en una lista con cada string separado
lista_string=entrada_limpia.split(" ") 
cantidad=0
for elemento in lista_string:
     #convirtiendo cada string en un int para poder graficar
    lista.append(int(elemento))
    cantidad=cantidad+1
print "Histograma de", int(cantidad) , "numeros"
#graficando
crear_histograma(lista) 