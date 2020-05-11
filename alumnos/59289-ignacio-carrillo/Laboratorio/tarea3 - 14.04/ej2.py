import argparse
import os 
import time

def calculo(n,m):
    return n**m

parser = argparse.ArgumentParser(prog='Calculadora de potencia')
parser.add_argument('-n','--base',action='store',nargs=1,type=int,required=True,metavar='',help='Numero a elevar ')
parser.add_argument('-m','--exp',action='store',nargs=1,type=int,required=True,metavar='',help='Exponente')
parser.add_argument('-v','--verbose',action='store_true',default=False,help='Modo verboso')

argumentos=parser.parse_args()
print("\nPID Pinicial: ",os.getpid())
print("Creando hijo...")
hijo=os.fork()
if hijo ==0:
    print("\nSoy el hijo {}, creado por: {}".format(os.getpid(),os.getppid()))
    if argumentos.verbose==True:
        print("\n...Modo verboso...")
        print("Base: {} | Exponente: {}".format(argumentos.base[0],argumentos.exp[0]))
        print("Resultado: {}".format(calculo(argumentos.base[0],argumentos.exp[0])))

    else:
        print("Resultado: ",calculo(argumentos.base[0],argumentos.exp[0]))
    print("\nTermino hijo")
    exit(0)

os.wait() #espero al hijo
print("Termino padre")