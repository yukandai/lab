import requests

n = input("Ingrese un numero\n")
m = int(input("Ingrese cantidad de veces\n"))

ns = 0
nc = n

for m in range(0, m):
    ns = int(nc) + ns
    nc = nc + n

print("El resultado es: ", ns)