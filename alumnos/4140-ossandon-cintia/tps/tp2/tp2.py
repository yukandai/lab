#!/usr/bin/env python3
#encoding=utf8

""" TP2 para ejercitar sincronizacion y sus problemas"""

import threading
import time
import random

import funciones

def main():
    mutex = threading.Lock()
    #hinchas = []
    lugares_bote = []
    viajes = 0

    t1 = threading.Thread(target=funciones.barra_brava_boca, args=(viajes, lugares_bote, mutex,))
    t2 = threading.Thread(target=funciones.barra_brava_river, args=(viajes, lugares_bote, mutex,))

    t1.start()
    t2.start()

    print("----- INICIO ----- \n")
    print("viajes = %s \n" % (viajes))
    print("lugares ocupados = %s \n" % (len(lugares_bote)))
    print("subidos = %s \n" % lugares_bote)
    print("------------------ \n")

    # si estan ocupados todos los lugares en el bote, inicio un viaje y limpio el bote
    # while viajes < 20:
        #print("chequeando lugares... \n")
        #if len(lugares_bote) > 4:
        #    lugares_bote.append(hinchas.pop(0))
        #    funciones.a_bordo()
        #elif len(lugares_bote) == 4:
        #    viajes = viajes + 1
        #    del lugares_bote[:]

    while viajes < 20:
        print("lugares bote = %s \n" % (len(lugares_bote)))
        if len(lugares_bote) == 4:
            mutex.acquire()
            viajes = viajes + 1
            print("viaje realizado con = %s \n" % (lugares_bote))
            del lugares_bote[:]
            print("bote vacio \n")
            mutex.release()

    t1.join()
    t2.join()

    print("----- FIN ----- \n")
    print("viajes realizados = %s \n" % (viajes))
    print("terminaron los viajes\n")
    print("------------------ \n")

if __name__ == "__main__":
    main()