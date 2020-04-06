#!/usr/bin/python3

class Copiar():
    def __init__(self):
        self.origen = ""
        self.destino = ""
    
    def copiar_archivos(self):
        with open(self.origen, "r") as l:
            with open(self.destino, 'a') as f:
                f.write("\n")
                for i in l:
                    f.write(i)

if __name__ == "__main__":
    copiar = Copiar()
    copiar.origen = input("Ingrese archivo origen: ")
    copiar.destino = input("Ingrese archivo destino: ")
    copiar.copiar_archivos()