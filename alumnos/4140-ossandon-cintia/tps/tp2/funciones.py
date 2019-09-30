#!/usr/bin/env python3

import threading
import time
import random

def a_remar():
    print("agarren los remos\n")

def a_bordo():
    print("subido al barco\n")

def hincha_river():
    """ Implementar funcion para subir al bote ....si es que se puede ..."""
    print("nuevo hincha....vamos river\n")

def hincha_boca():
    """ Implementar funcion para subir al bote ....si es que se puede ..."""
    print("nuevo hincha....vamos boca\n")

def barra_brava_river(hinchas, mutex):
    """ Generacion de hinchas de River"""
    while viajes < 20:
        time.sleep(random.randrange(0, 5))
        hr = threading.Thread(target=funciones.hincha_river)
        hr.start()
        mutex.acquire()
        #hincha_river()
        hinchas.append(hr)
        mutex.release()

def barra_brava_boca(hinchas, mutex):
    """ Generacion de hinchas de Boca"""
    while viajes < 20:
        time.sleep(random.randrange(0, 5))
        hb = threading.Thread(target=funciones.hincha_boca)
        hb.start()
        mutex.acquire()
        #hincha_boca()
        hinchas.append(hb)
        mutex.release()
