#!/usr/bin/env python3

import threading
import time
import random

def hincha_river():
    """ Implementar funcion para subir al bote ....si es que se puede ..."""
    print("vamos river")

def hincha_boca():
    """ Implementar funcion para subir al bote ....si es que se puede ..."""
    print("vamos boca")

def barra_brava_river(viajes, lugares_bote):
    """ Generacion de hinchas de River"""
    while viajes < 5:
        print("nuevo hincha de river")
        time.sleep(random.randrange(0, 5))
        hr = threading.Thread(target=hincha_river)
        lugares_bote.append(hr)
        # todos los hilos deben ejecutar el metodo "a_bordo()" y solo uno de ellos el metodo "a_remar()"  
        hr.start()

def barra_brava_boca(viajes, lugares_bote):
    """ Generacion de hinchas de Boca"""
    while viajes < 5:
        print("nuevo hincha de boca")
        time.sleep(random.randrange(0, 5))
        hb = threading.Thread(target=hincha_boca)
        lugares_bote.append(hb)
        # todos los hilos deben ejecutar el metodo "a_bordo()" y solo uno de ellos el metodo "a_remar()"
        hb.start()