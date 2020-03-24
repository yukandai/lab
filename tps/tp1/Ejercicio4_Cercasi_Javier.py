class Pedido:

    def __init__(self):
        datos = open("/home/javi/Computacion_2/lab/tps/tp1/ejercicio4.txt", "r")
        self.lista = list(datos.read())

    def imprimir(self):

        print("HISTOGRAMA:\n")
        for i in range(len(self.lista)-1):
           
            print(int(self.lista[i]) * "]")
    

if __name__ == "__main__":
    p = Pedido()
    p.imprimir()