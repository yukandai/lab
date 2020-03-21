lista=[]
archivo=open("histograma.txt","r")

for linea in archivo.readlines():
    if len(linea)>0 and linea!='\n':
        lista.append(int(linea))

print("\nHISTOGRAMA\n")
for i in range(0,len(lista)):
    for j in range(0,lista[i]):
        print("*",end='')
    print()
print()
    
