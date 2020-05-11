import os
os.system("clear")

lista=[]
archivo=open("histograma.txt","r") #leo la lista del archivo histograma.txt
for linea in archivo.readlines():
    if len(linea)>0 and linea!='\n':
        lista.append(int(linea)) #leo las lineas con datos diferentes de un salto y las guardo en la lista

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
