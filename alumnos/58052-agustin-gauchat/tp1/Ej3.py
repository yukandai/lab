# sudo apt-get install python3-matplotlib para instalar las librerias
from matplotlib.pylab import hist, show

def armado_lista(l):
    n = ""
    lista = []
    
    for i in (l + " "):
        if i != "," and i != " ":
            n = n + i
        else:
            if n != "":
                lista.append(int(n))
            n = ""
    
    return lista

l = input("Ingrese los numeros separado por comas y un espacio\n")
lista = armado_lista(l)

hist(lista, len(lista), (min(lista), max(lista)))
show()