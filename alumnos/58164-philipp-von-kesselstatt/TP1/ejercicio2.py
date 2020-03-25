def ejercicio2(n, m):

    w = ""
    resultado = 0

    for loop in range(m):
        w += str(n)

    for item in w:
        resultado += int(w)
        w = w[1:]

    return (resultado)


# print(ejercicio2(4, 5))
