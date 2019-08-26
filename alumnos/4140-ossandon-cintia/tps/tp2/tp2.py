#!/usr/bin/env python3
#encoding=utf8

""" TP2 para ejercitar sincronizacion y sus problemas"""

import threading
import time
import random

import funciones

def main():
    lugares_bote = []
    viajes = 0

    t1 = threading.Thread(target=funciones.barra_brava_boca, args=(viajes, lugares_bote,))
    t2 = threading.Thread(target=funciones.barra_brava_river, args=(viajes, lugares_bote,))

    t1.start()
    t2.start()

    # si estan ocupados todos los lugares en el bote, inicio un viaje y limpio el bote
    while viajes < 5:
        if len(lugares_bote) == 4:
            viajes = viajes + 1
            print("--- nuevo viaje (%s) ---" % (viajes))
            del lugares_bote[:]

    #print(viajes)
    #print(len(lugares_bote))

    t1.join()
    t2.join()

    print("terminaron los viajes")

if __name__ == "__main__":
    main()