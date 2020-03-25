class Histograma():

    def __init__(self):
        self.lista = []

    def interfaz(self):
        self.cant = int(input("Ingrese cuantos datos contendra el histograma\n"))
        print("Introduzca los datos:\t")
        for i in range(self.cant):
            x = int(input())
            self.lista.append(x)
        return self.lista

    def crear_histo(self):
        caracter = "*"
        show = self.interfaz()
        print("\n")
        print("El histograma es:\n")
        for i in show:
            print(caracter * i)

if __name__ == "__main__":
    Histograma = Histograma()
    Histograma.crear_histo()