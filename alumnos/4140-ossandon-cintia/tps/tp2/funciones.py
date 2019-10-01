#!/usr/bin/env python3

import threading
import time
import random

def a_remar():
    print("agarren los remos\n")

def a_bordo():
    print("subido al barco\n")

def hincha_river(lugares_bote, mutex):
    """ Implementar funcion para subir al bote ....si es que se puede ..."""
    print("nuevo hincha....vamos river\n")
    if len(lugares_bote) > 4:
        mutex.acquire()
        lugares_bote.append('HR')
        a_bordo()
        mutex.release()

def hincha_boca(lugares_bote, mutex):
    """ Implementar funcion para subir al bote ....si es que se puede ..."""
    print("nuevo hincha....vamos boca\n")
    if len(lugares_bote) > 4:
        mutex.acquire()
        lugares_bote.append('HB')
        a_bordo()
        mutex.release()

def barra_brava_river(viajes, lugares_bote, mutex):
    """ Generacion de hinchas de River"""
    while viajes < 20:
        time.sleep(random.randrange(0, 5))
        hr = threading.Thread(target=hincha_river, args=(lugares_bote, mutex,))
        hr.start()
        # --------------------------------------------------
        #mutex.acquire()
        #hinchas.append(hr)
        #mutex.release()
        hr.join()

def barra_brava_boca(viajes, lugares_bote, mutex):
    """ Generacion de hinchas de Boca"""
    while viajes < 20:
        time.sleep(random.randrange(0, 5))
        hb = threading.Thread(target=hincha_boca, args=(lugares_bote, mutex,))
        hb.start()
        # --------------------------------------------------
        #mutex.acquire()
        #hinchas.append(hb)
        #mutex.release()
        hb.join()
