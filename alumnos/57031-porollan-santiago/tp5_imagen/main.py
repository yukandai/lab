import argparse, os, time
import multiprocessing as mp


def get_color(color):
    if color == 0:
        return "red"
    if color == 1:
        return "green"
    if color == 2:
        return "blue"


def procesar_imagen(filename, leido, color, added, count, conn):
    newimage_arr = []
    for color_value in leido:
        if count == color:
            newl = color_value + added
            newl = 255 if newl > 255 else newl
        else:
            newl = color_value
        newimage_arr.append(newl)
        count += 1
        if count == 3:
            count = 0
    newimage = bytes(newimage_arr)
    color_str = get_color(color)
    with open(filename[:-4] + "_" + color_str + ".ppm", 'ab') as ni:
        ni.write(newimage)
    conn.send(count)


def escribir_headers(args, leido):
    processes = []
    for color in range(3):
        p = mp.Process(target=escribir_header, args=(args.archivo,
                                                     leido, color))
        p.start()
        processes.append(p)
    for process in processes:
        process.join()


def escribir_header(filename, leido, color):
    with open(filename[:-4] + "_" + get_color(color) + ".ppm", 'wb') as ni:
        ni.write(bytes(list(leido)))


def get_arguments():
    parser = argparse.ArgumentParser(description="Procesar imagen")
    parser.add_argument("-f", dest="archivo", type=str,
                        help="Nombre de la imagen formato ppm", required=True)
    parser.add_argument("-n", dest="tam", type=int, metavar="SIZE",
                        required=True, help="Tamaño del bloque de bytes",
                        default=256)
    parser.add_argument("-r", dest="red", type=int, metavar="RED",
                        nargs=1, help="Valor color rojo")
    parser.add_argument("-g", dest="green", type=int, metavar="GREEN",
                        nargs=1, help="Valor color verde")
    parser.add_argument("-b", dest="blue", type=int, metavar="BLUE",
                        nargs=1, help="Valor color azul")
    return parser.parse_args()


if __name__ == '__main__':
    args = get_arguments()
    fd = os.open(args.archivo, os.O_RDONLY)
    child_conns = [None, None, None]
    parent_conns = [None, None, None]
    parent_conns[0], child_conns[0] = mp.Pipe()
    parent_conns[1], child_conns[1] = mp.Pipe()
    parent_conns[2], child_conns[2] = mp.Pipe()

    # escribir header
    leido = os.read(fd, 15)
    tiempo_inicial = time.time()
    escribir_headers(args, leido)
    # escribir el resto
    colors = [args.red[0], args.green[0], args.blue[0]]
    counts = [0, 0, 0]
    while leido:
        leido = os.read(fd, args.tam)
        processes = []
        for color in range(3):
            p = mp.Process(target=procesar_imagen,
                           args=(args.archivo, leido, color, colors[color],
                                 counts[color], child_conns[color]))
            p.start()
            processes.append(p)
        for color in range(3):
            counts[color] = parent_conns[color].recv()
        for process in processes:
            process.join()
    tiempo_final = time.time()
    print("completado en", tiempo_final - tiempo_inicial, "segundos")
