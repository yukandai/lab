import argparse, os, time
import multiprocessing as mp


def get_color(color):
    if color == 0:
        return "red"
    if color == 1:
        return "green"
    if color == 2:
        return "blue"


def process_image(filename, leido, color, added, count, conn):
    newleido = []
    for l in leido:
        if count == color:
            newl = l + added
            newl = 255 if newl > 255 else newl
        else:
            newl = l        
        newleido.append(newl)
        count += 1
        if count == 3:
            count = 0
    newimage = bytes(newleido)
    color_str = get_color(color)
    with open(filename[:-4] + "_" + color_str + ".ppm", 'ab') as ni:
        ni.write(newimage)
    conn.send(count)


def process_image_header(filename, leido, color):
    newleido = []
    for l in leido:
        newl = l
        newleido.append(newl)
    newimage = bytes(newleido)
    color_str = get_color(color)
    with open(filename[:-4] + "_" + color_str + ".ppm", 'wb') as ni:
        ni.write(newimage)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Procesar imagen")
    parser.add_argument("-f", dest="archivo", type=str, help="Nombre de la imagen formato ppm", required=True)
    parser.add_argument("-n", dest="tam", type=int, help="Tamaño del bloque de bytes", default=256)
    parser.add_argument("-r", dest="red", type=int, metavar="RED", nargs=1, required=True, help="Color rojo")
    parser.add_argument("-g", dest="green", type=int, metavar="GREEN", nargs=1, required=True, help="Color verde")
    parser.add_argument("-b", dest="blue", type=int, metavar="BLUE", nargs=1, required=True, help="Color azul")
    args = parser.parse_args()
    fd = os.open(args.archivo, os.O_RDONLY)
    parent_conn_red, child_conn_red = mp.Pipe()
    parent_conn_green, child_conn_green = mp.Pipe()
    parent_conn_blue, child_conn_blue = mp.Pipe()

    # escribir header
    leido = os.read(fd, 15)
    # print("EMPIEZA: ", hex(leido[15]))
    processes = []
    tiempo_inicial = time.time()
    for color in range(3):
        p = mp.Process(target=process_image_header, args=(args.archivo, leido, color))
        p.start()
        processes.append(p)
    for process in  processes:
        process.join()

    # escribir el resto
    red_count = 0
    green_count = 0
    blue_count = 0
    while leido:
        leido = os.read(fd, args.tam)
        processes = []
        for color in range(3):
            if color == 0:
                added = args.red[0]
                count = red_count
                child_conn = child_conn_red
            elif color == 1:
                added = args.green[0]
                count = green_count
                child_conn = child_conn_green
            elif color == 2:
                added = args.blue[0]
                count = blue_count
                child_conn = child_conn_blue
            p = mp.Process(target=process_image, args=(args.archivo, leido, color,
                                                       added, count, child_conn))
            p.start()
            processes.append(p)
        red_count = parent_conn_red.recv()
        green_count = parent_conn_green.recv()
        blue_count = parent_conn_blue.recv()
        for process in  processes:
            process.join()
    tiempo_final = time.time()
    print("completado en",tiempo_final - tiempo_inicial, "segundos")
