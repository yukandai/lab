import string

numero = int(input("Ingrese un valor para la variable n:  "))
numero2 = int(input("Ingrese un valor m  para indicar cuantas sumas se haran:  "))

if numero and numero2<=0:
    print("ERROR\n Ingrese un Valor mayor a cero:")

num_string=''
lista=[]
j=0
while(j<numero2):
    num_string+=str(numero)
    lista.append(int(num_string))
    j+=1
    print(lista)

calculo=0
for i in range(0,numero2):
    calculo+=lista[i]
    
print("\nEl calculo es:",calculo)
