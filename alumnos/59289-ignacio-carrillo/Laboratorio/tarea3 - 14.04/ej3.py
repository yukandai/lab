import argparse
import os 

def calculo(n):
    while True:
        try:
            m=int(input("Ingrese el exponente: "))
            if m<0:
                raise ValueError
            else:
                break
        except ValueError:
            print("Ingrese un exponente valido")
    return n**m,m

parser = argparse.ArgumentParser(prog='Calculadora de potencia')
parser.add_argument('-n','--base',action='store',nargs=1,type=int,required=True,metavar='',help='Numero a elevar ')
parser.add_argument('-c','--child',action='store',nargs=1,type=int,required=True,metavar='',help='Cantidad de hijos')
parser.add_argument('-v','--verbose',action='store_true',default=False,help='Modo verboso')

argumentos=parser.parse_args()
print("Soy el padre: ",os.getpid())

for i in range(argumentos.child[0]):
    pid=os.fork()

    if (pid==0):
        print("\nSoy el hijo {} --> {}".format(i,os.getpid()))
        print("Mi padre es: ",os.getppid())
        resultado,m=calculo(argumentos.base[0])
        if(argumentos.verbose):
            print("\n...Modo verboso...")
            print("Base: {} | Exponente: {}".format(argumentos.base[0],m))
            print("Resultado: {}".format(resultado))
        else:
            print("\nResultado: ",resultado)
        exit(0)

    else:
        os.wait()






