#!/usr/bin/env python
#encoding=utf8

import os
import sys
import time
import getopt
import multiprocessing

import funciones

def main():
    try:
        opts, args = getopt.getopt(sys.argv[1:], "f:n:hp:", ["archivo=", "bloque=", "nro="])

        archivo = None
        bloque = None
        nro = None

        for o, a in opts:
            if o == "-f":
                archivo = a
            elif o == "-n":
                bloque = int(a)
            elif o == "-p":
                nro = int(a)
            elif o == "-h":
                print 'Ejemplo modo de uso: \n ./tp1.py -f <archivo> -n <tamaño_bloque> -p <cant hijos> \n ./tp1.py -f /etc/services -n 1024 -p 3'
                sys.exit(2)
            else:
                assert False, "option no válida"

        procesos = []

        mq = multiprocessing.Queue()
        lock = multiprocessing.Lock()
        cant = multiprocessing.Value('i', 0)

        #Creamos n procesos
        for h in range(0, nro):
            h = multiprocessing.Process(target=funciones.leer, args=(mq,cant,lock,))
            procesos.append(h)
            h.start()

        with funciones.abrir_archivo(archivo) as file:
            leido = file.read(bloque)
            while leido:
                mq.put(leido)
                leido = file.read(bloque)

        file.close()

        #Le indicamos a los procesos que ya terminamos de poner elementos en la cola
        for i in procesos:
            mq.put("DONE")

        #Terminamos los procesos
        for h in procesos:
            h.join()

        print '\npalabras totales: ', cant.value

    except getopt.GetoptError as err:
        print(err)
        sys.exit(2)
    except OSError:
        print 'el archivo indicado no existe'
        sys.exit(2)

if __name__ == "__main__":
    main()
