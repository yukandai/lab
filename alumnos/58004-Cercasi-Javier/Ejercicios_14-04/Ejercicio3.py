
import argparse
import sys
import os
parser = argparse.ArgumentParser(usage="\nAyuda: Los argumentos validos son" +
                                 " -v(verboso) -c(Numero de hijos a crear)")

parser.add_argument("-c", help="Cantidad de hijos", type=int)
parser.add_argument("-v", action="store_true", help="Verboso")
args = parser.parse_args()

if args.v:

    print("\n...Modo verboso...\nArgumentos ingresados: ")
    print(sys.argv[1:])

    for i in range(args.c):
        ex = input("\nIngrese un exponente: ")
        pid = os.fork()

        if pid == 0:
            print("\nPID hijo: " + str(os.getpid()) + "\nPotencia: " +
                  str(2**ex))
            print("Creados por: "+str(os.getppid()))
            exit()      # Que el hijo termine

        else:
            # Soy el padre
            os.wait()   # El padre espera a que terminen los hijos y no cree otro hijo ni finalice
