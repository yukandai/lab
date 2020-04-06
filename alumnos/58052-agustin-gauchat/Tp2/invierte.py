#!/usr/bin/python3
import sys

def voltear(palabra):
    y = palabra.split(" ")
    x = ""
    for i in y:
        if i.find('\n') != -1 and i != "\n":
            b = i.split()
            x += b[0][::-1] + "\n"
        else:
            x += i[::-1] + " "

    return x

if __name__ == "__main__":
    sys.stdout.write(voltear(sys.stdin.read()))