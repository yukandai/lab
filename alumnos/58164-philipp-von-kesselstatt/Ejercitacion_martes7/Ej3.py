#!/usr/bin/python3

path = __file__.replace("Ej3.py", "")

texto = open(path + "archivo.csv").read()
texto = texto.split("\n")[1:-1]

lines = [item.split(",") for item in texto]

for item in lines:
    if int(item[4]) > 1200:
        print(item[1])
