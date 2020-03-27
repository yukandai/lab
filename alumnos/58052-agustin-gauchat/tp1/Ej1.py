def suma(n):
    ns = int(n) + int(n + n) + int(n + n + n)
    return ns

n = input("Ingrese un numero\n")
print("El resultado es: ", suma(n))