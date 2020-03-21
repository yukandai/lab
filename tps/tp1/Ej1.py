import requests

n = input("Ingrese un numero\n")

ns = int(n) + int(n + n) + int(n + n + n)

print("El resultado es: ", ns)