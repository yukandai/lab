import os
import multiprocessing as mp
from argparse import ArgumentParser
import time
import sys


class ArchivoError(Exception):
    pass


class ValError(Exception):
    pass


class Proceso():
    def main(self):
        # Creo los argumentos
        args = self.argumentos()
        # Creo una variable que contenga al path absoluto
        path = os.path.abspath(os.getcwd())
        size = int(args.size)
        archivo = open(path + "/" + args.file, "rb")
        # Creo las colas
        self.queuer = mp.Queue()
        self.queueg = mp.Queue()
        self.queueb = mp.Queue()
        self.leer_datos(archivo, size)
        archivo.close()
        # Creo los hijos
        self.child_r = mp.Process(target=self.filtro_r, args=(self.queuer,
                                  args.red, args.file))
        self.child_g = mp.Process(target=self.filtro_g, args=(self.queueg,
                                  args.green, args.file))
        self.child_b = mp.Process(target=self.filtro_b, args=(self.queueb,
                                  args.blue, args.file))
        # Los inicio
        time.sleep(1)
        self.child_r.start()
        time.sleep(1)
        self.child_g.start()
        time.sleep(1)
        self.child_b.start()
        # El padre espera a que finalicen
        os.system("eog {}/{} &".format(path, args.file))
        self.child_r.join()
        self.child_g.join()
        self.child_b.join()
        print("Se generaron correctamente los 3 filtros")

    def leer_datos(self, archivo, size):
        while True:
            text = archivo.read(size + 15)
            self.queuer.put(text)
            self.queueg.put(text)
            self.queueb.put(text)
            if not text:
                break

    def eliminar_comentario(self, text):
        # Le saco el comentario a la imagen
        for i in range(text.count(b"\n#")):
            inicio = text.find(b"\n# ")
            fin = text.find(b"\n", inicio + 1)
            text = text.replace(text[inicio:fin], b"")
        return text

    def header(self, text):
        # Le saco el encabezado a la imagen
        header = text[:15].decode()
        header = header.replace("P6", "P3")
        raster = text[15:]
        raster_imagen = [i for i in raster]
        return header, raster_imagen

    def argumentos(self):
        # parser = ArgumentParser(description='TP1')
        # creo la instancia del parser
        parser = ArgumentParser(description='Tp1 - procesa ppm')
        parser.add_argument('-f', '--file',
                            default="No ingreso nada", help="Archivo a"
                                    " procesar")
        parser.add_argument('-s', '--size',
                            default=1024, help="Bloque de lectura")
        parser.add_argument('-r', '--red',
                            default=1, help="Escala para rojo")
        parser.add_argument('-g', '--green',
                            default=1, help="Escala para verde")
        parser.add_argument('-b', '--blue', default=1, help="Escala para azul")
        args = parser.parse_args()
        # hago un manejo de error en caso de que ingrese un archivo vacio
        text = ""
        try:
            if args.file == "No ingreso nada":
                raise ArchivoError()
        except ArchivoError:
            text += "Error. Ingrese un archivo ppm que se encuentre en el"
            text += " mismo directorio"
            print(text)
            sys.exit()
        try:
            if int(args.size) < 0:
                raise ValError()
        except ValError:
            print("Error. El tamaño del bloque no puede ser negativo")
            sys.exit()
        try:
            archivo = open(args.file, "rb")
            archivo.close()
        except FileNotFoundError:
            print("Error. El archivo no se encuentra en el directorio")
            sys.exit()
        try:
            if float(args.red) < 0 or float(args.green) < 0 or float(args.blue) < 0:
                raise ValError()
        except ValError:
            print("Error. Las escalas de los colores no pueden ser negativas")
            sys.exit()
        return args

    def filtro_r(self, queue, intensidad, archivo):
        leido = b""
        # Leo la cola
        while True:
            leido += queue.get()
            if queue.empty():
                break
        # Limpio el texto y separo la cabecera del cuerpo
        text = self.eliminar_comentario(leido)
        header, raster_image = self.header(text)
        # Modifico los valores de los pixeles
        if intensidad != 1:
            for i in range(0, (len(raster_image)-3), 3):
                raster_image[i] = round(float(raster_image[i]) *
                                        float(intensidad))
                raster_image[i + 1] = 0
                raster_image[i + 2] = 0
        # Creo la nueva imagen ppm
            body = ""
            n = 0
            for x in raster_image:
                n += 1
                body += str(x) + " "
                if n % 9 == 0:
                    body += "\n"
            imagen = open("r_" + archivo, "w")
            imagen.write(header + "\n")
            imagen.write(body)
            imagen.close()
            path = os.path.abspath(os.getcwd())
            os.system("eog {} &".format(path))

    def filtro_g(self, queue, intensidad, archivo):
        leido = b""
        while True:
            leido += queue.get()
            if queue.empty():
                break
        text = self.eliminar_comentario(leido)
        header, raster_image = self.header(text)
        if intensidad != 1:
            for i in range(0, (len(raster_image)-3), 3):
                raster_image[i + 1] = round(float(raster_image[i + 1]) *
                                            float(intensidad))
                raster_image[i] = 0
                raster_image[i + 2] = 0
            body = ""
            n = 0
            for x in raster_image:
                n += 1
                body += str(x) + " "
                if n % 9 == 0:
                    body += "\n"
            imagen = open("g_" + archivo, "w")
            imagen.write(header + "\n")
            imagen.write(body)
            imagen.close()
            path = os.path.abspath(os.getcwd())
            os.system("eog {} &".format(path))

    def filtro_b(self, queue, intensidad, archivo):
        leido = b""
        while True:
            leido += queue.get()
            if queue.empty():
                break
        text = self.eliminar_comentario(leido)
        header, raster_image = self.header(text)
        if intensidad != 1:
            for i in range(0, (len(raster_image)-3), 3):
                raster_image[i + 2] = round(float(raster_image[i + 2]) *
                                            float(intensidad))
                raster_image[i] = 0
                raster_image[i + 1] = 0
            body = ""
            n = 0
            for x in raster_image:
                n += 1
                body += str(x) + " "
                if n % 9 == 0:
                    body += "\n"
            imagen = open("b_" + archivo, "w")
            imagen.write(header + "\n")
            imagen.write(body)
            imagen.close()
            path = os.path.abspath(os.getcwd())
            os.system("eog {} &".format(path))


if __name__ == "__main__":
    x = Proceso()
    x.main()
