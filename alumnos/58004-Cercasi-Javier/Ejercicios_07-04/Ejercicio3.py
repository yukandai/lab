import sys
archivo = open("/home/javi/Computacion_2/lab/alumnos/58004-Cercasi-Javier/" +
               "Ejercicios_07-04/archivo.csv").read()

archivo = archivo.replace("\n", ",")
archivo = archivo.split(",")
deudor = []

for i in range(9, len(archivo), 5):
    if int(archivo[i]) > 1200:
        deudor.append(archivo[i-3])

print("\nLos deudores son:\n\n")
for i in range(len(deudor)):
    sys.stdout.write(deudor[i])
    print("\n")
