#!/usr/bin/python3

## TP2 - Cintia Ossandon

import os
import sys
import argparse
import threading
import time
import queue
import funciones as fc

content = ""
semR = threading.Semaphore(0)
semG = threading.Semaphore(0)
semB = threading.Semaphore(0)

def main():
    try:
        parser = argparse.ArgumentParser()
        parser.add_argument('-s', '--size SIZE', action="store", dest="bytes", metavar="bloque de lectura", type=int, required=True, help="Bloque de lectura")
        parser.add_argument('-f', '--file FILE', action="store", dest="fsource", metavar="archivo portador", type=str, required=True, help="Archivo a procesar")
        parser.add_argument('-m', '--message FILE', action="store", dest="fmessage", metavar="mensaje esteganografico", type=str, required=True, help="Mensaje a ser leido")
        parser.add_argument('-o', '--output FILE', action="store", dest="foutput", type=str, required=True, help="estego-mensaje")
        parser.add_argument('-e', '--offset PIXELS', action="store", dest="offset", type=int, required=True, help="offset en pixels del inicio del raster")
        parser.add_argument('-i', '--interleave PIXELS', action="store", dest="interleave", type=int, required=True,  help="interleave de modificacion en pixel")
        parser.add_argument('-c', '--cifrado INT(0/1)', action="store", dest="cifrado", type=int, default=0, help="cifrado rot13 al mensaje que se quiere ocultar")

        args = parser.parse_args()

        start_time = time.time()

        block = args.bytes
        source = args.fsource
        output = args.foutput
        offset = args.offset
        interleave = args.interleave
        fmessage = args.fmessage
        encryption = args.cifrado

        l_message = os.stat(fmessage).st_size
        l_source = os.stat(source).st_size
        l_header = 27
        raster = l_source - l_header

        threads = []
        colors = ["R", "G", "B"]
        #barrera = threading.Barrier(3)

        # Validamos el INTERLEAVE
        response = fc.check_interleave(interleave, l_message, raster)
        if (response == False):
            print("EL parametro INTERLEAVE es invalido")
            sys.exit()

        # armamos el comentario
        comment = fc.create_comment(encryption, offset, interleave, l_message)

        #armamos el encabezado
        header = fc.create_header(source, comment)

        # leemos el mensaje
        message = fc.get_file_content(fmessage)

        # si hay q encriptar el mensaje, lanzo un hilo que lo haga
        if (encryption == 1):
            q_encript = queue.Queue()
            h1 = threading.Thread(target=fc.apply_rot13, args=(message, q_encript))
            threads.append(h1)
            h1.start()

        # si encriptamos el mensaje, lo leo de la cola
        if (encryption == 1):
            message = q_encript.get()

        # lanzamos los 3 hilos
        for h in range(1, 4): #4
            h = threading.Thread(target=fc.process_color, args=(colors[h-1], offset, interleave, l_message, message))
            threads.append(h)
            h.start()

        # guardamos el encabezado
        fc.save_header(header, output)

        # leemos la imagen, se la mandamos a los hilos y esperamos la respuesta
        fd_source = fc.open_file_for_read(source)
        os.lseek(fd_source, 28, 0) #nos posicionamos despues del encabezado
        read = os.read(fd_source, block)
        fd_write = fc.open_or_create_file(output, os.O_WRONLY | os.O_CREAT)
        os.write(fd_write, bytearray(header))
        data = ""
        # vamos leyendo el archivo y se lo mandamos a los hilos
        while read:
            content = read
            # libero los hilos
            semR.release()
            semG.release()
            semB.release()
            # bloqueo los hilos
            semR.acquire()
            semG.acquire()
            semB.acquire()
            # leemos el contenido procesado
            os.write(fd_write, content)
            read = os.read(fd_source, block)
        os.close(fd_source)

        # le indico que ya no hay mas que escribir
        content = "DONE"

        # libero los hilos
        semR.release()
        semG.release()
        semB.release()

        # Espero a q los hilos terminen
        for h in threads:
            h.join()

        # Tiempo total de ejecucion
        elapsed_time = time.time() - start_time
        print("Tiempo de ejecucion: %0.10f seconds." % elapsed_time)

    except OSError as error:
        print("OSError: {0}".format(error))
        sys.exit(2)

if __name__ == "__main__":
    main()
