#!/usr/bin/python3

import csv

with open('archivo.csv', newline='') as f:
    # lo convertimos en una lista
    reader = list(csv.reader(f))

    for row in reader[1:]:
        if int(row[4]) > 1200:
            print(row[1])