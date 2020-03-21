
lista=[]

while True:
    try:
        n=int(input("\nIngrese un entero igual o mayor a cero para el histograma: "))
        if(n<0):
            raise ValueError
        lista.append(n)
    except ValueError:
        print("\n**ERROR DE INGRESO** -Ingrese un entero mayor o igual a cero")
    
    a=input("\nDesea finalizar la carga? Y/y: ")
    if(a=='y' or a=='Y'):
        break
    else:
        print("\nLa carga continua por defecto")
        pass

print("\nHISTOGRAMA\n")
for i in range(0,len(lista)):
    for j in range(0,lista[i]):
        print('*',end='')
    print()

