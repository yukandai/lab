def ejercicio6(lista):

    lista = lista.split(",")

    lista = [int(num) for num in lista]

    lista.sort(reverse=True)

    return lista


# print(ejercicio6("5,77,8,33,6,45,3"))
