'''
1- Escriba un programa que lea un archivo definido por argumento y le 
envie cada linea a un hijo, este invertira y pasara a mayuscula lo que se le
envie, luego se lo reenviara transformado al padre quien lo mostrara por
pantalla. La comunicacion se hara mediante pipe

Ej de funcionamiento

$ python3 ej1.py -f pasar.txt

Escribiendo...
Hijo iniciado

ALOH
ETNEG
ED
UPMOC'''

import argparse
import os
import time

parser = argparse.ArgumentParser(description='python3 ej1.py -f pasar.txt')
parser.add_argument('-f', action="store", metavar='archivo', type=str,
                    required=True, help="Archivo a abrir")

args = parser.parse_args()
pipe_r, pipe_w = os.pipe()
pid1 = os.fork()

if pid1 == 0:

    os.close(pipe_w)
    print("Hijo iniciado\n")
    while True:
        leido = os.read(pipe_r, 15).encode()
        leido = leido.replace("\n", "")
        if leido == '':
            break
        print ("Leyendo: " + leido[::-1].upper())

    exit()

else:
    with open(args.f, 'r') as f:
        print("\nEscribiendo...")
        for linea in f:
            time.sleep(1)
            os.write(pipe_w, linea)
    f.close()

os.close(pipe_r)
os.close(pipe_w)
os.wait()
