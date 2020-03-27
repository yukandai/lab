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
    
    lista.sort(reverse=True)
    return lista

l = input("Ingrese numeros separado por comas y un espacio\n")

print("Lista ordenada de forma descendente: ", armado_lista(l))



