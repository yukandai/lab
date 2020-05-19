import argparse
import multiprocessing as mp
import time


def lector(cola):
    print("Hijo iniciado\n")
    while True:

        if not cola.empty():
            leido = cola.get()
            leido = leido.replace("\n", "")
            #if leido == '':
            #    break
            print ("Leyendo: " + leido[::-1].upper())


if __name__ == '__main__':
    cola = mp.Queue()
    parser = argparse.ArgumentParser(description='python3 ej1.py -f pasar.txt')
    parser.add_argument('-f', action="store", metavar='archivo', type=str,
                        required=True, help="Archivo a abrir")
    args = parser.parse_args()

    hijo = mp.Process(target=lector, args=(cola,))
    hijo.start()

    with open(args.f, 'r') as f:
        print("\nEscribiendo...")
        for linea in f:
            #time.sleep(1)
            cola.put(linea)
    f.close()
