from io import open 

class Histograma():
    def crear_histo(self):
        caracter = "*"
        show = self.leer_datos()
        print("El histograma es:\n")
        for i in show:
            print(caracter * i)

    def leer_datos(self):
        archivo = open("datos.txt", "r")
        lista = archivo.read()
        lista=list(lista.replace(" ", ""))
        return lista

if __name__ == "__main__":
    Histograma = Histograma()
    Histograma.crear_histo()