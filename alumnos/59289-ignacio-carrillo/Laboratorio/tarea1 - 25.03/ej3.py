#3 - Rescriba un programa que cree un histograma de una lista de enteros 
# ingresados por teclado. 

import os
import string
os.system("clear")

lista=[] #inicializo la lista

while True: #manejo de excepciones
    try:
        n=int(input("\nIngrese un entero igual o mayor a cero para el histograma: ")) #enteros mayor o igual a cero para hist
        if(n<0):
            raise ValueError #si es negativo, error
        lista.append(n) #guardo el valor ingresado en la lista
    except ValueError:
        print("\n**ERROR DE INGRESO** -Ingrese un entero mayor o igual a cero") #mensaje de error
    
    a=input("\nDesea finalizar la carga? Y // Pulse enter para continuar la carga: ") #control de lista dinamica
    if(a=='y' or a=='Y'):
        os.system("clear")
        break
    os.system("clear")

print("\nHISTOGRAMA\n") #impresion histograma
listah=[]
for i in range(0,len(lista)):
    reps=lista.count(lista[i])
    if (lista[i],reps) not in listah:
        listah.append((lista[i],reps))

for i in range(len(listah)):
    for j in range(listah[i][1]):
        if j==0:
            print((str(listah[i][0])).zfill(2),end=" |") #imprimo el valor almacenado en la lista con 2 digitos
            print("*",end='') #impresion pura del histograma
        else:
            print('*',end='')
    print()
print()





        
    