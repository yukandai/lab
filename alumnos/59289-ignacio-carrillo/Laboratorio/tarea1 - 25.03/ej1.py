#1 - Realize un programa al que se le da un nro (n) por argumento y el resultado 
# será n + nn + nnn. 
#Por ejemplo si ingreso 9 el resultado será 9 + 99 + 999 = 1107

import os
os.system("clear")

def rellenar(valor):
    k=0
    ns='' #inicializo ns como string
    nv=[] #inicializo la lista
    while(k<3): 
        ns+=str(valor) #completo el string con el formato pedido
        nv.append(int(ns)) #lo guardo en componentes de nv como enteros
        k+=1
    return nv

if __name__ == "__main__":
    nv=rellenar(9)
    calculo=0
    for i in range(0,3):
        calculo+=nv[i] #realizo el calculo

    print("\nEl calculo es: ",end='')
    for i in range(0,3):
        if(i==0):
            print(nv[i],end='')
        else:
            print(" +",nv[i],end='')
    print(" =",calculo,"\n")