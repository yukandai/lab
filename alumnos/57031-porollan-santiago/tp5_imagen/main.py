import argparse
from wand.image import Image


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Procesar imagen")
    parser.add_argument("-f", dest="archivo", type=str, help="Nombre de la imagen formato ppm", required=True)
    parser.add_argument("-n", dest="tam", type=int, default=64, help="Tamaño del bloque de bytes")
    args = parser.parse_args()
    #with Image(width=100, height=100, pseudo='plasma:') as img: 
    #    img.save(filename='P6.ppm') 

    # If you specify "compression='no'", you will get P3 (uncompressed ASCII)
    #with Image(width=100, height=100, pseudo='plasma:') as img: 
    #    img.compression = 'no' 
    #    img.save(filename='P3.ppm')
    f = Image(filename=args.archivo)
    f.compression = 'no'
    f.save(filename='new_dow.ppm')
    with open("new_"+args.archivo, 'w') as newf:
        for line in f:
            print(line)
