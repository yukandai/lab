#!/usr/bin/python3
import argparse

parser = argparse.ArgumentParser(usage="./calculadora.py n1 [s|r|m|d] n2 -t tipo", description="Calculadora")
parser.add_argument("calculadora", type=float, help="Calculadora primitiva", metavar="")
parser.add_argument("-s", "--suma", type=float, help="Sumar n1 y n2", metavar="")
parser.add_argument("-r", "--resta", type=float, help="Restar n1 y n2", metavar="")
parser.add_argument("-m", "--multiplicacion", type=float, help="Multiplicar n1 y n2", metavar="")
parser.add_argument("-d", "--division", type=float, help="Dividir n1 y n2", metavar="")
parser.add_argument("-t", "--tipo", help="Tipos: int o float", metavar="")

args = parser.parse_args()

def calcular(tipo):
    if tipo == "float":
        if args.suma != None:
            answer = float(args.calculadora) + float(args.suma)
        elif args.resta != None:
            answer = float(args.calculadora) - float(args.resta)
        elif args.multiplicacion != None:
            answer = float(args.calculadora) * float(args.multiplicacion)
        elif args.division != None:
            answer = float(args.calculadora) / float(args.division)

        return float(answer)

    if tipo == "int":
        if args.suma != None:
            answer = int(args.calculadora) + int(args.suma)
        elif args.resta != None:
            answer = int(args.calculadora) - int(args.resta)
        elif args.multiplicacion != None:
            answer = int(args.calculadora) * int(args.multiplicacion)
        elif args.division != None:
            answer = int(args.calculadora) / int(args.division)

        return int(answer)

print(calcular(args.tipo))
