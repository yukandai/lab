#!/usr/bin/python3
import argparse
import os

parser = argparse.ArgumentParser(usage="/fork_argumentos_getopt_multiple.py -v -c arg1", description="Los argumentos validos son -v (verboso) -c (cantidad de hijos)")

parser.add_argument("-v", "--verboso", action="store_true", default=False, help="Mostrar proceso")
parser.add_argument("-c", "--contador", type=int, help="Cantidad de hijos")

args = parser.parse_args()

if args.verboso == True:
    print("...Modo verboso...\n")
    print("Argumentos ingresados: ", args._get_kwargs())
    
    for i in range(0, args.contador):

        pros = os.forkpty()
        exp = 2 ** int(input("Ingrese exponente >"))
        print("Exponente:", exp)
        print("PID hijo:", pros[0])
        print("PID padre", os.getppid())