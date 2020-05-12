import argparse, os, time
import multiprocessing as mp


def get_color(color):
    if color == 0:
        return "red"
    if color == 1:
        return "green"
    if color == 2:
        return "blue"


def procesar_imagen(filename, color, added, conn):
    leido, count = conn.recv()
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
    if leido:
        procesar_imagen(filename, color, added, conn)


def escribir_headers(args, leido):
    processes = []
    exitcode = 0
    for color in range(3):
        p = mp.Process(target=escribir_header, args=(args.archivo,
                                                     leido, color))
        p.start()
        processes.append(p)
    for process in processes:
        process.join()
        exitcode = exitcode or process.exitcode
    return exitcode


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
    parser.add_argument("-r", dest="red", type=int, default=[25], metavar="RED",
                        nargs=1, help="Valor color rojo")
    parser.add_argument("-g", dest="green", type=int, default=[25], metavar="GREEN",
                        nargs=1, help="Valor color verde")
    parser.add_argument("-b", dest="blue", type=int, default=[25], metavar="BLUE",
                        nargs=1, help="Valor color azul")
    return parser.parse_args()


if __name__ == '__main__':
    args = get_arguments()
    try:
        fd = os.open(args.archivo, os.O_RDONLY)
    except FileNotFoundError:
        exitcode = 1
        print("No se ha encontrado el archivo")
    else:
        exitcode = 0
    child_conns = [None, None, None]
    parent_conns = [None, None, None]
    parent_conns[0], child_conns[0] = mp.Pipe()
    parent_conns[1], child_conns[1] = mp.Pipe()
    parent_conns[2], child_conns[2] = mp.Pipe()

    # escribir header
    tiempo_inicial = time.time()
    if not exitcode:
        leido = os.read(fd, 15)        
        exitcode = escribir_headers(args, leido)
    # escribir el resto
    colors = [args.red[0], args.green[0], args.blue[0]]
    counts = [0, 0, 0]
    processes = []
    for color in range(3):
        p = mp.Process(target=procesar_imagen,
                        args=(args.archivo, color, colors[color],
                                child_conns[color]))
        p.start()
        processes.append(p)
    while not exitcode and leido:
        try:
            leido = os.read(fd, args.tam)
        except MemoryError:
            exitcode = 1
            print("Error de memoria")
            continue
        for color in range(3):
            parent_conns[color].send((leido, counts[color]))
        for color in range(3):
            counts[color] = parent_conns[color].recv()
    for process in processes:
        process.join()
        exitcode = exitcode or process.exitcode
    tiempo_final = time.time()
    if not exitcode:
        print("Se generaron correctamente los 3 filtros")
    else:
        print("Ha ocurrido un error")
    print("Completado en", tiempo_final - tiempo_inicial, "segundos")
