
import argparse
import sys
import os
parser = argparse.ArgumentParser(usage="\nAyuda: Los argumentos validos son" +
                                 " -v(verboso) -n (base) -m (exponente)")

parser.add_argument("-n", help="Base", type=int)
parser.add_argument("-m", help="Exponente", type=int)
parser.add_argument("-v", action="store_true", help="Verboso")
args = parser.parse_args()
res = args.n ** args.m

if args.v:
    print("\n...Modo verboso...\nArgumentos ingresados: ")
    print(sys.argv[1:])

    pid = os.fork()
    if pid == 0:        #Tiene hijos?
        print("\nPID padre: " + str(os.getppid()) + "\nCreando hijo....")
        print("\nPID hijo: " + str(os.getpid()) + "\nPotencia: " + str(res))
        print("Creado por: "+str(os.getppid()))



# print(args._get_kwargs())
# print("El numero {} elevado a la {} es: {}".format(args.n, args.m, res))
