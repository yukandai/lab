# 3 - realize una aplicación que a partir de un archivo csv muestre por stdout 
# las direcciones de correo de los clientes que adeuden mas de $1200, para reclamar deuda.
#  (para el archivo csv y para stdout puede usar bibliotecas de alto nivel)
# Un archivo de ejemplo es el siguiente:

import csv
print()
with open ('cuentacorriente.csv') as archivocsv:
    reader=csv.DictReader(archivocsv,delimiter=";")
    for fila in reader:
        if int(fila["Deuda"])>1200:
            print("{},{} --> {}".format(fila["Apellido"],fila["Nombre"],fila["Correo"]))
print()
