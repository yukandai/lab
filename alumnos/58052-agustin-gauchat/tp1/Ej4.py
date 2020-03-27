# sudo apt-get install python3-matplotlib para instalar las librerias
from matplotlib.pylab import hist, show

lista = []
n = ""
with open("/home/agus/Computacion2/lab/alumnos/58052-agustin-gauchat/tp1/Numeros.txt", "r") as l:


    for j in l:
        for i in (j + " "):
            if i != "," and i != " ":
                n = n + i
            else:
                if n != "":
                    lista.append(int(n))
                n = ""

hist(lista, len(lista), (min(lista), max(lista)))
show()