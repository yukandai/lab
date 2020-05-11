#!/usr/bin/python3
import os
import argparse
import array
import time
import multiprocessing
from queue import Empty

try:
    # Argumentos
    parser = argparse.ArgumentParser(description='Tp1 - procesa ppm')
    parser.add_argument('-r', '--red', type=float, default=0, help='Escala para rojo')
    parser.add_argument('-g', '--green', type=float, default=0, help='Escala para verde')
    parser.add_argument('-b', '--blue', type=float, default=0, help='Escala para azul')
    parser.add_argument('-s', '--size', type=int, help='Bloque de lectura')
    parser.add_argument('-f', '--file', help='Archivo a procesar')

    args = parser.parse_args()

    if args.size < 90:
            args.size = 90
    while args.size % 3 != 0:
        args.size += 1

except:
    print("ERROR - Argumentos invalidos")
    exit(1)

try:
    print("El padre", os.getpid(), "esta leyendo el archivo")
    time.sleep(2)

    #Abro la imagen y la leo
    imagen = open("dog.ppm", "rb").read()

    #Fuera comentarios
    for num in range(imagen.count(b"\n# ")):
        com1 = imagen.find(b"\n# ")
        com2 = imagen.find(b"\n", com1 + 1)
        imagen = imagen.replace(imagen[com1:com2], b"")

    finHeader = imagen.find(b"\n", imagen.find(b"\n", imagen.find(b"\n") + 1) + 1) + 1

    #Guardo el header y el body
    header = imagen[:finHeader].decode()
    body = imagen[finHeader:]

    #Pixeles a int
    imageInt = [i for i in body]

    print("Imagen leida correctamente")
except:
    print("ERROR - Error al leer la imagen, verifique la direccion")
    exit(1)


try:
    print("Llamando hijos")

    def prosRojo(queue):
        rojo = []
        while True:
            try:
                imar = queue.get_nowait()
                for num in range(len(imar)):
                    if num % 3 == 0 or num == 0:
                        #Aumento el color con la escala seleccionada
                        r = int(imar[num] * args.red)
                        #Verifico que no supere los 255 bytes 
                        if r > 255:
                            r = 255

                        rojo += [r] + [0] + [0]
            except Empty:
                break

        imagenRojo = array.array('B', [i for i in rojo])
        with open("FiltroRojo_" + args.file, "wb", os.O_CREAT) as x:
            x.write(bytearray(header, 'ascii'))
            imagenRojo.tofile(x)
            x.close()

    def prosVerde(queue):
        verde = []
        while True:
            try:
                ima = queue.get_nowait()
                for num in range(len(ima)):
                    if (num-1) % 3 == 0 or num == 1:
                        v = int(ima[num] * args.green)
                        if v > 255:
                            v = 255

                        verde += [0] + [v] + [0]
            except Empty:
                break

        imagenVerde = array.array('B', [i for i in verde])

        with open("FiltroVerde_" + args.file, "wb", os.O_CREAT) as x:
            x.write(bytearray(header, 'ascii'))
            imagenVerde.tofile(x)
            x.close()

    def prosAzul(queue):
        azul = []
        while True:
            try:
                imaa = queue.get_nowait()
                for num in range(len(imaa)):
                    if num % 3 == 0 or num == 0:
                        #Aumento el color con la escala seleccionada
                        a = int(imaa[num] * args.blue)
                        #Verifico que no supere los 255 bytes 
                        if a > 255:
                            a = 255

                        azul += [0] + [0] + [a]
            except Empty:
                break

        imagenAzul = array.array('B', [i for i in azul])
        with open("FiltroAzul_" + args.file, "wb", os.O_CREAT) as x:
            x.write(bytearray(header, 'ascii'))
            imagenAzul.tofile(x)
            x.close()

    cola = []
    j = 0
    k = []
    for i in range(len(imageInt)):
        k += [imageInt[i]]
        j += 1
        if j == args.size:
            cola.append(k)
            k = []
            j = 0

    qr = multiprocessing.Queue()
    qv = multiprocessing.Queue()
    qa = multiprocessing.Queue()

    for col in cola:
        qr.put(col)
        qv.put(col)
        qa.put(col)

    hr = multiprocessing.Process(target=prosRojo, args=(qr,))
    hv = multiprocessing.Process(target=prosVerde, args=(qv,))
    ha = multiprocessing.Process(target=prosAzul, args=(qa,))

    hr.start()
    hv.start()
    ha.start()

    hr.join()
    hv.join()
    ha.join()

    print("Colores procesados correctamente")

except:
    print("ERROR - No se pudieron procesar los colores")
    exit(2)