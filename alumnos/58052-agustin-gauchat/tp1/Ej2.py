def suma(n, m):
    ns = 0
    nc = n

    for m in range(0, m):
        ns = int(nc) + ns
        nc = nc + n
    
    return ns


n = input("Ingrese un numero\n")
m = int(input("Ingrese cantidad de veces\n"))
print("El resultado es: ", suma(n, m))