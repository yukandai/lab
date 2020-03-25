l = input("Ingrese numeros separado por comas y un espacio\n")
n = ""
lista = []

for i in (l + " "):
    if i != "," and i != " ":
        n = n + i
    else:
        if n != "":
            lista.append(int(n))
        n = ""