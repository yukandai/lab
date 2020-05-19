import os

while True:
    pid = os.fork()
    if pid == 0:
        print(pid)
    else:
        break

# El programa escrito anterior, mediante una variable de iniciacion en
# estado verdadero, crea procesos en el cual un proceso padre crea un proceso
# hijo y ambos, padre e hijo, empiezan a recorrer el programa anterior. El
# hijo va a entrar en el primer "if" e imprimira el pid de su hijo
# (Igual a 0), y el proceso padre entrara en la condicion "else" restante
# por lo cual volvera a ejecutar la condicion "while", creara otro hijo ,y asi
# sucesivamente.
