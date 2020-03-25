l = input("Ingrese los numeros separado por comas y un espacio\n")
n = ""
lista = []

for i in (l + " "):
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