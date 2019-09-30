#!/usr/bin/env python3
#encoding=utf8

""" TP2 para ejercitar sincronizacion y sus problemas"""

import threading
import time
import random

import funciones

def main():
    mutex = threading.Lock()
    hinchas = []
    lugares_bote = []
    viajes = 0

    t1 = threading.Thread(target=funciones.barra_brava_boca, args=(hinchas, mutex,))
    t2 = threading.Thread(target=funciones.barra_brava_river, args=(hinchas, mutex,))

    t1.start()
    t2.start()

    #print("----- INICIO ----- \n")
    #print("lugares ocupados = %s \n" % (len(lugares_bote)))
    #print("subidos = %s \n" % lugares_bote)
    #print("------------------ \n")

    #time.sleep(random.randrange(0, 5))

    # si estan ocupados todos los lugares en el bote, inicio un viaje y limpio el bote
    print("viajes = %s \n" % (viajes))
    while viajes < 20:
        print("lugares ocupados = %s \n" % (len(lugares_bote)))
        if len(lugares_bote) > 4:
            #print("subidos = %s \n" % lugares_bote)
            lugares_bote.append(hinchas.pop(0))
            #funciones.a_bordo()
            print("bote = %s \n" % (lugares_bote))
            print("lugares ocupados = %s \n" % (len(lugares_bote)))
        else:
            print("bote lleno = %s \n" % (lugares_bote))
            viajes = viajes + 1
            del lugares_bote[:]

    t1.join()
    t2.join()

    print("viajes realizados = %s \n" % (viajes))
    print("terminaron los viajes\n")

if __name__ == "__main__":
    main()