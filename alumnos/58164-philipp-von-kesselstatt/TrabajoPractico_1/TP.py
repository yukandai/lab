#!/bin/python3

import os
import array
import argparse


# El objeto ImagenPPM tiene:
# -path (el path directorio del archivo)
# -image (el string leido del archivo)
# -header (el header de la imagen PPM)
# -body (el cuerpo de la imagen PPM)
# -imageList (lista con los pixels de la imagen como valores RGB)
# --------------------------------------------------------------------------
# El objetoColorChannel tiene:
# -header (el header de la imagen PPM)
# -filterImage (lista con los valores RGB de la imagen con un solo color)
# -customFilterImage (lista como filterImage pero con la intensidad cambiada)
# +intensity(intensity) (cambia el valor del filtro con un porcentaje)
# +write(path, name) (escribe la imagen en un archivo)
class ImagePPM():
    def __init__(self, path, name):

        self.path = path

        # size = os.path.getsize(path + "7o.ppm")
        archivo = open(self.path + name, "rb")
        self.image = archivo.read()

        # borro los comentarios de la self.image
        for num in range(self.image.count(b"\n# ")):
            commentS = self.image.find(b"\n# ")
            commentE = self.image.find(b"\n", commentS + 1)
            self.image = self.image.replace(self.image[commentS:commentE], b"")

        # encuentro el tercer \n que es el que delimita al header de la imagen
        return_1 = self.image.find(b"\n") + 1

        return_2 = self.image.find(b"\n", return_1) + 1

        header_end = self.image.find(b"\n", return_2) + 1

        # separo el header de el resto de la imagen
        self.header = self.image[:header_end].decode()
        self.body = self.image[header_end:]

        # creo una lista con los pixeles como ints
        self.imageList = [i for i in self.body]

        # print(self.imageList)


class ColorChannel():
    def __init__(self, color, imageList, header, intensity=1):
        self.header = header

        self.filterImage = [0 for i in imageList]

        for i in range(color, len(imageList), 3):
            self.filterImage[i] = imageList[i]

        self.customFilterImage = [int(i * intensity) for i in self.filterImage]

    def intensity(self, intensity):
        self.customFilterImage = [int(i * intensity) for i in self.filterImage]
        return self.customFilterImage

    def write(self, path, name):
        image = array.array('B', self.customFilterImage)

        with open(path + name, "wb", os.O_CREAT) as x:
            x.write(bytearray(self.header, 'ascii'))
            image.tofile(x)


if __name__ == "__main__":

    parser = argparse.ArgumentParser()

    parser.add_argument("-f", "--fileppm", help="ppm file you want to open")
    parser.add_argument("-n", "--bloque", type=int, help="byte block size")
    parser.add_argument("-r", "--red", type=float, help="intensity of the red channel")
    parser.add_argument("-g", "--green", type=float, help="intensity of the green channel")
    parser.add_argument("-b", "--blue", type=float, help="intensity of the blue channel")

    args = parser.parse_args()

    path = __file__.replace("TP.py", "")
    name = args.fileppm

    i = ImagePPM(path, name)

    pids = []

    for num in range(3):
        pids.append(os.fork())
        if pids[num] == 0:
            break

    if 0 in pids:

        if len(pids) == 1:
            intensity = args.red
        elif len(pids) == 2:
            intensity = args.green
        else:
            intensity = args.blue

        color = ColorChannel(len(pids) - 1, i.imageList, i.header, intensity)

        color.write(path, str(os.getpid()) + "output.ppm")
