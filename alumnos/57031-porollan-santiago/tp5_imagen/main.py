import argparse
import os
import sys
import multiprocessing as mp


def get_color(color):
    if color == 0:
        return "red"
    if color == 1:
        return "green"
    if color == 2:
        return "blue"


def process_image(filename, leido, color):
    newleido = []
    for l in leido:
        newl = l
        newleido.append(newl)
    newimage = bytes(newleido)
    color_str = get_color(color)
    with open(filename + "_" + color_str + ".ppm", 'ab') as ni:
        ni.write(newimage)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Procesar imagen")
    parser.add_argument("-f", dest="archivo", type=str, help="Nombre de la imagen formato ppm", required=True)
    parser.add_argument("-n", dest="tam", type=int, help="Tamaño del bloque de bytes", default=256)
    parser.add_argument("-r", dest="red", metavar="RED", nargs=1, required=True, help="Color rojo")
    parser.add_argument("-g", dest="green", metavar="GREEN", nargs=1, required=True, help="Color verde")
    parser.add_argument("-b", dest="blue", metavar="BLUE", nargs=1, required=True, help="Color azul")
    leido = 1
    with open("newimage.ppm", 'wb') as bi:
        pass
    args = parser.parse_args()
    fd = os.open(args.archivo, os.O_RDONLY)
    while leido:
        leido = os.read(fd, args.tam)
        processes = []
        for color in range(3):
            p = mp.Process(target=process_image, args=(args.archivo, leido, color))
            p.start()
            processes.append(p)
        for process in  processes:
            process.join()
