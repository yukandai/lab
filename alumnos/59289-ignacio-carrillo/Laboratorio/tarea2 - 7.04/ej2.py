import os

leer=input("\nIngrese el nombre del archivo a leer: ")
fd3=os.open(leer,os.O_RDONLY)
escribir=input("\nIngrese el nombre del archivo a escribir: ")
fd4=os.open(escribir,os.O_WRONLY | os.O_CREAT) #si el archivo no existe, lo crea

while True:
    aux=os.read(fd3,1024)
    os.write(fd4,aux)
    print(len(aux))
    if(len(aux)!=1024):
        break
os.close(fd3)
os.close(fd4)