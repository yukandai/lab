#!/usr/bin/python

import os
import sys
import multiprocessing
import argparse
import getopt

def argumentos():
    parse=argparse.argumentosparse()
    parser.add_argument("-f","--file",dest="patharchivo",nargs=1,required=True,"Input file path")
    parser.add_argument("-s","--size",dest="vertamaño",nargs="?",default=2048,const=1024,type=int,help="Reading chunks size")
    return parse.parse_argumento()

def abirarchivo(path):
    try:
        if os.path.isfile(path):
            return os.open(path, os.O_RDONLY)
        else:
            raise OSError
    except OSError as error:
        print "No se pudo abrir"

def contador(text):
    for char in "-.,\n":
        text=text.replace(char," ")
        text=text.lower()
        return len(text.split())

def leer(fd, tamaño, cola):
    EOF=False
    while not EOF:
        text=os.read(fd,tamaño)
        cola.put(text)
        if len(text)<tamaño:
            EOF=True
    os.close(fd)

def procedimiento(cola,resultado):
    while(cola.csize()!=0):
        text=cola.get()
        palabras=contadorpalabras(text)
        resultado.put(contadorpalabras)
    return

controlador=multiprocessing.Controlador()
cola=multiprocessing.Queue()
resultado=multiprocessing.Queue()

args=argumentos()

fd=abirarchivo(args.patharchivo)

leer(fd,args.vertamaño,cola)

proceso=multiprocessing.Process(target=procedimiento,args=(cola.resultado))
proceso2=multiprocessing.Process(target=procedimiento,args=(cola,resultado))

proceso.inicio()
proceso2.inicio()

proceso.unirse()
proceso2.uniser()

contadorpalabras=0

while(resultado.csize()!=0):
    contadorpalabras=contadorpalabras+int(resultado.get())
print contadorpalabras

print(args.patharchivo,args.vertamaño)