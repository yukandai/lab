import os
import shutil


# os.chdir("/home/javi/Computacion_2/lab/alumnos/58004-Cercasi-Javier/" +
#         "Ejercicios_07-04")

print("Usted se encuentra en:\n")
print(os.getcwd())

original = input("\n\nIngrese nombre de archivo origen: ")
origen = os.getcwd() + "/" + original

if os.path.exists(origen):

    copia = input("\nIngrese nombre de destino: ")
    destino = os.getcwd() + "/" + copia
    shutil.copy(origen, destino)
    print("\n\nEl archivo fue copiado")

else:
    print("\n\nArchivo de origen no encontrado")
