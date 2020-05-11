import sys

leido=sys.stdin.read()
print()
for renglon in leido.splitlines():
    # renglon=renglon[::-1]
    for palabra in renglon.split():
        sys.stdout.write(palabra[::-1])
        sys.stdout.write(" ")
    sys.stdout.write("\n")
    