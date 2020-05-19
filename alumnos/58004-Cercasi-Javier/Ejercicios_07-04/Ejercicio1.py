
import sys

leido = sys.stdin.read().split("\n")
a = ''
print(leido)

for item in leido:
    a = item.split()
    print("\n")

    for b in a:
        sys.stdout.write(" " + b[::-1])
