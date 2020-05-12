#!/usr/bin/python3

import os
import sys

def abrir_archivo(file):
    '''Abre el archivo indicado en modo lectura'''
    fd = os.open(file, os.O_RDONLY)
    return fd

def crear_archivo(file):
    '''Crea el archivo indicado en modo escritura'''
    fd = os.open(file, os.O_WRONLY | os.O_CREAT)
    return fd

def leer_mensajes(mq, rgb_file, color):
    '''Leemos desde una cola de mensajes y guardamos en el archivo enviado'''
    msg = ""
    fd = crear_archivo(rgb_file)
    rgb_options = color.split(",")
    # print("procesando color: ", rgb_options[0])
    # print("procesando intensidad: ", rgb_options[1])
    while msg != "DONE":
        #try:
        msg = mq.get()
        block = procesar_color(msg, rgb_options)
        os.write(fd, block)
        #except TypeError as error:
        #    print("TypeError: {0}".format(error))
            #sys.exit(2)
        #finally:
        #    lock.release()

    os.close(fd)
    print("Proceso exitoso...") #os.getpid()

def procesar_color(bytes, color):
    '''Procesamos el bloque de bytes segun el color enviado'''
    if (color[0] == "R"):
        linea = procesar_rojo(bytes, color[1])
    elif (color[0] == "G"):
        linea = procesar_gris(bytes, color[1])
    else:
        linea = procesar_azul(bytes, color[1])
    return linea

def procesar_rojo(bytes, intensidad):
    #print('procesando rojo con intensidad: ', intensidad)

    # genero las posiciones que tengo q cambiar
    if(bytes[0] == 80):
        start=28
    else:
        start=0
    elem = start
    posiciones = []
    tope = len(bytes)
    while elem < tope:
        posiciones.append(elem)
        elem = elem+3
    #print('ROJO')
    #print(posiciones)

    #cambio mis colores
    contador=0
    rojo=0
    #linea = bytearray()
    linea = []
    for byte in bytes:
        #linea.extend(byte)
        if (contador in posiciones):
            #print(str(contador) + ') COMPONENTE ROJO')
            #print(hex(b))
            #rojo=hex(byte)*hex(intensidad)
            rojo=byte*intensidad
            #print(rojo)
            linea.append(rojo)
        #    linea.extend(b"1")
        else:
            #print(str(contador) + ') OTRO COMPONENTE')
            print(byte)
            linea.append(byte)
        #    linea.extend(byte)
        contador = contador+1

    #print(linea)
    #print(bytes)
    # enter => 0A
    #sys.exit(1)
    return bytes
    #return linea

def procesar_gris(bytes, intensidad):
    print('procesando gris con intensidad: ', intensidad)

    if(bytes[0] == 'P'):
        start=28
    else:
        start=0
    elem = start+1
    posiciones = []
    tope = len(bytes)
    while elem < tope:
        posiciones.append(elem)
        elem = elem+3
    print('GRIS')
    print(posiciones)
    #sys.exit(1)
    return bytes

def procesar_azul(bytes, intensidad):
    print('procesando azul con intensidad: ', intensidad)

    if(bytes[0] == 'P'):
        start=28
    else:
        start=0
    elem = start+2
    posiciones = []
    tope = len(bytes)
    while elem < tope:
        posiciones.append(elem)
        elem = elem+3
    print('AZUL')
    print(posiciones)
    #sys.exit(1)
    return bytes