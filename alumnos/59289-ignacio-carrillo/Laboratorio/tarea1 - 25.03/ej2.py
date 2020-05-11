#2 - Modificar el programa anterior, ingresando un segundo nro (m) por argumento, que será el
# encargado de indicar cuantas sumas se harán.Por ejemplo si ingreso 4 y 5 
#  el resultado será 4 + 44 + 444 + 4444 + 44444 = 49380
import os
os.system("clear")

def rellenar(valor,iterar):
    k=0
    ns='' #inicializo ns como string
    nv=[] #inicializo la lista
    while(k<iterar): 
        ns+=str(valor) #completo el string con el formato pedido
        nv.append(int(ns)) #lo guardo en componentes de nv como enteros
        k+=1
    return nv

if __name__ == "__main__":
    iteracion=4
    nv=rellenar(3,iteracion)
    calculo=0
    for i in range(iteracion):
        calculo+=nv[i] #realizo el calculo

    print("\nEl calculo es: ",end='')
    for i in range(0,iteracion):
        if(i==0):
            print(nv[i],end='')
        else:
            print(" +",nv[i],end='')
    print(" =",calculo,"\n")