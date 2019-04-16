#!/usr/bin/python3

import os

origen  = input("ingrese archivo origen: ")
destino = input("ingrese archivo destino: ")

try:
    #abrimos el archivo origen solo para lectura
    o = open(origen, 'r')

    #abrimos el archivo destino, sino existe lo creamos, y escribimos en él
    d = open(destino, 'w')

    read_data = o.read()

    d.write(read_data)

    d.close()
    o.close()
except FileNotFoundError:
    print("el archivo de origen no existe")
