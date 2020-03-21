import string

numero = int(input("Ingrese un valor para la variable n:  "))
if numero<=0:
    print("ERROR\n Ingrese un Valor mayor a cero:")

num_string=''
lista=[]
j=0
while(j<3):
    num_string+=str(numero)
    lista.append(int(num_string))
    j+=1
    print(lista)

calculo=0
for i in range(0,3):
    calculo+=lista[i]
    
print("\nEl calculo es:",calculo)

