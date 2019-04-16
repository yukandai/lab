#!/usr/bin/python3

import sys

#leer argumentos 
#input = sys.argv

#leer desde redireccion
input = sys.stdin.readlines()

result = ""
for i in input:
    x = i.split()
    for p in x:
        result += p[::-1] + " "
print(result)
