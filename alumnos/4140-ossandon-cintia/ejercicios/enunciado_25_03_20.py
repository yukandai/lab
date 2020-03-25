#!/usr/bin/env python
#encoding=utf8

import sys

#1 - Realize un programa al que se le da un nro (n) por argumento y el resultado será n + nn + nn.
#    Por ejemplo si ingreso 9 el resultado será 9 + 99 + 999 = 1107

#def main():
#	uno = int(sys.argv[1])
#	dos = uno*10+uno
#	tres = dos*10+uno
#	result = uno+dos+tres
#	print result

#2 - Modificar el programa anterior, ingresando un segundo nro (m) por argumento, que será el encargado de indicar cuantas sumas se harán.
#    Por ejemplo si ingreso 4 y 5  el resultado será 4 + 44 + 444 + 4444 + 44444 = 49380

#def main():
#	numero = int(sys.argv[1])
#	cant = int(sys.argv[2])

#	for n in range(1, cant+1):
#		pot = n-1
#		if n==1:
#			ant = numero*(10**pot)
#			result = ant
#		else:
#			ant = numero*(10**pot)+ant
#			result = result + ant
			
#	print result

#3 - Rescriba un programa que cree un histograma de una lista de enteros ingresados por teclado. ¿?

#4 - Modificar el ejercicio anterior para leerlo de un archivo. ¿?

#5 - Describa como funciona el programa siguiente:

#def fibo(n,a=0,b=1):
#   while n!=0:
#      return fibo(n-1,b,a+b)
#   return a

#for i in range(0,10):
#   print(fibo(i))

#A partir de 2 numeros (0,1), cada término es la suma de los dos anteriores.
#Comienza con 0, luego 1, y desde aqui los numeros se generaran a partir de la suma de los anteriores.

#6 - Escriba un programa que acepte una serie de números separados por coma, y genere una lista de python ordenada de manera descendente.
#    ingresando los numeros 5,77,8,33,6,45,38 se debe obtener [77, 45, 33, 8, 6, 5, 3] 

#def main():
#	args = sys.argv[1]
#	l1 = args.split(",")

#	for n in range(0,len(l1)):
#		l1[n] = int(l1[n])

#	print sorted(l1,reverse=True)

###################################################################################################

if __name__ == "__main__":
	main()
