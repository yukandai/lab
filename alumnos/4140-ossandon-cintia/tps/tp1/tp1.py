#!/usr/bin/env python3
#encoding=utf8

import os
import sys
import time
import getopt
import multiprocessing

import funciones

def leer(mq, cant):
    while True:
        msg = mq.get()
        palabras = msg.split()
        if (msg == 'DONE'):
            break
        cant += len(palabras)
        print('palabras: ' , len(palabras), os.getpid(), cant)
        #print('H1: TOTAL: %d' % cant)
        #print('\n************')
        #cant = cant + len(palabras)
        #return cant

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
                print('Ejemplo modo de uso: \n ./tp1.py -f <archivo> -n <tamaño_bloque> -p <cant hijos> \n ./tp1.py -f /etc/services -n 1024 -p 3')
                sys.exit(2)
            else:
                assert False, "option no válida"

        start_index = 0
        cant = 0

        mq = multiprocessing.Queue()

        #Lanzamos n hijos
        for h in range(0, nro):
            h = multiprocessing.Process(target=leer, args=(mq, cant,))
            h.start()

        #h1 = multiprocessing.Process(target=leer, args=(mq, cant,))
        #h2 = multiprocessing.Process(target=leer, args=(mq, cant,))

        #h1.start()
        #h2.start()

        with funciones.abrir_archivo(archivo) as file:
            file.seek(start_index)
            leido = file.read(bloque)
            while leido:
                mq.put(leido)
                start_index = start_index + bloque
                file.seek(start_index)
                leido = file.read(bloque)

        file.close()

        #time.sleep(3)

        for h in range(0, nro):
            h.join()

        #h2.join()
        #h1.join()

        #print('\nterminando padre')

        print('\npalabras totales: %d' % cant)

    except getopt.GetoptError as err:
        print(err)
        sys.exit(2)
    except OSError:
        print('el archivo indicado no existe')
        sys.exit(2)

if __name__ == "__main__":
    main()
