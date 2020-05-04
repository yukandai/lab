import os
import array


path = __file__.replace("probando.py", "")

# size = os.path.getsize(path + "7o.ppm")
p = open(path + "7o.ppm", "rb")
imagen = p.read()

# borro los comentarios de la imagen
for num in range(imagen.count(b"\n# ")):
    comment_start = imagen.find(b"\n# ")
    comment_end = imagen.find(b"\n", comment_start + 1)
    imagen = imagen.replace(imagen[comment_start:comment_end], b"")

# encuentro el tercer \n que es el que delimita al header de la imagen
header_end = imagen.find(b"\n", imagen.find(b"\n", imagen.find(b"\n") + 1) + 1) + 1

# separo el header de el resto de la imagen
header = imagen[:header_end].decode()
body = imagen[header_end:]

# creo una lista con los pixeles como ints
imageList = [i for i in body]


# print(imageList)

# separo cada canal de color y creo una lista para cada uno
redChannel = []
greenChannel = []
blueChannel = []
for num in range(len(imageList)):
    if num % 3 == 0 or num == 0:

        redChannel += [imageList[num]] + [0] + [0]

    elif (num-1) % 3 == 0 or num == 1:
        greenChannel += [0] + [imageList[num]] + [0]

    else:

        blueChannel += [0] + [0] + [imageList[num]]

# la copiada y pegada cosmica ha comenzado: https://solarianprogrammer.com/2017/10/25/ppm-image-python-3/

# creo un bytearray para cada canal de color
rimage = array.array('B', [i for i in redChannel])
gimage = array.array('B', [i for i in greenChannel])
bimage = array.array('B', [i for i in blueChannel])


# creo cada imagen para cada color
with open(path + "red.ppm", "wb", os.O_CREAT) as x:
    x.write(bytearray(header, 'ascii'))
    rimage.tofile(x)

with open(path + "green.ppm", "wb", os.O_CREAT) as x:
    x.write(bytearray(header, 'ascii'))
    gimage.tofile(x)

with open(path + "blue.ppm", "wb", os.O_CREAT) as x:
    x.write(bytearray(header, 'ascii'))
    bimage.tofile(x)

x = open(path + "probando_1.ppm", "wb", os.O_CREAT)
x.write(imagen)
x.close()
