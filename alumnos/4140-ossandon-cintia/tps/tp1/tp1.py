#!/usr/bin/env python3
#encoding=utf8

import multiprocessing

import os
import sys
import time
import getopt

import funciones

#def leer1(queue):
#    leido = queue.get()
#    print(leido)

#def leer2():
#    leido = queue.get()
#    print(leido)

def leer1(queue):
    #leido = queue.get()
    #palabras = leido.split()
    #print(len(palabras))
    while True:
        msg = queue.get()
        palabras = msg.split()
        if (msg == 'DONE'):
            break
        print(len(palabras))

def leer2(queue):
    #leido = queue.get()
    #palabras = leido.split()
    #print(len(palabras))
    while True:
        msg = queue.get()
        palabras = msg.split()
        if (msg == 'DONE'):
            break
        print(len(palabras))

def main():
    try:
        opts, args = getopt.getopt(sys.argv[1:], "f:n:hp:", ["archivo=", "bloque=", "nro="])

        archivo = None
        bloque = None

        for o, a in opts:
            if o == "-f":
                archivo = a
            elif o == "-n":
                bloque = int(a)
            elif o == "-p":
                nro = int(a)
            elif o == "-h":
                print('Ejemplo modo de uso: \n ./tp1.py -f <archivo> -n <tamaño_bloque> \n ./tp1.py -f /etc/services -n 1024')
                sys.exit(2)
            else:
                assert False, "option no válida"

        mensajes = []
        start_index = 0
        end_index = os.stat(archivo).st_size

        mq = multiprocessing.Queue()

        #Lanzamos n hijos
        #for h in range(0, nro): 
        #    p = multiprocessing.Process(target=leer, args=((mq),))
        #    p.start()
        #    p.join()
        #    exec('h{} = multiprocessing.Process()'.format(i))
        #    exec('h{} = start()'.format(i))

        #Lanzamos 2 hijos
        #print('Hijo %d' % (h))
        mq = multiprocessing.Queue()

        h1 = multiprocessing.Process(target=leer1, args=((mq),))
        h2 = multiprocessing.Process(target=leer2, args=((mq),))

        h1.start()
        h2.start()

        with funciones.abrir_archivo(archivo) as file:
            file.seek(start_index)
            leido = file.read(end_index - start_index)

            mq.put(leido)
            #armamos la cola de mensajes
            #mensajes.append(leido)
            #print(leido)

            start_index = end_index + 1
            end_index = start_index + bloque

        # leemos de la cola
        #print(mensajes.pop(0))

        h2.join()
        h1.join()

        file.close()

    except getopt.GetoptError as err:
        print(err)
        sys.exit(2)
    except OSError:
        print('el archivo indicado no existe')
        sys.exit(2)

if __name__ == "__main__":
    main()
