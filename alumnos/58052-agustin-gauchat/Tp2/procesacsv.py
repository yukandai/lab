#!/usr/bin/python3
import sys
import csv
 
def leercsv():
    with open('/home/agus/Computacion2/lab/alumnos/58052-agustin-gauchat/Tp2/archivo.csv', newline='') as File:  
        reader = csv.reader(File)
        for row in reader:
            if row[4] != 'saldo':
                if int(row[4]) > 1200:
                    sys.stdout.write(row[1] + "\n")

if __name__ == "__main__":
    leercsv()