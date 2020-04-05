#!/bin/python3

import sys

lista = sys.stdin.read()[:-1].split(" ")

result = [item[::-1] for item in lista]

print(" ".join(result).replace("\n ", "\n"))
