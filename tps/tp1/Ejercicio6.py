cadena = input("Ingrese la cadena de numeros por comas:")
cadena2= ''
lista=[]

for i in range(0,len(cadena)):
    if (cadena[i]!= ','):
        cadena2= cadena2+cadena[i]
    else:
        lista.append(int(cadena2))        
        cadena2=''

lista.append(int(cadena2))

lista.sort(reverse=True)
print(lista)
        