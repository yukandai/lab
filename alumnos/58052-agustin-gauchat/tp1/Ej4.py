lista = []
n = ""
with open("/home/agus/Computacion2/lab/tps/tp1/Numeros.txt", "r") as l:


    for j in l:
        for i in (j + " "):
            if i != "," and i != " ":
                n = n + i
            else:
                if n != "":
                    lista.append(int(n))
                n = ""

def histograma(lis, cant = "-"):
    for i in lis:
        print(cant * i)

histograma(lista)