#!/usr/bin/python3
import os
import signal
import argparse
import sys

class Señal():
    def __init__(self, arch):
        self.archivo = None
        self.hijo1 = os.fork()
        self.hijo2 = os.fork()
        self.señal1 = False

    def crearArchivo_imprimir(self, signalNumber, frame, arch):
        self.señal1 = True
        self.archivo = open("/home/agus/Computacion2/lab/alumnos/58052-agustin-gauchat/Tp4/"+arch+".txt", "w")
        self.archivo.write(sys.stdin.read())
        os.kill(self.hijo2, signal.SIGUSR2)

    def pasarMayusculas(self, arch):
        self.archivo = open("/home/agus/Computacion2/lab/alumnos/58052-agustin-gauchat/Tp4/"+arch+".txt", "w")
        with open("/home/agus/Computacion2/lab/alumnos/58052-agustin-gauchat/Tp4/"+arch+".txt", "r") as l:
            for i in l:
                for j in i:
                    self.archivo.write(j.upper())

            self.señal1 = True

            os.kill(self.hijo1, signal.SIGUSR1)
            signal.signal(signal.SIGUSR1, self.imprimir)

    def imprimir(sg, frame):
        with open("/home/agus/Computacion2/lab/alumnos/58052-agustin-gauchat/Tp4/archivo.txt", "r") as l:
            for i in l:
                for j in i:
                    print(j.upper(), end="")


if __name__ == "__main__":

    parser = argparse.ArgumentParser(usage="echo \"contenido del archivo\" | ./Ej2.py -f archivo")

    parser.add_argument("-f", "--file", help="Crear archivo")
    args = parser.parse_args()

    señal = Señal(args.file)
    def recibirSeñal(signalNumber, frame):
        if signalNumber == 10 and señal.señal1 == False:
            señal.crearArchivo_imprimir(signalNumber, frame, args.file)
        elif signalNumber == 12:
            señal.pasarMayusculas(args.file)
        elif signalNumber == 10 and señal.señal1 == True:
            señal.imprimir(args.file)

    #Codigo de señal: -10
    signal.signal(signal.SIGUSR1, recibirSeñal)
    #Codigo de señal: -12
    signal.signal(signal.SIGUSR2, recibirSeñal)

    os.kill(señal.hijo1, signal.SIGUSR1)