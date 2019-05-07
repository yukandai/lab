#!/usr/bin/env python3

def abrir_archivo(file):
    '''Abre el archivo indicado en modo lectura'''
    f = open(file, 'r')
    return f

#def leer():
#    leido = mq.get()
#    return leido

#def leer(queue):
#    while True:
#        msg = queue.get()
#        if (msg == 'DONE'):
#            break
#        print(msg)