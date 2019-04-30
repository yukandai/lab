#!/usr/bin/env python3

import funciones
import getopt
import sys

def main():
    try:
        opts, args = getopt.getopt(sys.argv[1:], "f:n:h", ["archivo=", "bloque="])

        archivo = None
        bloque = None

        for o, a in opts:
            if o == "-f":
                archivo = a
            elif o == "-n":
                bloque = int(a)
            elif o == "-h":
                print('Ejemplo modo de uso: \n ./tp1.py -f <archivo> -n <tamaño_bloque> \n ./tp1.py -f /etc/services -n 1024')
                sys.exit(2)
            else:
                assert False, "option no válida"

        f_read = funciones.abrir_archivo(archivo)

        #mostramos el conenido del archivo
        print(f_read.read(bloque))

        #TODO: ARMAR COLA DE MENSAJES

        #TODO: LANZAR 2 HIJOS QUE LEAN LOS MENSAJES Y CUENTEN LA CANTIDAD DE PALABRAS

        f_read.close()

    except getopt.GetoptError as err:
        print(err)
        sys.exit(2)
    except FileNotFoundError:
        print("el archivo indicado no existe")
        sys.exit(2)

if __name__ == "__main__":
    main()
