#!/usr/bin/python3
import argparse
import os

parser = argparse.ArgumentParser(usage="/fork_argumentos_getopt.py -v -n arg1 -m arg2", description="Los argumentos validos son -v (verboso) -n (base) -m (exponente)")

parser.add_argument("-v", "--verboso", action="store_true", default=False, help="Mostrar proceso")
parser.add_argument("-n", "--base", type=int, help="Numero base del exponente")
parser.add_argument("-m", "--exponente", type=int, help="Numero exponente")

args = parser.parse_args()

#argumentos = args._get_kwargs()

exp = args.base ** args.exponente

if args.verboso == True:
    print("...Modo verboso...\n")
    print("Argumentos ingresados: ", args._get_kwargs())

    pid = os.fork()
    if pid == 0:
        print("PID padre:", os.getppid())
        print("Creando hijo...")
        print("PID hijo:", os.getpid(), "potencia:", exp, "por:", os.getpid())