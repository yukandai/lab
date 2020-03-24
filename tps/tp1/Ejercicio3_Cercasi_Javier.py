class Pedido:

    def __init__(self):
        self.numero= input("Ingrese el numero de datos a colocar en el histograma:\n")
        self.lista=[]


    def chequeo(self):
        if not self.numero:
            print("No ingreso la cantidad de numeros del histograma\n")

        try:
            n=int(self.numero)
            
            if int(self.numero) < 1:
                print("Debe ingresar una cantidad mayor a 0")

            for i in range(n):
                m=int(input("\nIngreso de numeros:\n"))
                self.lista.append(m)
                print("La lista ingresada es:",self.lista)    
            return self.lista
        
        except:
            print("Disculpe, solo acepto numeros")

    def imprimir(self):

        self.chequeo()
        print("HISTOGRAMA:\n")
        for i in range(int(self.numero)):
            print(self.lista[i] * "]")

if __name__ == "__main__":
    p = Pedido()
    p.imprimir()