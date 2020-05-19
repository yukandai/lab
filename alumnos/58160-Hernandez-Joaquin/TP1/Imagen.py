import os 
import argparse
from multiprocessing import Process,Queue
import sys


def calcular_posicion(imagen):
    for i in range(imagen.count(b"\n# ")): #Si hay comentarios en la imagen
        barra_n_numeral = imagen.find(b"\n#")+1
        barra_n = imagen.find(b"\n", barra_n_numeral) #Ultimo barra antes de arrancar con la imagen
            
    if imagen.count(b"\n# ") == 0: #Si no hay comentarios 
        barra_n = imagen.find(b"\n")
    medidas = imagen.find(b"\n",barra_n+1) 
    profundidad= imagen.find(b"\n", medidas+1)
    return profundidad+1

def procesar_datos(q,id,encabezado,intensidad): #Proceso los datos y los genero
    if id==0:
        nombre="rojo.ppm"    #Nombre a cada archivo
    elif id==1:
        nombre="verde.ppm"
    else:
        nombre="azul.ppm"

    fd=os.open(nombre, os.O_WRONLY | os.O_CREAT)#genero el fd de cada color
    while True:

        if not q.empty():#si la cola no se encuentra vacia 
            imagen=q.get() #leo el mensaje de la cola
            if(imagen=="EOF"):#si ya lei todo el mensaje salgo del bucle
                break         
            if(type(imagen)==list):
                aux=""
                for i in range(len(imagen)):
                    if (type(imagen[i])==int):
                        aux += str(int(imagen[i]*intensidad)) #Multiplico los pixeles de cada archvio por la intesidad
                    else:
                        aux += str(imagen[i])                
                imagen=aux.encode()#escribo en archvio
            os.write(fd,imagen)
    os.close(fd) #cierrro el fd cuando completo el archivo
    print("Proceso {} termino".format(id))

def main():
    parser = argparse.ArgumentParser(description='Trabajo Practico - Imagen ppm')

    parser.add_argument('-r', '--red', default= 1,help='Escala rojo', type=float)
    parser.add_argument('-b', '--blue', default= 1, help='Escala azul', type=float)
    parser.add_argument('-g', '--green', default= 1, help='Escala verde', type=float)
    parser.add_argument('-f', '--file', default='', help='Archivo a procesar',type=str)
    parser.add_argument('-s', '--size', default= 1024,help='Bloque de lectura', type=int)

    args =parser.parse_args()
    
    if(args.size<=0):
        print("ERROR!!! El tamaño del bloque no es correcto")
        sys.exit()

    if (args.red<=0 or args.blue<=0 or args.green<=0):
        print("ERROR!!! Ingrese nuevamente los argumentos")
        sys.exit()

    try:
        archivo = os.open(args.file, os.O_RDONLY)
    except:
        print("El archivo no se encuentra en el directorio")
        sys.exit()

    size =(args.size)
    archivo = os.open(args.file, os.O_RDONLY) #ABRO ARCHIVO
    imagen = os.read(archivo, size)#LEO ARCHIVO
    #print(imagen)
    offset=calcular_posicion(imagen)#POSICION ANTES DEL LA IMAGEN (DEPSUES DEL ENCABEZADO)
    encabezado=imagen[:offset]
    encabezado=encabezado.replace(b'P6',b'P3')
    os.lseek(archivo,offset,0)#posiciono el offset en el archivo


    #creo 3 colas para cada color
    colas=[]
    for i in range(3):
        colas.append(Queue())
        colas[i].put(encabezado)
    idq=0 #ID de cola 

    #Creo 3 hijos uno por cada color
    procesos=[]
    for i in range(3):
        if(i==0):
            intensidad=args.red
        elif(i==1):
            intensidad=args.blue
        else:
            intensidad=args.green
        procesos.append(Process(target=procesar_datos,args=(colas[i],i,encabezado,intensidad)))#Guardo un nuevo proceso con la funcion que tiene que hacer y sus argumentos
        procesos[i].start()

    #Leo imagen completa y paso a enteros 
    while True:
        imagen=os.read(archivo,size)
        if(len(imagen))!= size:
            for i in imagen:
            #envio los mensajes a cada cola
                if idq==0:#roja
                    colas[idq].put([i," ","0"," ","0"," "])
                if idq==1:#azul
                    colas[idq].put(["0"," ",i," ","0"," "])
                if idq==2:
                    colas[idq].put(["0"," ","0"," ",i," "])
                idq+=1
                if idq==3:
                    idq=0
            for idq in range(3):
                colas[idq].put("EOF") #avisa que termino de escribir en la cola 
            os.close(archivo) #cierra el fd del archivo leido
            print("Padre dejo de escribir")
            break
        else:
            for i in imagen:
                if idq==0:
                    colas[idq].put([i," ","0"," ","0"," "])
                if idq==1:
                    colas[idq].put(["0"," ",i," ","0"," "])
                if idq==2:
                    colas[idq].put(["0"," ","0"," ",i," "])
                idq+=1
                if idq==3:
                    idq=0


    #El padre los espera
    for i in range(3):
        procesos[i].join()    
    print("Padre termino exitosamente")

if __name__ == "__main__":
    main()