#!/usr/bin/python3

path = __file__.replace("Ej2.py", "")
archivo1 = input("ingrese archivo origen: ")
archivo2 = input("ingrese archivo destino: ")

texto1 = open(path + archivo1).read()
texto2 = open(path + archivo2, "w").write(texto1)
