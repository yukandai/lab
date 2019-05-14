#!/usr/bin/env python3
import  os
def abrir_archivo(file):
    '''Abre el archivo indicado en modo lectura'''
    f = open(file, 'r')
    return f

def leer(mq,cant):
    msg = ""
    while msg != "chau":
        msg = mq.get()
        palabras = msg.split()
        cant.value += len(palabras)
        print('proceso: ', os.getpid(), 'contadas: ', len(palabras), 'total: ', cant.value)
