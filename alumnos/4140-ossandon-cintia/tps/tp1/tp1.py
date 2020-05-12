#!/usr/bin/python3

## TP1 - Cintia Ossandon

import os
import sys
import argparse
import multiprocessing as mp
import funciones as fc

def main():
    try:
        parser = argparse.ArgumentParser(description='Arrays')
        parser.add_argument('-f', '--file', action="store", dest="a_origen", metavar="archivo origen", type=str, required=True, help="Archivo a procesar")
        parser.add_argument('-s', '--size', action="store", dest="n_bytes", metavar="numero de bytes", type=int, required=True, help="Bloque de lectura")
        parser.add_argument('-r', '--red', action="store", dest="r", default=1, help="RED Escala para rojo")
        parser.add_argument('-g', '--green', action="store", dest="g", default=1, help="GREEN Escala para verde")
        parser.add_argument('-b', '--blue', action="store", dest="b", default=1, help="BLUE Escala para azul")
        args = parser.parse_args()
        #print(args)

        colores = ["R," + str(args.r), "G," + str(args.g), "B," + str(args.b)]
        procesos = []
        colas = []

        #Creamos 3 procesos
        for h in range(1, 2):
            name = "color_" + str(h) + ".ppm"
            mq = mp.Queue()
            colas.append(mq)
            h = mp.Process(target=fc.leer_mensajes, args=(mq,name,colores[h-1]))
            procesos.append(h)
            h.start()

        #Leemos el archivo
        fd = fc.abrir_archivo(args.a_origen)
        #os.lseek(fd,28,0)
        leido = os.read(fd, args.n_bytes)
        while leido:
            for mq in colas:
                mq.put(leido)
            leido = os.read(fd, args.n_bytes)
        os.close(fd)

        #Le indicamos a los procesos que ya terminamos de poner elementos en la cola
        for mq in colas:
            mq.put("DONE")

        #Espero a q los procesos terminen
        for h in procesos:
            h.join()

        print("Terminamos.....")

    except OSError as error:
        print("OSError: {0}".format(error))
        #sys.exit(2)

if __name__ == "__main__":
    main()